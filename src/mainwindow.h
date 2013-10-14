#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

private slots:
    void on_randomPushButton_clicked();
    void on_copyMyHashButton_clicked();
    void on_copyMyCleartextButton_clicked();
};

#endif // MAINWINDOW_H
