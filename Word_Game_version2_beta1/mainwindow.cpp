#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<about.h>
#include<selectoperation.h>
#include<qmessagebox.h>
#include<qstring.h>
#include<qdebug.h>
#include<qfile.h>
#include<player.h>
#include<questioner.h>
#include<set>
#include "publicdata.h"
#include "questionerpage.h"
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QFile file("Playerlist");               //账号信息读入内存
    if(file.open(QIODevice::ReadOnly)){
        Player temp;
        QDataStream in(&file);
        while(!in.atEnd()){
            in>>temp.name>>temp.pwd>>temp.cgs>>temp.jyvalue>>temp.level;
            sp.insert(temp);
        }
        file.close();
    }

    QFile file1("Questionerlist");               //账号信息读入内存
    if(file1.open(QIODevice::ReadOnly)){
        Questioner temp;
        QDataStream in(&file1);
        //bool isok=false;
        while(!in.atEnd()){
            in>>temp.name>>temp.pwd>>temp.ctnum>>temp.level;
            sq.insert(temp);
        }
        file1.close();
    }




    connect(ui->actionExit,&QAction::triggered,[=](){       //退出
        this->close();
    });


    connect(ui->actionAbout,&QAction::triggered,[=](){      //打开关于界面
        this->hide();
        //aboutpage->show();
        emit this->showAbout();
    });

    connect(ui->exitbt,&QPushButton::clicked,[=](){             //退出
        this->close();
    });

    connect(ui->userdt,&QPushButton::clicked,[&](){             //打开用户数据页面
        this->hide();
        qDebug() << (this->sp.size()) << "YY";
        qDebug() << (this->sq.size()) << "NOYY";
        emit showUser(this);
//        emit this->showUser(this->sp,this->sq);
    });

//    connect(aboutpage,&About::Aboutpageback,[=](){      //从关于界面返回
//        aboutpage->hide();
//        this->show();
//    });




    ui->typeplayer->setChecked(true);


    connect(ui->pushButton,&QPushButton::clicked,[=](){             //登录


        QString user=ui->input1->text();
        //qDebug()<<user<<endl;
        QString pwd=ui->input2->text();

        if(user==""||pwd==""){
            QMessageBox::critical(this,"Error!","User name and password should not be empty!");
        }
        else{
        if(ui->typeplayer->isChecked()){
            Player temp;temp.name=user;temp.pwd=pwd;
            if(sp.find(temp)==sp.end()){
                QMessageBox::warning(this,"Error!","No such user!");
            }
            else{
                auto a=sp.find(temp);
                if(a->pwd==pwd){
                    QMessageBox::information(this,"Welcome!","Login success!");
                   //copy1(temp);//qDebug()<<current_questioner.name<<endl;
                    //emit this->playerin(temp);
                    this->hide();
                    emit this->showSelect(a->name,a->pwd,a->cgs,a->jyvalue,a->level);
                    //selectpage->show();
                }
                else{
                    QMessageBox::warning(this,"Error","Wrong Password!");
                }
            }
        }
        else if(ui->typeque->isChecked()){
            Questioner que;que.name=user;que.pwd=pwd;
            if(sq.find(que)==sq.end()){
                QMessageBox::critical(this,"Error!","No such user!");
            }
            else{
                auto a=sq.find(que);
                if(a->pwd==pwd){
                    QMessageBox::information(this,"Welcome!","Login success!");
                    //copy2(que);
                    //qDebug()<<current_name<<endl;
                    //emit this->questionin(temp);
                    this->hide();
                    emit showQue(a->name,a->pwd,a->ctnum,a->level);
                    //questionpage->show();
                }
                else{
                    QMessageBox::critical(this,"Error","Wrong Password!");
                }
            }
        }
        }
        ui->input1->clear();
        ui->input2->clear();
    });

    connect(ui->pushButton_2,&QPushButton::clicked,[=](){           //注册
        QString user=ui->input1->text();
        //qDebug()<<user<<endl;
        QString pwd=ui->input2->text();
        if(user.isEmpty()||pwd.isEmpty()){
            QMessageBox::warning(this,"Error!","Lineedit shouldn't be empty!");
        }
        else{
        if(ui->typeplayer->isChecked()){
            Player temp;
            temp.name=user;temp.pwd=pwd;
            if(sp.find(temp)!=sp.end()){
                QMessageBox::critical(this,"Error","User already exist!");
            }
            else{
                sp.insert(temp);
                QMessageBox::information(this,"Welcome","Register success!");
            }
        }
        else if(ui->typeque->isChecked()){
            Questioner temp;
            temp.name=user;temp.pwd=pwd;
            if(sq.find(temp)!=sq.end()){
                QMessageBox::critical(this,"Error","User already exist!");
            }
            else{
                sq.insert(temp);
                QMessageBox::information(this,"Welcome","Register success!");
            }
        }
        ui->input1->clear();
        ui->input2->clear();
        }
    });

}

void MainWindow::que_return_main(QString user,QString pwd,int ctnum,int level)
{
    Questioner que;que.name=user;que.pwd=pwd;que.ctnum=ctnum;que.level=level;
    sq.erase(sq.find(que));sq.insert(que);
    this->show();
}

void MainWindow::Sel_return_main(QString user,QString pwd,int cgs,int jyvalue,int level)
{
    Player play;play.name=user;play.pwd=pwd;play.cgs=cgs;
    play.jyvalue=jyvalue;play.level=level;
    sp.erase(sp.find(play));sp.insert(play);
    this->show();
}

void MainWindow::about_return_main()
{
    this->show();
}

void MainWindow::user_return_main()
{
    this->show();
}

MainWindow::~MainWindow()
{
        QFile file("Playerlist");
        if(!file.open(QFile::WriteOnly | QIODevice::Truncate))
        {
            qDebug() << "Can't open file for writing";
            //return 0;
        }
        QDataStream out(&file);
       // out.setVersion(QDataStream::Qt_5_7);
        for(auto a:sp){
            Player temp=a;
            out<<temp.name<<temp.pwd<<temp.cgs<<temp.jyvalue<<temp.level;
        }
        file.close();

       QFile file1("Questionerlist");
            if(!file1.open(QFile::WriteOnly | QIODevice::Truncate))
            {
                qDebug() << "Can't open file for writing";
                //return 0;
            }
            QDataStream out1(&file1);
           // out.setVersion(QDataStream::Qt_5_7);
            for(auto a:sq){
                Questioner temp=a;
                out1<<temp.name<<temp.pwd<<temp.ctnum<<temp.level;
            }
            file1.close();


    delete ui;
}

