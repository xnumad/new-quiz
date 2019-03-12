#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lbl_question->setText("Wie viele Ringen gibt‘s auf der Olympischen Flagge? \n1) 6\n2) 4\n3) 7\n4) 5");
    counter = 0;
    richtigBeantwortet = 0;
    falschBeantwortet = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::validateAnswer(QString correctAnswer)
{
    if (ui->txt_eingabe->text() == correctAnswer) {
        richtigBeantwortet++;
    }
    else {
        falschBeantwortet++;
        if (ui->chk_correctAnswers->checkState())
            QMessageBox(QMessageBox::Information, "Korrektur", "Die richtige Antwort wäre " + correctAnswer + ") gewesen.", QMessageBox::Ok).exec();
    }
}

void MainWindow::on_btn_next_clicked()
{
    switch  (counter) {
    case 0: validateAnswer("4"); break;
    case 1: validateAnswer("1"); break;
    case 2: validateAnswer("3"); break;
    case 3: validateAnswer("4"); break;
    case 4: validateAnswer("2"); break;
    case 5: validateAnswer("3"); break;
    case 6: validateAnswer("4"); break;
    case 7: validateAnswer("3"); break;
    case 8: validateAnswer("3"); break;
    case 9: validateAnswer("3"); break;
    }

    ui->lbl_score_value->setText(QString::number(richtigBeantwortet-falschBeantwortet));
    ui->txt_eingabe->setText("");
    ui->txt_eingabe->setFocus();

    switch (counter ++){
    case 0: ui->lbl_question->setText("Welches chemische Element macht mehr als die Hälfte der Masse \ndes menschlichen Körpers aus? \n1) Sauerstoff\n2) Eisen\n3) Kohlenstoff\n4) Calcium");
        break;
    case 1: ui->lbl_question->setText("Welches Meer ist nach einem mythologischen König benannt, der \nsich dort hineingestürzt haben soll? \n1) Ionisches Meer\n2) Adriatisches Meer\n3) Ägäisches Meer\n4) Kaspisches Meer");
        break;
    case 2: ui->lbl_question->setText("Die Amtssprache in Brasilien ist… \n1) Spanisch\n2) Italienisch\n3) Französisch\n4) Portugiesisch");
        break;
    case 3: ui->lbl_question->setText("Welche der folgenden war der erste Präsident von Amerika? \n1) Benjamin Franklin\n2) George Washington\n3) Thomas Jefferson\n4) Abraham Lincoln");
        break;
    case 4: ui->lbl_question->setText("Wer sollte sich mit der Zwanzig nach vier-Stellung auskennen? \n1) Fahrlehrer\n2) Karatemeister\n3) Kellner\n4) Landwirtschaftler");
        break;
    case 5: ui->lbl_question->setText("Ein Diamant entsteht aus dem chemischen Element… \n1) Beryllium\n2) Francium\n3) Krypton\n4) Kohlenstoff");
        break;
    case 6: ui->lbl_question->setText("Wer ist der römische Kriegsgott? \n1) Poseidon\n2) Hermes\n3) Ares\n4) Hephaestus");
        break;
    case 7: ui->lbl_question->setText("Welcher ist der längste Fluss der Welt? \n1) Amazonas\n2) Kongo-Fluss\n3) Nil\n4) Yangtze");
        break;
    case 8: ui->lbl_question->setText("Welches Jahr ist für den französischen Nationalfeiertag \nbesonders wichtig? \n1) 1776\n2) 1848\n3) 1789\n4) 1990");
        break;
    case 9:
        ui->txt_eingabe->hide();
        ui->chk_correctAnswers->hide();
        ui->btn_next->hide();
        if (richtigBeantwortet >= 6)
            ui->lbl_question->setText("Herzlichen Glückwunsch, du bist ein richtiges Genie!!! \n:)");
        else
            ui->lbl_question->setText("Leider muss ich dir mitteilen, dass du noch ein Noob bist. \nViel Glück beim nächsten Mal. :(");
        break;
    }
}