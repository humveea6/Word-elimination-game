#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<about.h>
#include<selectoperation.h>
#include<questionerpage.h>
#include<set>
#include "player.h"
#include "questioner.h"
#include<vector>
#include<qtcpsocket.h>


namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    std::set<Player>sp;
    std::set<Questioner>sq;
    std::vector<QString>ww;

signals:
    void showQue(QString user,QString pwd,int ctnum,int level,std::vector<QString>);
    void showAbout();
    void showSelect(QString user,QString pwd,int cgs,int jyvalue,int level,std::vector<QString>);
    void showUser(MainWindow *ww);

//    void showUser(std::set<Player>&,std::set<Questioner>&);

public slots:
    void que_return_main(QString user,QString pwd,int ctnum,int level,std::set<QString>);
    void about_return_main();
    void Sel_return_main(QString user,QString pwd,int cgs,int jyvalue,int level);
    void user_return_main();
    void readMessages();

private:
    Ui::MainWindow *ui;
    QTcpSocket *tcpSocket;
    void connectServer();
    void init();
    void login();
    void register1();
    void open_user_data();

};

#endif // MAINWINDOW_H
