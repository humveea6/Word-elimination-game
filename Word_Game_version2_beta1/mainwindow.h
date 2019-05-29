#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<about.h>
#include<selectoperation.h>
#include<questionerpage.h>
#include<set>
#include "player.h"
#include "questioner.h"



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

signals:
    void showQue(QString user,QString pwd,int ctnum,int level);
    void showAbout();
    void showSelect(QString user,QString pwd,int cgs,int jyvalue,int level);
    void showUser(MainWindow *ww);
//    void showUser(std::set<Player>&,std::set<Questioner>&);

public slots:
    void que_return_main(QString user,QString pwd,int ctnum,int level);
    void about_return_main();
    void Sel_return_main(QString user,QString pwd,int cgs,int jyvalue,int level);
    void user_return_main();

private:
    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
