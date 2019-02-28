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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void validateAnswer(QString correctAnswer);

private:
    Ui::MainWindow *ui;
    int counter;
    int richtigeAntwort;
    int falscheAntwort;
};

#endif // MAINWINDOW_H
