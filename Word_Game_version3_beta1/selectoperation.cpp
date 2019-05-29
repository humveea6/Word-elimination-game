#include "selectoperation.h"
#include "ui_selectoperation.h"
#include<qobject.h>
#include"player.h"
#include<qpushbutton.h>
#include<qlabel.h>
#include<qdebug.h>

Player current_Player;


Selectoperation::Selectoperation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Selectoperation)
{
    ui->setupUi(this);

    for(int i=0;i<20;i++){
        QPushButton *newbutton=new QPushButton;                 //设置选择按钮
        newbutton->setParent(this);
        newbutton->move(350+(i%4)*120,70+(i/4)*100);
        newbutton->setFixedSize(100,70);
        newbutton->setText(QString::number(i+1));


        newbutton->setEnabled(true);
        newbutton->setCheckable(true);
        connect(newbutton,&QPushButton::clicked, [=](){
            this->hide();
            emit this->sel_to_game(current_Player.name,current_Player.pwd,current_Player.cgs,
                                   current_Player.jyvalue,current_Player.level,i+1,word);
        });
    }

    connect(ui->btexit,&QPushButton::clicked,[=](){
        this->close();
    });

    connect(ui->returnmain,&QPushButton::clicked,[=](){
        this->hide();
        emit this->sel_return_main(current_Player.name,current_Player.pwd,current_Player.cgs,
                                   current_Player.jyvalue,current_Player.level);
    });

}

Selectoperation::~Selectoperation()
{
    delete ui;
}

void Selectoperation::receive_Show(QString user, QString pwd, int cgs, int jyvalue,
                                   int level,std::vector<QString>ww)      //信号槽
{
    current_Player.name=user;current_Player.pwd=pwd;current_Player.cgs=cgs;
    current_Player.jyvalue=jyvalue;current_Player.level=level;
    word=ww;
    //qDebug()<<user<<endl;

    QString s="欢迎您，玩家"; s+=user;

    ui->label_2->setText(s);
    this->show();
}

void Selectoperation::receive_Play(QString user,QString pwd,int cgs,int jyvalue,int level)
{
    current_Player.name=user;current_Player.pwd=pwd;current_Player.cgs=cgs;
    current_Player.jyvalue=jyvalue;current_Player.level=level;

    QString s="欢迎您，玩家"; s+=user;

    ui->label_2->setText(s);
    this->show();
}
