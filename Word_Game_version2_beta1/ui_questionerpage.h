/********************************************************************************
** Form generated from reading UI file 'questionerpage.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONERPAGE_H
#define UI_QUESTIONERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Questionerpage
{
public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *rt_to_main;
    QPushButton *pushButton;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *ct;
    QLabel *welcome;

    void setupUi(QWidget *Questionerpage)
    {
        if (Questionerpage->objectName().isEmpty())
            Questionerpage->setObjectName(QStringLiteral("Questionerpage"));
        Questionerpage->resize(1000, 600);
        Questionerpage->setMinimumSize(QSize(1000, 600));
        Questionerpage->setMaximumSize(QSize(1000, 600));
        QFont font;
        font.setPointSize(13);
        Questionerpage->setFont(font);
        label = new QLabel(Questionerpage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 40, 471, 111));
        QFont font1;
        font1.setPointSize(30);
        label->setFont(font1);
        widget = new QWidget(Questionerpage);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 520, 202, 47));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rt_to_main = new QPushButton(widget);
        rt_to_main->setObjectName(QStringLiteral("rt_to_main"));
        QFont font2;
        font2.setPointSize(12);
        rt_to_main->setFont(font2);

        horizontalLayout->addWidget(rt_to_main);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font2);

        horizontalLayout->addWidget(pushButton);

        widget_2 = new QWidget(Questionerpage);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(40, 210, 821, 101));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        ct = new QPushButton(widget_2);
        ct->setObjectName(QStringLiteral("ct"));
        QFont font3;
        font3.setPointSize(20);
        ct->setFont(font3);

        horizontalLayout_2->addWidget(ct);

        welcome = new QLabel(Questionerpage);
        welcome->setObjectName(QStringLiteral("welcome"));
        welcome->setGeometry(QRect(590, 70, 281, 51));
        welcome->setFont(font3);

        retranslateUi(Questionerpage);

        QMetaObject::connectSlotsByName(Questionerpage);
    } // setupUi

    void retranslateUi(QWidget *Questionerpage)
    {
        Questionerpage->setWindowTitle(QApplication::translate("Questionerpage", "Form", nullptr));
        label->setText(QApplication::translate("Questionerpage", "\344\270\272\346\234\254\346\270\270\346\210\217\351\242\230\345\272\223\345\242\236\345\212\240\345\206\205\345\256\271\357\274\237", nullptr));
        rt_to_main->setText(QApplication::translate("Questionerpage", "\345\233\236\345\210\260\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        pushButton->setText(QApplication::translate("Questionerpage", "\351\200\200\345\207\272", nullptr));
        ct->setText(QApplication::translate("Questionerpage", "\345\207\272\351\242\230\357\274\201", nullptr));
        welcome->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Questionerpage: public Ui_Questionerpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONERPAGE_H
