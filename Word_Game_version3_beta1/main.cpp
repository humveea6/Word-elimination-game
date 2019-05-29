#include "mainwindow.h"
#include <QApplication>
#include<player.h>
#include<questioner.h>
#include<qstring.h>
#include"questionerpage.h"
#include"selectoperation.h"
#include"about.h"
#include<qobject.h>
#include<play_scene.h>
#include"user_data.h"
#include"cmhelper.h"
#include"tcpserver1.h"
//Player current_player;
//Questioner current_questioner;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CMhelper::setStyle("/Users/humveea6/QT/Word_Game_version2_beta1/ysdark.qss");

    MainWindow w;                               //所有界面
    Questionerpage questionpage;
    Selectoperation selectpage;
    About aboutpage;
    Play_scene playpage;
    User_data userdatapage;
    //Tcpserver1 tcpserver1;


    QObject::connect(&w, SIGNAL(showQue(QString,QString,int,int,std::vector<QString>)),
            &questionpage, SLOT(receiveShow(QString,QString,int,int,std::vector<QString>)));

    QObject::connect(&questionpage, SIGNAL(return_main(QString,QString,int,int,std::set<QString>)),
            &w, SLOT(que_return_main(QString,QString,int,int,std::set<QString>)));

    QObject::connect(&aboutpage,SIGNAL(Aboutpageback()),&w,SLOT(about_return_main()));

    QObject::connect(&w,SIGNAL(showAbout()),&aboutpage,SLOT(receiveShow()));

    QObject::connect(&w,SIGNAL(showSelect(QString,QString,int,int,int,std::vector<QString>)),
                     &selectpage,SLOT(receive_Show(QString,QString,int,int,int,std::vector<QString>)));

    QObject::connect(&selectpage,SIGNAL(sel_return_main(QString,QString,int,int,int)),
                     &w,SLOT(Sel_return_main(QString,QString,int,int,int)));

    QObject::connect(&selectpage,SIGNAL(sel_to_game(QString,QString,int,int,int,int,std::vector<QString>)),
                     &playpage,SLOT(receive_Sel(QString,QString,int,int,int,int,std::vector<QString>)));

    QObject::connect(&playpage,SIGNAL(play_return_sel(QString,QString,int,int,int)),
                     &selectpage,SLOT(receive_Play(QString,QString,int,int,int)));

    QObject::connect(&playpage,SIGNAL(go_to_next(QString,QString,int,int,int,int,int,int)),
                     &playpage,SLOT(receive_from_last(QString,QString,int,int,int,int,int,int)));

    QObject::connect(&userdatapage,SIGNAL(user_data_to_main()),&w,SLOT(user_return_main()));

    QObject::connect(&w,&MainWindow::showUser,
                     &userdatapage,&User_data::receive_show_User);

    w.show();

    return a.exec();
}
