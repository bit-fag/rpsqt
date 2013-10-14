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

void MainWindow::on_randomPushButton_clicked()
{
    int random = qrand() % 3;
    if (random == ROCK) {
        ui->rockRadioButton->click();
    } else if (random == PAPER) {
        ui->paperRadioButton->click();
    } else if (random == SCISSORS) {
        ui->scissorsRadioButton->click();
    }
}

void MainWindow::on_rockRadioButton_clicked()
{
}

void MainWindow::on_paperRadioButton_clicked()
{
}

void MainWindow::on_scissorsRadioButton_clicked()
{
}

void MainWindow::on_copyMyHashButton_clicked()
{
    QApplication::clipboard()->setText(ui->myHashLineEdit->text());
}

void MainWindow::on_copyMyCleartextButton_clicked()
{
    QApplication::clipboard()->setText(ui->myCleartextLineEdit->text());
}
