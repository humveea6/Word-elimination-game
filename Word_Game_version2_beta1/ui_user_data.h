/********************************************************************************
** Form generated from reading UI file 'user_data.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_DATA_H
#define UI_USER_DATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_User_data
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *playerbt;
    QRadioButton *questionerbt;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *exitbt;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *idin;
    QLabel *label_2;
    QLineEdit *levelmin;
    QLineEdit *levelmax;
    QLabel *label_3;
    QLineEdit *cgmin;
    QLineEdit *cgmax;
    QLabel *label_4;
    QLineEdit *jymin;
    QLineEdit *jymax;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *clearbt;
    QPushButton *okbt;
    QTableWidget *tableWidget;

    void setupUi(QWidget *User_data)
    {
        if (User_data->objectName().isEmpty())
            User_data->setObjectName(QStringLiteral("User_data"));
        User_data->resize(1000, 800);
        User_data->setMinimumSize(QSize(1000, 800));
        User_data->setMaximumSize(QSize(1000, 800));
        widget = new QWidget(User_data);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(80, 30, 234, 38));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        playerbt = new QRadioButton(widget);
        playerbt->setObjectName(QStringLiteral("playerbt"));

        horizontalLayout->addWidget(playerbt);

        questionerbt = new QRadioButton(widget);
        questionerbt->setObjectName(QStringLiteral("questionerbt"));

        horizontalLayout->addWidget(questionerbt);

        widget_2 = new QWidget(User_data);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(20, 60, 358, 44));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        exitbt = new QPushButton(User_data);
        exitbt->setObjectName(QStringLiteral("exitbt"));
        exitbt->setGeometry(QRect(280, 570, 114, 32));
        widget_3 = new QWidget(User_data);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(10, 70, 441, 221));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        idin = new QLineEdit(widget_3);
        idin->setObjectName(QStringLiteral("idin"));

        gridLayout->addWidget(idin, 1, 1, 1, 1);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        levelmin = new QLineEdit(widget_3);
        levelmin->setObjectName(QStringLiteral("levelmin"));

        gridLayout->addWidget(levelmin, 2, 1, 1, 1);

        levelmax = new QLineEdit(widget_3);
        levelmax->setObjectName(QStringLiteral("levelmax"));

        gridLayout->addWidget(levelmax, 2, 2, 1, 1);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        cgmin = new QLineEdit(widget_3);
        cgmin->setObjectName(QStringLiteral("cgmin"));

        gridLayout->addWidget(cgmin, 3, 1, 1, 1);

        cgmax = new QLineEdit(widget_3);
        cgmax->setObjectName(QStringLiteral("cgmax"));

        gridLayout->addWidget(cgmax, 3, 2, 1, 1);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        jymin = new QLineEdit(widget_3);
        jymin->setObjectName(QStringLiteral("jymin"));

        gridLayout->addWidget(jymin, 4, 1, 1, 1);

        jymax = new QLineEdit(widget_3);
        jymax->setObjectName(QStringLiteral("jymax"));

        gridLayout->addWidget(jymax, 4, 2, 1, 1);

        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 1, 1, 1);

        label_7 = new QLabel(widget_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        clearbt = new QPushButton(widget_3);
        clearbt->setObjectName(QStringLiteral("clearbt"));

        gridLayout->addWidget(clearbt, 5, 1, 1, 1);

        okbt = new QPushButton(widget_3);
        okbt->setObjectName(QStringLiteral("okbt"));

        gridLayout->addWidget(okbt, 5, 2, 1, 1);

        tableWidget = new QTableWidget(User_data);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(470, 30, 501, 511));
        QFont font;
        font.setPointSize(20);
        tableWidget->setFont(font);

        retranslateUi(User_data);

        QMetaObject::connectSlotsByName(User_data);
    } // setupUi

    void retranslateUi(QWidget *User_data)
    {
        User_data->setWindowTitle(QApplication::translate("User_data", "Form", nullptr));
        playerbt->setText(QApplication::translate("User_data", "\351\227\257\345\205\263\350\200\205", nullptr));
        questionerbt->setText(QApplication::translate("User_data", "\345\207\272\351\242\230\350\200\205", nullptr));
        exitbt->setText(QApplication::translate("User_data", "\350\277\224\345\233\236", nullptr));
        label->setText(QApplication::translate("User_data", "ID", nullptr));
        label_2->setText(QApplication::translate("User_data", "\347\255\211\347\272\247", nullptr));
        label_3->setText(QApplication::translate("User_data", "\345\267\262\351\227\257\345\205\263\346\225\260/\345\267\262\345\207\272\351\242\230\346\225\260", nullptr));
        label_4->setText(QApplication::translate("User_data", "\347\273\217\351\252\214\345\200\274", nullptr));
        label_5->setText(QApplication::translate("User_data", "\345\261\236\346\200\247", nullptr));
        label_6->setText(QApplication::translate("User_data", "\344\270\213\351\231\220", nullptr));
        label_7->setText(QApplication::translate("User_data", "\344\270\212\351\231\220", nullptr));
        clearbt->setText(QApplication::translate("User_data", "\346\270\205\347\251\272", nullptr));
        okbt->setText(QApplication::translate("User_data", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User_data: public Ui_User_data {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_DATA_H
