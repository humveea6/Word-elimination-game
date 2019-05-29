#ifndef SELECTOPERATION_H
#define SELECTOPERATION_H
#include<qobject.h>
#include <QMainWindow>
#include<vector>
namespace Ui {
class Selectoperation;
}

class Selectoperation : public QMainWindow
{
    Q_OBJECT

public:
    explicit Selectoperation(QWidget *parent = 0);
    ~Selectoperation();
    std::vector<QString>word;

public slots:
    void receive_Show(QString user,QString pwd,int cgs,int jyvalue,int level,std::vector<QString>);
    void receive_Play(QString user,QString pwd,int cgs,int jyvalue,int level);

signals:
    void sel_return_main(QString user,QString pwd,int cgs,int jyvalue,int level);
    void sel_to_game(QString user,QString pwd,int cgs,int jyvalue,int level,int hard,std::vector<QString>);

private:
    Ui::Selectoperation *ui;
};

#endif // SELECTOPERATION_H
