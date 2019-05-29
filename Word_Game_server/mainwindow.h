#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qtcpserver.h>
#include<qtcpsocket.h>
#include <QWidget>
#include<qobject.h>
#include<set>
#include<vector>
#include<player.h>
#include<questioner.h>

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
    bool checkSignUp(QString user,QString pwd,QString type1);
    bool checkSignIn(QString user,QString pwd,QString type1);
    void init();
    QTcpServer *tcpserver;
    QTcpSocket *tcpsocket;

private slots:
    void on_pushButton_clicked();
    void receiveData();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
