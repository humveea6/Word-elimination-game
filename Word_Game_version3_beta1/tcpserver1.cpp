#include "tcpserver1.h"
#include "ui_tcpserver1.h"
#include<qobject.h>
#include<qtcpserver.h>
#include<qtcpsocket.h>
#include"player.h"
#include<questioner.h>
#include<qfile.h>

Tcpserver1::Tcpserver1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tcpserver1)
{
    ui->setupUi(this);

    init();

    tcpserver=new QTcpServer(this);

    tcpserver->listen(QHostAddress::Any,8888);


    connect(tcpserver,&QTcpServer::newConnection,[=](){         //连接成功
        tcpsocket=tcpserver->nextPendingConnection();
        this->show();

        connect(tcpsocket,&QTcpSocket::readyRead,this,&Tcpserver1::receiveData);
    });
}

void Tcpserver1::receiveData()                                  //接收数据
{
    QString data=tcpsocket->readAll();
    QStringList list=data.split("#");
    bool ret=0;
    if(list[0]=="a"){
        ret=checkSignUp(list[1],list[2],list[3]);
    }     //注册

    else if(list[0]=="b")  //登录
        ret=checkSignIn(list[1],list[2],list[3]);
    else if(list[0]=="P"){
        //data
        Player play;play.name=list[1],play.pwd=list[2],play.cgs=list[3].toInt();
        play.jyvalue=list[4].toInt(),play.level=list[5].toInt();
        sp.erase(sp.find(play));sp.insert(play);
    }
    else if(list[0]=="Q"){
        Questioner que;que.name=list[1],que.pwd=list[2],que.ctnum=list[3].toInt();
        que.level=list[4].toInt();
        sq.erase(sq.find(que));sq.insert(que);
        ww.clear();
        for(int i=5;i<list.size();i++){
            ww.push_back(list[i]);
        }
    }
    else {
        ww.clear();
        for(int i=0;i<list.size();i++){
            ww.push_back(list[i]);
        }
    }


    QString sendData=list[0];
    if(ret){
        sendData+="#true";
        if(list[0]=="b"){
            if(list[3]=="P"){
                Player play;play.name=list[1];
                auto a=sp.find(play);
                sendData+="#b#P#"+a->name+"#"+a->pwd+"#"+a->cgs+"#"+a->jyvalue+"#"+a->level;
            }
            else if(list[3]=="Q"){
                Questioner que;que.name=list[1];
                auto a=sq.find(que);
                sendData+="#b#Q#"+a->name+"#"+a->pwd+"#"+a->ctnum+"#"+a->level;
            }
            for(auto a:ww){
                sendData+="#"+a;
            }
        }
    }
    else{
        sendData+="#false";
        if(list[0]=="b")sendData+="#b";
        else sendData+="#a";
    }

    tcpsocket->write(sendData.toLatin1());
}

bool Tcpserver1::checkSignUp(QString user,QString pwd,QString type1)              //检查注册
{
    if(type1=="P"){
        Player temp;
        temp.name=user;temp.pwd=pwd;
        if(sp.find(temp)!=sp.end()){
            //QMessageBox::critical(NULL,"Error","User already exist!");
            return false;
        }
        else{
            sp.insert(temp);
            //QMessageBox::information(NULL,"Welcome","Register success!");
            return true;
        }
    }
    else{
        Questioner temp;
        temp.name=user;temp.pwd=pwd;
        if(sq.find(temp)!=sq.end()){
            //QMessageBox::critical(NULL,"Error","User already exist!");
            return false;
        }
        else{
            sq.insert(temp);
            //QMessageBox::information(NULL,"Welcome","Register success!");
            return true;
        }
    }
}

bool Tcpserver1::checkSignIn(QString user,QString pwd,QString type1)              //检查登录
{
    if(type1=="P"){
        Player temp;temp.name=user;temp.pwd=pwd;
        if(sp.find(temp)==sp.end()){
            //QMessageBox::warning(NULL,"Error!","No such user!");
            return false;
        }
        else{
            auto a=sp.find(temp);
            if(a->pwd==pwd){
                //QMessageBox::information(NULL,"Welcome!","Login success!");
//               //copy1(temp);//qDebug()<<current_questioner.name<<endl;
//                //emit this->playerin(temp);

//                //selectpage->show();
                return true;
            }
            else{
                //::warning(NULL,"Error","Wrong Password!");
                return false;
            }
        }
    }
    else{
        Questioner que;que.name=user;que.pwd=pwd;
        if(sq.find(que)==sq.end()){
            //QMessageBox::critical(NULL,"Error!","No such user!");
            return false;
        }
        else{
            auto a=sq.find(que);
            if(a->pwd==pwd){
                //QMessageBox::information(NULL,"Welcome!","Login success!");
//                //copy2(que);
//                //qDebug()<<current_name<<endl;
//                //emit this->questionin(temp);
//                this->hide();
//                emit showQue(a->name,a->pwd,a->ctnum,a->level);
//                //questionpage->show();
                return true;
            }
            else{
                //QMessageBox::critical(NULL,"Error","Wrong Password!");
                return false;
            }
        }
    }
}

void Tcpserver1::init()
{

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

    QFile file2("Wordlist");               //单词读入内存
    if(file2.open(QIODevice::ReadOnly)){
        Player temp;
        QDataStream in(&file2);
        while(!in.atEnd()){
            QString t;
            in>>t;
            ww.push_back(t);
        }
        file.close();
    }
}

void Tcpserver1::on_pushButton_clicked()
{
    this->close();
}


Tcpserver1::~Tcpserver1()
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

        QFile file2("Wordlist"); file2.open(QIODevice::WriteOnly);            //单词写入文件
       QDataStream out3(&file2);
       for(auto a:ww){
           out3<<a;
       }
       file.close();

    delete ui;
}
