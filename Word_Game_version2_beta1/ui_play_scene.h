/********************************************************************************
** Form generated from reading UI file 'play_scene.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAY_SCENE_H
#define UI_PLAY_SCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Play_scene
{
public:
    QLabel *label;
    QLabel *label_2;
    QProgressBar *progressBar;
    QLabel *word;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *input;
    QPushButton *pushButton;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *start;
    QPushButton *exitsel;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *cur_jy;
    QLabel *cornum;
    QLabel *cnttopass;

    void setupUi(QWidget *Play_scene)
    {
        if (Play_scene->objectName().isEmpty())
            Play_scene->setObjectName(QStringLiteral("Play_scene"));
        Play_scene->resize(1000, 600);
        Play_scene->setMinimumSize(QSize(1000, 600));
        Play_scene->setMaximumSize(QSize(1000, 600));
        label = new QLabel(Play_scene);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 281, 41));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);
        label_2 = new QLabel(Play_scene);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 90, 381, 71));
        QFont font1;
        font1.setPointSize(25);
        label_2->setFont(font1);
        progressBar = new QProgressBar(Play_scene);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(230, 400, 461, 61));
        progressBar->setValue(24);
        word = new QLabel(Play_scene);
        word->setObjectName(QStringLiteral("word"));
        word->setGeometry(QRect(360, 180, 601, 81));
        word->setFont(font);
        widget = new QWidget(Play_scene);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(100, 240, 761, 161));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        input = new QLineEdit(widget);
        input->setObjectName(QStringLiteral("input"));

        horizontalLayout->addWidget(input);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        widget_2 = new QWidget(Play_scene);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(380, 330, 126, 44));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        start = new QPushButton(Play_scene);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(320, 160, 301, 71));
        start->setFont(font);
        exitsel = new QPushButton(Play_scene);
        exitsel->setObjectName(QStringLiteral("exitsel"));
        exitsel->setGeometry(QRect(740, 50, 171, 51));
        widget_3 = new QWidget(Play_scene);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(210, 480, 691, 71));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cur_jy = new QLabel(widget_3);
        cur_jy->setObjectName(QStringLiteral("cur_jy"));
        QFont font2;
        font2.setPointSize(20);
        cur_jy->setFont(font2);

        horizontalLayout_3->addWidget(cur_jy);

        cornum = new QLabel(widget_3);
        cornum->setObjectName(QStringLiteral("cornum"));
        cornum->setFont(font2);

        horizontalLayout_3->addWidget(cornum);

        cnttopass = new QLabel(widget_3);
        cnttopass->setObjectName(QStringLiteral("cnttopass"));
        cnttopass->setFont(font2);

        horizontalLayout_3->addWidget(cnttopass);


        retranslateUi(Play_scene);

        QMetaObject::connectSlotsByName(Play_scene);
    } // setupUi

    void retranslateUi(QWidget *Play_scene)
    {
        Play_scene->setWindowTitle(QApplication::translate("Play_scene", "Form", nullptr));
        label->setText(QApplication::translate("Play_scene", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("Play_scene", "\346\230\257\345\205\204\345\274\237\357\274\214\345\260\261\346\235\245\344\270\200\345\205\263\357\274\237", nullptr));
        word->setText(QApplication::translate("Play_scene", "TextLabel", nullptr));
        pushButton->setText(QApplication::translate("Play_scene", "\347\241\256\345\256\232", nullptr));
        start->setText(QApplication::translate("Play_scene", "\346\210\263\346\210\221\345\274\200\345\247\213", nullptr));
        exitsel->setText(QApplication::translate("Play_scene", "\350\277\224\345\233\236", nullptr));
        cur_jy->setText(QApplication::translate("Play_scene", "TextLabel", nullptr));
        cornum->setText(QApplication::translate("Play_scene", "TextLabel", nullptr));
        cnttopass->setText(QApplication::translate("Play_scene", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Play_scene: public Ui_Play_scene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAY_SCENE_H
