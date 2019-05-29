#ifndef CMHELPER_H
#define CMHELPER_H

#include<qfile.h>
#include<qapplication.h>

class cmhelper
{
public:
    cmhelper();
    static void setStyle(const QString &style) {
            QFile qss(style);
            qss.open(QFile::ReadOnly);
            qApp->setStyleSheet(qss.readAll());
            qss.close();
    }
};

#endif // CMHELPER_H
