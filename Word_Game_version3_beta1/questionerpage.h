#ifndef QUESTIONERPAGE_H
#define QUESTIONERPAGE_H

#include <QWidget>
#include<qmainwindow.h>
#include<set>
#include<vector>
namespace Ui {
class Questionerpage;
}

class Questionerpage : public QWidget
{
    Q_OBJECT

public:
    explicit Questionerpage(QWidget *parent = 0);
    QMainWindow *new_win;
    std::set<QString>word;

    ~Questionerpage();
public slots:
    void receiveShow(QString user,QString pwd,int ctnum,int level,std::vector<QString>);

signals:
    void return_main(QString user,QString pwd,int ctnum,int level,std::set<QString>);

private:
    Ui::Questionerpage *ui;
};

#endif // QUESTIONERPAGE_H
