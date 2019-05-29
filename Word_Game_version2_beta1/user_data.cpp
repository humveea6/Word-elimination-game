#include "user_data.h"
#include "ui_user_data.h"
#include<qobject.h>
#include"player.h"
#include"questioner.h"
#include<set>
#include<QDebug>
#include "mainwindow.h"



User_data::User_data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User_data)
{
    ui->setupUi(this);

    ui->playerbt->setChecked(true);
    ui->levelmin->setValidator(new QIntValidator(0,10000,this));
    ui->levelmax->setValidator(new QIntValidator(0,10000,this));
    ui->cgmin->setValidator(new QIntValidator(0,10000,this));
    ui->cgmax->setValidator(new QIntValidator(0,10000,this));
    ui->jymin->setValidator(new QIntValidator(0,10000,this));
    ui->jymax->setValidator(new QIntValidator(0,10000,this));

    //ui->tableWidget->set

    exit();

    clear();

    check();

    tablesort();

}

void User_data::tablesort()                                     //排序
{
    connect(ui->tableWidget->horizontalHeader(),SIGNAL(sectionClicked(int)),
            this,SLOT(sortByColumn(int)));
}

void User_data::exit()
{
    connect(ui->exitbt,&QPushButton::clicked,[=](){
        ui->tableWidget->clear();
        this->hide();
        emit this->user_data_to_main();
    });
}

void User_data::sortByColumn(int n)                             //排序函数
{
    if(SortUporDown){
        ui->tableWidget->sortItems(n, Qt::AscendingOrder);
        SortUporDown=false;
    }
    else{
        ui->tableWidget->sortItems(n, Qt::DescendingOrder);
        SortUporDown=true;
    }
}


void User_data::clear()
{
    connect(ui->clearbt,&QPushButton::clicked,[=](){
        ui->idin->clear();
        ui->levelmin->clear();
        ui->levelmax->clear();
        ui->cgmin->clear();
        ui->cgmax->clear();
        ui->jymin->clear();
        ui->jymax->clear();
    });
}

void User_data::check()
{
    connect(ui->okbt,&QPushButton::clicked,[=](){
        QString idd=ui->idin->text();
        int levelmin=ui->levelmin->text().toInt(),levelmax=ui->levelmax->text().toInt();
        //qDebug()<<levelmin;
        int cgmin=ui->cgmin->text().toInt(),cgmax=ui->cgmax->text().toInt();
        int jymin=ui->jymin->text().toInt(),jymax=ui->jymax->text().toInt();

        if(ui->playerbt->isChecked()){                          //筛选玩家
            sp1.clear();sp2.clear();sp3.clear();sp4.clear();        //筛选ID
              //int downn,upp;
            if(!ui->idin->text().isEmpty()){
                for(auto a:playerdata){
                    if(a.name==ui->idin->text()){
                        sp1.insert(a);
                    }
                }
            }
            else sp1=playerdata;

                                                                   //筛选等级
              if(ui->levelmin->text().isEmpty())levelmin=0;
              if(ui->levelmax->text().isEmpty())levelmax=10000;
              for(auto b:sp1){
                  if(b.level>=levelmin&&b.level<=levelmax){
                      sp2.insert(b);
                  }
              }

              if(ui->cgmin->text().isEmpty())cgmin=0;               //筛选闯关数
              if(ui->cgmax->text().isEmpty())cgmax=10000;
              for(auto c:sp2){
                  if(c.cgs>=cgmin&&c.cgs<=cgmax){
                      sp3.insert(c);
                  }
              }

              if(ui->jymin->text().isEmpty())jymin=0;               //筛选经验值
              if(ui->jymax->text().isEmpty())jymax=10000;
              for(auto d:sp3){
                  if(d.jyvalue>=jymin&&d.jyvalue<=jymax){
                      sp4.insert(d);
                  }
              }

              ui->tableWidget->setColumnCount(4);
              ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"用户名"<<"等级"<<"闯关数"<<"经验值");
              ui->tableWidget->setRowCount(sp4.size());

              auto pp=sp4.begin();

              for(int i=0;i<sp4.size();i++){
                  ui->tableWidget->setItem(i,0,new QTableWidgetItem(pp->name));
                  ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(pp->level)));
                  ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(pp->cgs)));
                  ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(pp->jyvalue)));
                  pp++;
              }
        }
        else if(ui->questionerbt->isChecked()){                                     //筛选出题人
            sq1.clear();sq2.clear();sq3.clear();//sp4.clear();
              //int downn,upp;
            if(!ui->idin->text().isEmpty()){
                for(auto a:questionerdata){
                    if(a.name==ui->idin->text()){
                        sq1.insert(a);
                    }
                }
            }
            else sq1=questionerdata;
            qDebug()<<sq1.size();

                                                                   //筛选等级
              if(ui->levelmin->text().isEmpty())levelmin=0;
              if(ui->levelmax->text().isEmpty())levelmax=10000;
              for(auto b:sq1){
                  qDebug()<<b.level;
                  if(b.level>=levelmin&&b.level<=levelmax){
                      sq2.insert(b);
                  }
              }
              qDebug()<<sq2.size();

              if(ui->cgmin->text().isEmpty())cgmin=0;               //筛选出题数
              if(ui->cgmax->text().isEmpty())cgmax=10000;
              for(auto c:sq2){
                  if(c.ctnum>=cgmin&&c.ctnum<=cgmax){
                      sq3.insert(c);
                  }
              }
              qDebug()<<sq3.size();

//              if(ui->jymin->text().isEmpty())jymin=0;               //筛选经验值
//              if(ui->jymax->text().isEmpty())jymax=10000;
//              for(auto d:sp3){
//                  if(d.jyvalue>=jymin&&d.jyvalue<=jymax){
//                      sp4.insert(d);
//                  }
//              }

              ui->tableWidget->setColumnCount(3);
              ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"用户名"<<"等级"<<"出题数");
              ui->tableWidget->setRowCount(sq3.size());

              auto pp=sq3.begin();

              for(int i=0;i<sq3.size();i++){
                  ui->tableWidget->setItem(i,0,new QTableWidgetItem(pp->name));
                  ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(pp->level)));
                  ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(pp->ctnum)));
                  //ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(pp->jyvalue)));
                  pp++;
              }
        }
    });
}

//void User_data::receive_show_User(std::set<Player>&pl,std::set<Questioner>&que)
void User_data::receive_show_User(MainWindow *ww)
{
    qDebug() << (ww->sp.size());
    qDebug() << (ww->sq.size());
    playerdata=ww->sp;
    questionerdata=ww->sq;
    for (auto i : playerdata) {
        qDebug() << "SDYY" << i.name << i.level << i.cgs << i.jyvalue;
    }

    this->show();
}

User_data::~User_data()
{
    delete ui;
}
