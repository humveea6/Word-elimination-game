#include "about.h"
#include "ui_about.h"
#include<qpushbutton.h>
#include<qtimer.h>
About::About(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

    QPushButton *buttonback=new QPushButton("返回");//返回主页面
    buttonback->setParent(this);
    buttonback->move(300,300);
    connect(buttonback,&QPushButton::clicked,[=](){
        QTimer::singleShot(500,this,[=](){
            emit this->Aboutpageback();
            this->hide();
        });
    });

//    connect(ui->actionExit,&QAction::triggered,[=](){       //退出
//        this->close();
//    });

}

void About::receiveShow()
{
    this->show();
}

About::~About()
{
    delete ui;
}
