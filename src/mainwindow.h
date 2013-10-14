#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

enum Choice {
    ROCK,
    PAPER,
    SCISSORS
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    Choice choice_;

private slots:
    void on_randomPushButton_clicked();

    void on_rockRadioButton_clicked();
    void on_paperRadioButton_clicked();
    void on_scissorsRadioButton_clicked();

    void on_copyMyHashButton_clicked();
    void on_copyMyCleartextButton_clicked();

private:
    void setChoice(Choice choice);
};

#endif // MAINWINDOW_H
