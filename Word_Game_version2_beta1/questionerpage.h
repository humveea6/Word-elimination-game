#ifndef QUESTIONERPAGE_H
#define QUESTIONERPAGE_H

#include <QWidget>
#include<qmainwindow.h>

namespace Ui {
class Questionerpage;
}

class Questionerpage : public QWidget
{
    Q_OBJECT

public:
    explicit Questionerpage(QWidget *parent = 0);
    QMainWindow *new_win;

    ~Questionerpage();
public slots:
    void receiveShow(QString user,QString pwd,int ctnum,int level);

signals:
    void return_main(QString user,QString pwd,int ctnum,int level);

private:
    Ui::Questionerpage *ui;
};

#endif // QUESTIONERPAGE_H
