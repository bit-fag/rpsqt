#-------------------------------------------------
#
# Project created by QtCreator 2013-10-14T19:20:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rpsqt
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp

HEADERS  += src/mainwindow.h

FORMS    += ui/mainwindow.ui

TRANSLATIONS += locale/rpsqt_ru.ts

RESOURCES += \
    resources.qrc

win32 {
    RC_FILE = resource.rc
}
