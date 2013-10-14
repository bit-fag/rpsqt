#include <QApplication>
#include <QTime>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
