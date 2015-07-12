#-------------------------------------------------
#
# Project created by QtCreator 2015-05-07T21:48:25
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyQQ_Server
TEMPLATE = app


SOURCES += main.cpp\
        myqqserver.cpp \
    login.cpp

HEADERS  += myqqserver.h \
    login.h \
    global.h

FORMS    += myqqserver.ui \
    login.ui
