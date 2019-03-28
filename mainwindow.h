#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <question.h>
#include "ui_mainwindow.h" //for UI elements like QPushButton

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void validateAnswer(QString userAnswer);

    void on_btnAnswer_clicked();

    void on_btnReset_clicked();

private:
    Ui::MainWindow *ui;
    void displayLevel(Question *obj);
    void nextQuestion();
    void updateScore();

    Question *one;
    Question *two;
    Question *three;
    Question *four;
    Question *five;
    Question *six;
    Question *seven;
    Question *eight;
    Question *nine;
    Question *ten;
};

#endif // MAINWINDOW_H
