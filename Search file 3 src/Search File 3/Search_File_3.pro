#-------------------------------------------------
#
# Project created by QtCreator 2016-07-05T17:03:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Search_File_3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    globlefun.cpp \
    settingui.cpp

HEADERS  += mainwindow.h \
    globlefun.h \
    settingui.h

FORMS    += mainwindow.ui \
    settingui.ui

RESOURCES += \
    search.qrc
