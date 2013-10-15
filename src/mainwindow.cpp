#include <QtGui>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    newGame();
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
    setChoice(ROCK);
}

void MainWindow::on_paperRadioButton_clicked()
{
    setChoice(PAPER);
}

void MainWindow::on_scissorsRadioButton_clicked()
{
    setChoice(SCISSORS);
}

void MainWindow::newGame()
{
    ui->myHashLabel->hide();
    ui->copyMyHashButton->hide();
    ui->myHashLineEdit->hide();
    ui->myHashLineEdit->setText("");
    ui->opponentHashLabel->hide();
    ui->opponentHashLineEdit->hide();
    ui->opponentHashLineEdit->setText("");
    ui->myCleartextLabel->hide();
    ui->copyMyCleartextButton->hide();
    ui->myCleartextLineEdit->hide();
    ui->myCleartextLineEdit->setText("");
    ui->opponentCleartextLabel->hide();
    ui->opponentCleartextLineEdit->hide();
    ui->opponentCleartextLineEdit->setText("");
    ui->rockRadioButton->setEnabled(true);
    ui->paperRadioButton->setEnabled(true);
    ui->scissorsRadioButton->setEnabled(true);
    ui->randomPushButton->setEnabled(true);
    ui->resultLabel->setText("");
    ui->resultLabel->hide();
}

QString sha1sum(QString arg) {
    return QCryptographicHash::hash(arg.toAscii(), QCryptographicHash::Sha1).toHex();
}

QString randomString() {
    QString random_text;
    for (int i = 0; i < 100; i++) {
        random_text += QString::number(qrand());
    }
    return sha1sum(random_text);
}

QString choiceLetter(Choice choice) {
    if (choice == ROCK) {
        return "r";
    } else if (choice == PAPER) {
        return "p";
    } else if (choice == SCISSORS) {
        return "s";
    }
    return "error";
}

QString MainWindow::myClearText() const
{
    return salt_ + "-" + choiceLetter(choice_);
}

QString MainWindow::myHash() const
{
    return sha1sum(myClearText());
}

void MainWindow::setChoice(Choice choice)
{
    choice_ = choice;
    salt_ = randomString();
    ui->myHashLineEdit->show();
    ui->myHashLabel->show();
    ui->copyMyHashButton->show();
    ui->myHashLineEdit->setText(myHash());
    ui->rockRadioButton->setEnabled(false);
    ui->paperRadioButton->setEnabled(false);
    ui->scissorsRadioButton->setEnabled(false);
    ui->randomPushButton->setEnabled(false);
    ui->opponentHashLabel->show();
    ui->opponentHashLineEdit->show();
}

void MainWindow::on_copyMyHashButton_clicked()
{
    QApplication::clipboard()->setText(ui->myHashLineEdit->text());
}

void MainWindow::on_opponentHashLineEdit_textEdited(QString opponent_hash)
{
    opponent_hash_ = opponent_hash;
    ui->myCleartextLabel->show();
    ui->copyMyCleartextButton->show();
    ui->myCleartextLineEdit->show();
    ui->myCleartextLineEdit->setText(myClearText());
    ui->opponentCleartextLabel->show();
    ui->opponentCleartextLineEdit->show();
}

void MainWindow::on_copyMyCleartextButton_clicked()
{
    QApplication::clipboard()->setText(ui->myCleartextLineEdit->text());
}

QString choiceWord(Choice choice) {
    if (choice == ROCK) {
        return QObject::tr("rock");
    } else if (choice == PAPER) {
        return QObject::tr("paper");
    } else if (choice == SCISSORS) {
        return QObject::tr("scissors");
    }
    return QObject::tr("error");
}

Choice cleartextToChoice(QString cleartext) {
    QStringList compounds = cleartext.split("-");
    if (compounds.size() != 2) {
        return INVALID_CHOICE;
    }
    QString salt = compounds[0];
    if (salt.length() < 10) {
        return INVALID_CHOICE;
    }
    QString choice = compounds[1];
    if (choice == "r") {
        return ROCK;
    } else if (choice == "p") {
        return PAPER;
    } else if (choice == "s") {
        return SCISSORS;
    }
    return INVALID_CHOICE;
}

Choice winnerOf(Choice c1, Choice c2) {
    if (c1 == c2) {
        return c1;
    } else if (c1 == ROCK && c2 == SCISSORS) {
        return c1;
    } else if (c1 == SCISSORS && c2 == PAPER) {
        return c1;
    } else if (c1 == PAPER && c2 == ROCK) {
        return c1;
    } else {
        return c2;
    }
}

void MainWindow::on_opponentCleartextLineEdit_textEdited(QString opponent_cleartext)
{
    QString text = "";
    QColor foreground = Qt::black;
    if (sha1sum(opponent_cleartext) == opponent_hash_) {
        Choice opponent_choice = cleartextToChoice(opponent_cleartext);
        if (opponent_choice != INVALID_CHOICE) {
            if (choice_ == opponent_choice) {
                text = tr("Draw: ") + choiceWord(choice_) + " = " + choiceWord(opponent_choice);
                foreground = Qt::darkYellow;
            } else if (winnerOf(choice_, opponent_choice) == choice_) {
                text = tr("You won: ") + choiceWord(choice_) + " > " + choiceWord(opponent_choice);
                foreground = Qt::green;
            } else if (winnerOf(choice_, opponent_choice) == opponent_choice) {
                text = tr("Opponent won: ") + choiceWord(opponent_choice) + " > " + choiceWord(choice_);
                foreground = Qt::red;
            }
        } else {
            text = tr("Invalid choice of your opponent! Although he doesn't cheat");
            foreground = Qt::red;
        }
    } else {
        text = tr("Opponent hash FAIL!!! It looks like he cheats");
        foreground = Qt::red;
    }
    ui->resultLabel->setText(text);
    ui->resultLabel->setStyleSheet("QLabel { color : " + foreground.name() +
        "; font-weight: 600; font-size: 14pt; }");
    ui->resultLabel->show();
}

void MainWindow::on_newGameButton_clicked()
{
    newGame();
}
