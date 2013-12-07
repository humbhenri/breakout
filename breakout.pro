#-------------------------------------------------
#
# Project created by QtCreator 2013-12-05T22:24:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = breakout
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paddle.cpp \
    graphicsscene.cpp

HEADERS  += mainwindow.h \
    paddle.h \
    graphicsscene.h

FORMS    += mainwindow.ui
