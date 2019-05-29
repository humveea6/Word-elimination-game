#ifndef USER_DATA_H
#define USER_DATA_H

#include <QWidget>
#include<set>
#include"player.h"
#include"questioner.h"
#include "mainwindow.h"
namespace Ui {
class User_data;
}

class User_data : public QWidget
{
    Q_OBJECT

public:
    std::set<Player>playerdata,sp1,sp2,sp3,sp4;
    std::set<Questioner>questionerdata,sq1,sq2,sq3,sq4;
    bool SortUporDown;
    explicit User_data(QWidget *parent = 0);
    void clear();
    void check();
    void exit();
    void tablesort();

    ~User_data();

signals:
    void user_data_to_main();

public slots:
//    void receive_show_User(std::set<Player>&,std::set<Questioner>&);
    void receive_show_User(MainWindow *ww);
    void sortByColumn(int n);

private:
    Ui::User_data *ui;
};

#endif // USER_DATA_H
