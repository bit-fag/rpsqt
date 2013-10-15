#include <QApplication>
#include <QTranslator>
#include <QTime>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    QApplication a(argc, argv);

    QTranslator translator;
    translator.load(":/rpsqt.qm");
    a.installTranslator(&translator);

    MainWindow w;
    w.show();
    
    return a.exec();
}
