/********************************************************************************
** Form generated from reading UI file 'selectoperation.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTOPERATION_H
#define UI_SELECTOPERATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Selectoperation
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *returnmain;
    QPushButton *btexit;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Selectoperation)
    {
        if (Selectoperation->objectName().isEmpty())
            Selectoperation->setObjectName(QStringLiteral("Selectoperation"));
        Selectoperation->resize(1000, 600);
        Selectoperation->setMinimumSize(QSize(1000, 600));
        Selectoperation->setMaximumSize(QSize(1000, 600));
        centralwidget = new QWidget(Selectoperation);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 351, 41));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 141, 31));
        QFont font1;
        font1.setPointSize(20);
        label_2->setFont(font1);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 490, 231, 47));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        returnmain = new QPushButton(widget);
        returnmain->setObjectName(QStringLiteral("returnmain"));

        horizontalLayout->addWidget(returnmain);

        btexit = new QPushButton(widget);
        btexit->setObjectName(QStringLiteral("btexit"));

        horizontalLayout->addWidget(btexit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        Selectoperation->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Selectoperation);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 22));
        Selectoperation->setMenuBar(menubar);
        statusbar = new QStatusBar(Selectoperation);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Selectoperation->setStatusBar(statusbar);

        retranslateUi(Selectoperation);

        QMetaObject::connectSlotsByName(Selectoperation);
    } // setupUi

    void retranslateUi(QMainWindow *Selectoperation)
    {
        Selectoperation->setWindowTitle(QApplication::translate("Selectoperation", "MainWindow", nullptr));
        label->setText(QApplication::translate("Selectoperation", "\351\200\211\346\213\251\344\270\200\344\270\252\346\202\250\345\226\234\346\254\242\347\232\204\351\232\276\345\272\246\357\274\237", nullptr));
        label_2->setText(QString());
        returnmain->setText(QApplication::translate("Selectoperation", "\350\277\224\345\233\236\344\270\273\351\241\265\351\235\242", nullptr));
        btexit->setText(QApplication::translate("Selectoperation", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Selectoperation: public Ui_Selectoperation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTOPERATION_H
