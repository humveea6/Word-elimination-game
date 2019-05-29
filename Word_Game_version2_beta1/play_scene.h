#ifndef PLAY_SCENE_H
#define PLAY_SCENE_H

#include <QWidget>

namespace Ui {
class Play_scene;
}

class Play_scene : public QWidget
{
    Q_OBJECT

public:
    explicit Play_scene(QWidget *parent = 0);
    QString rand_word();
    void ckans();
    ~Play_scene();
    QTimer *qtimer;
    QString getRandomString(int length);


public slots:
    void receive_Sel(QString user,QString pwd,int cgs,int jyvalue,int level,int hard);
    void time_out1();
    void click_button1();
    void receive_from_last(QString user,QString pwd,int cgs,int jyvalue,int level,int hard,int cnt,int corr);

signals:
    void play_return_sel(QString user,QString pwd,int cgs,int jyvalue,int level);
    void go_to_next(QString user,QString pwd,int cgs,int jyvalue,int level,int hard,int cnt,int corr);

private:
    Ui::Play_scene *ui;
};

#endif // PLAY_SCENE_H
