#ifndef TCPSERVER1_H
#define TCPSERVER1_H

#include<qtcpserver.h>
#include<qtcpsocket.h>
#include <QWidget>
#include<qobject.h>
#include<set>
#include<vector>
#include<player.h>
#include<questioner.h>
namespace Ui {
class Tcpserver1;
}

class Tcpserver1 : public QWidget
{
    Q_OBJECT

public:
    explicit Tcpserver1(QWidget *parent = 0);
    ~Tcpserver1();
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
    Ui::Tcpserver1 *ui;

};

#endif // TCPSERVER1_H
