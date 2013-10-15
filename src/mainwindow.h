#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

enum Choice {
    ROCK,
    PAPER,
    SCISSORS,
    INVALID_CHOICE
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
    QString salt_;
    QString opponent_hash_;

private slots:
    void on_randomPushButton_clicked();

    void on_rockRadioButton_clicked();
    void on_paperRadioButton_clicked();
    void on_scissorsRadioButton_clicked();

    void on_copyMyHashButton_clicked();
    void on_opponentHashLineEdit_textEdited(QString opponent_hash);
    void on_copyMyCleartextButton_clicked();
    void on_opponentCleartextLineEdit_textEdited(QString opponent_cleartext);

    void on_newGameButton_clicked();

private:
    void newGame();
    void setChoice(Choice choice);
    QString myClearText() const;
    QString myHash() const;
};

#endif // MAINWINDOW_H
