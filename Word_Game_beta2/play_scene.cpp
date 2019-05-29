#include "play_scene.h"
#include "ui_play_scene.h"
#include<qobject.h>
#include"player.h"
#include<vector>
#include<QTime>
#include<qfile.h>
#include<qmessagebox.h>
#include<qtimer.h>
#include <QDebug>

Player current_player;
int hardd,temp;
QString wordd;

std::vector<QString>ww;

Play_scene::Play_scene(QWidget *parent) :                       //主场景
    QWidget(parent),
    ui(new Ui::Play_scene)
{
    ui->setupUi(this);
    ui->progressBar->setInvertedAppearance(true);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));


    connect(ui->start,&QPushButton::clicked,[=](){              //开始按钮

        if(ww.empty()){
            emit this->play_return_sel(current_player.name,current_player.pwd,current_player.cgs,
                                       current_player.jyvalue,current_player.level);
            this->hide();
        }
        else{
        ui->word->show();
        ui->input->show();
        ui->progressBar->show();
        ui->pushButton->show();
        ui->start->hide();


//        ui->progressBar->setRange(0,8000);
//        ui->progressBar->setValue(0);

        wordd=ww[qrand()%ww.size()];
        ui->word->setText(wordd);
        }
    });

    temp = 100;


    qtimer = new QTimer;                        //计时器

    qtimer->connect(qtimer, &QTimer::timeout, this, &Play_scene::time_out1);            //超时
    ui->start->connect(ui->start,&QPushButton::clicked,this,&Play_scene::click_button1);   //计时器启动



    connect(ui->exitsel,&QPushButton::clicked,[=](){                    //退出
        emit this->play_return_sel(current_player.name,current_player.pwd,current_player.cgs,
                                   current_player.jyvalue,current_player.level);
        this->hide();
    });

    connect(ui->pushButton,&QPushButton::clicked,[=](){                 //答案提交
        QString inn=ui->input->text();ui->input->clear();
        if(inn==wordd){
//            QMessageBox::StandardButton rb=QMessageBox::information(this,"Congratuation!",
//                           "You have successfully passed this round,continue for the next?");

            current_player.cgs++;current_player.jyvalue+=inn.length();
            current_player.level=current_player.jyvalue/10;
            if(hardd==20){                                          //通关判断
                QMessageBox::information(this,"Congratuation!","You have passed all rounds!");
                emit this->play_return_sel(current_player.name,current_player.pwd,current_player.cgs,
                                           current_player.jyvalue,current_player.level);
                this->hide();
            }
            else{
            QMessageBox msgBox;
            msgBox.setText("Congratuation!");                       //下一步选择
            msgBox.setInformativeText("You have successfully passed this round,continue for the next?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No );
            msgBox.setDefaultButton(QMessageBox::Yes);
            int ret = msgBox.exec();
            if(ret==QMessageBox::Yes){
                this->hide();
                emit this->go_to_next(current_player.name,current_player.pwd,current_player.cgs,
                                      current_player.jyvalue,current_player.level,hardd+1);
                }
            else{
                emit this->play_return_sel(current_player.name,current_player.pwd,current_player.cgs,
                                           current_player.jyvalue,current_player.level);
                this->hide();
            }
            }
//            else{
//                emit this->play_return_sel(current_player.name,current_player.pwd,current_player.cgs,
//                                           current_player.jyvalue,current_player.level);
//                this->hide();
//            }
        }
        else{                                                       //答案错误
            QMessageBox::critical(this,"Wrong answer!","Wrong answer!");
            this->hide();
            emit this->go_to_next(current_player.name,current_player.pwd,current_player.cgs,
                                  current_player.jyvalue,current_player.level,hardd);
        }
    });
}

void Play_scene::time_out1()
{
    //qDebug() << "HEHE";
    temp-=hardd;
    ui->progressBar->setValue((temp<0?0:temp));
    if(temp < 0){
        qtimer->stop();
         //QMessageBox::warning(this,"Failed!","You have failed to finish this round!");
        ui->word->hide();
        temp = 100;
    }
}

void Play_scene::click_button1()
{
    //qDebug() << "HEHEDA";

    if(qtimer->isActive()){
        qtimer->stop();
    }
    else{
        qtimer->start(100);
    }
}


void Play_scene::receive_Sel(QString user,QString pwd,int cgs,int jyvalue,int level,int hard)//返回选关
{
    current_player.name=user;current_player.pwd=pwd;current_player.cgs=cgs;
    current_player.jyvalue=jyvalue;current_player.level=level;
    hardd=hard;

    QString s="欢迎来到关卡：";s+=QString::number(hard);
    ui->label->setText(s);

    ui->word->hide();
    ui->input->hide();
    ui->progressBar->hide();
    ui->pushButton->hide();
    ui->start->show();

    QFile file("Wordlist");               //单词读入内存
    if(file.open(QIODevice::ReadOnly)){
        Player temp;
        QDataStream in(&file);ww.clear();
        while(!in.atEnd()){
            QString t;
            in>>t;
            ww.push_back(t);
        }
        file.close();
    }

    if(ww.empty()){
        QMessageBox::warning(this,"Error","Please add word first!");
        emit this->play_return_sel(current_player.name,current_player.pwd,current_player.cgs,
                                   current_player.jyvalue,current_player.level);
        this->hide();
    }


    this->show();
}

void Play_scene::receive_from_last(QString user,QString pwd,int cgs,int jyvalue,int level,int hard)//前往下一关
{
    current_player.name=user;current_player.pwd=pwd;current_player.cgs=cgs;
    current_player.jyvalue=jyvalue;current_player.level=level;
    hardd=hard;

    QString s="欢迎来到关卡：";s+=QString::number(hard);
    ui->label->setText(s);

    ui->word->hide();
    ui->input->hide();
    ui->progressBar->hide();
    ui->pushButton->hide();
    ui->start->show();

    QFile file("Wordlist");               //单词读入内存
    if(file.open(QIODevice::ReadOnly)){
        Player temp;
        QDataStream in(&file);ww.clear();
        for(int i=1;i<=20;i++)ww.push_back(getRandomString(qrand()%10+1));
        while(!in.atEnd()){
            QString t;
            in>>t;
            ww.push_back(t);
        }
        file.close();
    }

    if(ww.empty()){
        QMessageBox::warning(this,"Error","Please add word first!");
        emit this->play_return_sel(current_player.name,current_player.pwd,current_player.cgs,
                                   current_player.jyvalue,current_player.level);
        this->hide();
    }
    else this->show();
}

QString Play_scene::getRandomString(int length)
{
    qsrand(QDateTime::currentMSecsSinceEpoch());//为随机值设定一个seed

    const char chrs[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int chrs_size = sizeof(chrs);

    char* ch = new char[length + 1];
    memset(ch, 0, length + 1);
    int randomx = 0;
    for (int i = 0; i < length; ++i)
    {
        randomx= rand() % (chrs_size - 1);
        ch[i] = chrs[randomx];
    }

    QString ret(ch);
    delete[] ch;
    return ret;
}

Play_scene::~Play_scene()
{
    delete ui;
}
