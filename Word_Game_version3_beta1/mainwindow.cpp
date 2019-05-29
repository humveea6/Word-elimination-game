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
#include<qtcpsocket.h>
//using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init();

    tcpSocket=new QTcpSocket(this);

    connectServer();

    login();
    register1();
    open_user_data();

}

void MainWindow::login()
{

    connect(ui->pushButton,&QPushButton::clicked,[=](){             //登录


        QString user=ui->input1->text();
        //qDebug()<<user<<endl;
        QString pwd=ui->input2->text();

        if(user==""||pwd==""){
            QMessageBox::critical(this,"Error!","User name and password should not be empty!");
        }
        else{
        if(ui->typeplayer->isChecked()){
            QString bs="b";
               QString data=bs+"#"+user+"#"+pwd+"#P";
               tcpSocket->write(data.toLatin1());
        }
        else if(ui->typeque->isChecked()){
            QString bs="b";
               QString data=bs+"#"+user+"#"+pwd+"#Q";
               tcpSocket->write(data.toLatin1());
        }
        }
        ui->input1->clear();
        ui->input2->clear();
    });
}
void MainWindow::register1()
{
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){           //注册
        QString user=ui->input1->text();
        //qDebug()<<user<<endl;
        QString pwd=ui->input2->text();
        if(user.isEmpty()||pwd.isEmpty()){
            QMessageBox::warning(this,"Error!","Lineedit shouldn't be empty!");
        }
        else{
        if(ui->typeplayer->isChecked()){
            QString as="a";
               QString data=as+"#"+user+"#"+pwd+"#P";
               tcpSocket->write(data.toLatin1());
        }
        else if(ui->typeque->isChecked()){
            QString as="a";
               QString data=as+"#"+user+"#"+pwd+"#Q";
               tcpSocket->write(data.toLatin1());
        }
        ui->input1->clear();
        ui->input2->clear();
        }
    });

}


void MainWindow::connectServer()
{
    tcpSocket->abort();   //取消已有的连接
    tcpSocket->connectToHost("127.0.0.1",8888);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessages()));
}

void MainWindow::readMessages()                                     //读取服务器发送的数据
{
    QString data=tcpSocket->readAll();
    QStringList list=data.split("#");
    ui->textEdit1->setText(data);

    if(list[0]=="true"){
        ww.clear();
        if(list[1]=="a"){
            QMessageBox::information(this,"信息提示","注册成功!",QMessageBox::Ok);
        }
        else{
            QMessageBox::information(this,"信息提示","登录成功!",QMessageBox::Ok);
            if(list[2]=="P"){
                Player a;a.name=list[3],a.pwd=list[4],a.cgs=list[5].toInt(),a.jyvalue=list[6].toInt()
                        ,a.level=list[7].toInt();
                //this->hide();
                for(int i=8;i<list.size();i++){
                    ww.push_back(list[i]);
                }
                emit this->showSelect(a.name,a.pwd,a.cgs,a.jyvalue,a.level,ww);
                this->hide();
            }
            else{
                Questioner que;que.name=list[3];que.pwd=list[4];que.ctnum=list[5].toInt();que.level=list[6].toInt();
                this->hide();
                for(int i=7;i<list.size();i++){
                    ww.push_back(list[i]);
                }
                emit this->showQue(que.name,que.pwd,que.ctnum,que.level,ww);
                this->hide();
            }
        }
    }
    else if(list[0]=="false"){
        if(list[1]=="a"){
            QMessageBox::information(this,"信息提示","注册失败,用户名已经被注册!",QMessageBox::Ok);
        }
        else{
            QMessageBox::information(this,"信息提示","登录失败,用户名或密码错误!",QMessageBox::Ok);
        }
    }
    else if(list[0]=="User_data"){
        sp.clear();sq.clear();
        qDebug()<<"OK1";
        for(int i=1;i<list.size();i++){
            if(list[i]=="P"){
                Player play;play.name=list[i+1];play.pwd=list[i+2];play.cgs=list[i+3].toInt();
                play.jyvalue=list[i+4].toInt();play.level=list[i+5].toInt();
                i+=5;
                sp.insert(play);
                qDebug() << play.name << play.level;
                qDebug()<<"OK2";
            }
            else if(list[i]=="Q"){
                Questioner que;que.name=list[i+1];que.pwd=list[i+2];que.ctnum=list[i+3].toInt();
                que.level=list[i+4].toInt();
                i+=4;
                sq.insert(que);
                qDebug()<<"OK3";
            }
        }
        emit showUser(this);
    }
    else return;

}

void MainWindow::open_user_data()
{
    connect(ui->userdt,&QPushButton::clicked,[&](){             //打开用户数据页面
        QString bs="Data";
        tcpSocket->write(bs.toLatin1());

        qDebug()<<sp.size()<<' '<<sq.size();

        this->hide();
        //qDebug() << (this->sp.size()) << "YY";
        //qDebug() << (this->sq.size()) << "NOYY";
//        emit showUser(this);
//        emit this->showUser(this->sp,this->sq);
    });
}

void MainWindow::que_return_main(QString user,QString pwd,int ctnum,int level,std::set<QString>new_word)
{
    Questioner que;que.name=user;que.pwd=pwd;que.ctnum=ctnum;que.level=level;
    //sq.erase(sq.find(que));sq.insert(que);

    ww.clear();
    for(auto a:new_word)ww.push_back(a);

    QString as="Q";
    QString data=as+"#"+que.name+"#"+que.pwd+"#"+QString().setNum(que.ctnum)+"#"+QString().setNum(que.level);
    for(auto a:new_word)data+="#"+a;

    tcpSocket->write(data.toLatin1());

    this->show();
}

void MainWindow::Sel_return_main(QString user,QString pwd,int cgs,int jyvalue,int level)
{
    Player play;play.name=user;play.pwd=pwd;play.cgs=cgs;
    play.jyvalue=jyvalue;play.level=level;
    //sp.erase(sp.find(play));sp.insert(play);
    QString as="P";
    QString data=as+"#"+play.name+"#"+play.pwd+"#"+QString().setNum(play.cgs)+
            "#"+QString().setNum(play.jyvalue)+"#"+QString().setNum(play.level);
    qDebug()<<data;
    tcpSocket->write(data.toLatin1());

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

void MainWindow::init()
{
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


    ui->typeplayer->setChecked(true);
}

MainWindow::~MainWindow()
{
    QString as="W";
    for(auto a:ww){
        as+="#"+a;
    }
    tcpSocket->write(as.toLatin1());


    delete ui;
}

