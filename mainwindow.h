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
    void on_btn_next_clicked();
    void validateAnswer(QString correctAnswer);

private:
    Ui::MainWindow *ui;
    int counter;
    int richtigBeantwortet;
    int falschBeantwortet;
};

#endif // MAINWINDOW_H
