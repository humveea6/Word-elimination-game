#include "questionerpage.h"
#include "ui_questionerpage.h"
#include<qstring.h>
#include<questioner.h>
#include<mainwindow.h>
#include<qdebug.h>
#include"publicdata.h"
#include<set>
#include<qfile.h>
#include<qmessagebox.h>
//extern Questioner current_questioner;

 Questioner current_Questioner;
 std::set<QString>word;

Questionerpage::Questionerpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Questionerpage)
{
    ui->setupUi(this);


    //connect(mainwindow,)
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->close();
    });


    connect(ui->ct,&QPushButton::clicked,[=](){     //获取单词
        QString t=ui->lineEdit->text();
        if(word.find(t)!=word.end()){
            QMessageBox::warning(this,"Error","Word already exist!");
        }
        else{
            word.insert(t);
            current_Questioner.ctnum++;current_Questioner.level=current_Questioner.ctnum/5+1;
            QMessageBox::information(this,"Success","You have successfully add one word to the database!");
            ui->lineEdit->clear();
            qDebug()<<"level"<<current_Questioner.level;
        }
    });

    //new_win=new MainWindow;

    connect(ui->rt_to_main,&QPushButton::clicked,[=](){         //回到登录界面
         QFile file("Wordlist"); file.open(QIODevice::WriteOnly);
        QDataStream out(&file);
        for(auto a:word){
            out<<a;
        }
        file.close();
        this->hide();
        emit this->return_main(current_Questioner.name,current_Questioner.pwd,current_Questioner.ctnum,current_Questioner.level);
        //w->show();
    });

}

Questionerpage::~Questionerpage()
{
    delete ui;
}

void Questionerpage::receiveShow(QString user,QString pwd,int ctnum,int level)
{
    this->show();
    QString s="欢迎您，Questioner: ";
    s+=user;
    //qDebug() << "!!!" << s;

    ui->welcome->setText(s);
    current_Questioner.name=user;current_Questioner.pwd=pwd;
    current_Questioner.ctnum=ctnum;current_Questioner.level=level;
    qDebug()<<"level"<<current_Questioner.level;

    QFile file("Wordlist");               //单词读入内存
    if(file.open(QIODevice::ReadOnly)){
        Player temp;
        QDataStream in(&file);word.clear();
        while(!in.atEnd()){
            QString t;
            in>>t;
            word.insert(t);
        }
        file.close();
    }
}
