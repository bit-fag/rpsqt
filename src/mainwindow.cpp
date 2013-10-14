#include <QtGui>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_copyMyHashButton_clicked()
{
    QApplication::clipboard()->setText(ui->myHashLineEdit->text());
}

void MainWindow::on_copyMyCleartextButton_clicked()
{
    QApplication::clipboard()->setText(ui->myCleartextLineEdit->text());
}
