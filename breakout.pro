#-------------------------------------------------
#
# Project created by QtCreator 2013-12-05T22:24:15
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = breakout
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paddle.cpp \
    graphicsscene.cpp \
    ball.cpp \
    block.cpp \
    sound.cpp

HEADERS  += mainwindow.h \
    paddle.h \
    graphicsscene.h \
    ball.h \
    block.h \
    sound.h

FORMS    += mainwindow.ui

RESOURCES +=
