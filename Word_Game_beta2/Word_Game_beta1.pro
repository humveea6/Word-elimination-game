#-------------------------------------------------
#
# Project created by QtCreator 2019-05-25T15:07:58
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Word_Game_beta1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    selectoperation.cpp \
    about.cpp \
    player.cpp \
    questioner.cpp \
    questionerpage.cpp \
    publicdata.cpp \
    play_scene.cpp \
    user_data.cpp \
    user.cpp \
    cmhelper.cpp \
    rss.cpp

HEADERS += \
        mainwindow.h \
    selectoperation.h \
    about.h \
    player.h \
    questioner.h \
    questionerpage.h \
    publicdata.h \
    play_scene.h \
    user_data.h \
    user.h \
    cmhelper.h

FORMS += \
        mainwindow.ui \
    selectoperation.ui \
    about.ui \
    questionerpage.ui \
    play_scene.ui \
    user_data.ui

RESOURCES += \
    rsss.qrc
