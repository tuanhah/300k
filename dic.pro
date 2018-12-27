#-------------------------------------------------
#
# Project created by QtCreator 2018-12-19T21:37:24
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dic
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connection.cpp

HEADERS  += mainwindow.h \
    connection.h

FORMS    += mainwindow.ui
