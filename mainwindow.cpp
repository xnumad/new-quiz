#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("Wie viele Ringen gibt‘s auf der Olympischen Flagge? \n1) 6\n2) 4\n3) 7\n4) 5");
    counter=0;
    richtigeAntwort=0;
    falscheAntwort=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    switch  (counter) {
    case 0: {
        if (ui->eingabe->text() =="4") {
                richtigeAntwort++;
        }
        else {
           falscheAntwort++;
        }
    }
    break; case 1: {
        if (ui->eingabe->text() =="1") {
                richtigeAntwort++;
        }
        else {
           falscheAntwort++;
        }
        break;
    }
    case 2: {
        if (ui->eingabe->text() =="3") {
                richtigeAntwort++;
        }
        else {
           falscheAntwort++;
        }
        break;
    }
    case 3: {
        if (ui->eingabe->text() =="4") {
                richtigeAntwort++;
        }
        else {
           falscheAntwort++;
        }
        break;
    }
    case 4: {
        if (ui->eingabe->text() =="2") {
                richtigeAntwort++;
        }
        else {
           falscheAntwort++;
        }
        break;
    }
    case 5: {
        if (ui->eingabe->text() =="3") {
                richtigeAntwort++;
        }
        else {
           falscheAntwort++;
        }
        break;
    }
    case 6: {
        if (ui->eingabe->text() =="4") {
                richtigeAntwort++;
        }
        else {
           falscheAntwort++;
        }
        break;
    }
    case 7: {
        if (ui->eingabe->text() =="3") {
                richtigeAntwort++;
        }
        else {
           falscheAntwort++;
        }
        break;
    }
    case 8: {
        if (ui->eingabe->text() =="3") {
                richtigeAntwort++;
        }
        else {
           falscheAntwort++;
        }
        break;
    }
    case 9: {
        if (ui->eingabe->text() =="3") {
                richtigeAntwort++;
        }
        else {
           falscheAntwort++;
        }
        break;
    }
    }

    ui->lbl_score_value->setText(QString::number(richtigeAntwort-falscheAntwort));
    ui->eingabe->setText("");

    switch (counter ++){
    case 0: ui->label->setText("Welches chemische Element macht mehr als die Hälfte der Masse \ndes menschlichen Körpers aus? \n1) Sauerstoff\n2) Eisen\n3) Kohlenstoff\n4) Calcium");
        break;
    case 1: ui->label->setText("Welches Meer ist nach einem mythologischen König benannt, der \nsich dort hineingestürzt haben soll? \n1) Ionisches Meer\n2) Adriatisches Meer\n3) Ägäisches Meer\n4) Kaspisches Meer");
        break;
    case 2: ui->label->setText("Die Amtssprache in Brasilien ist… \n1) Spanisch\n2) Italienisch\n3) Französisch\n4) Portugiesisch");
        break;
    case 3: ui->label->setText("Welche der folgenden war der erste Präsident von Amerika? \n1) Benjamin Franklin\n2) George Washington\n3) Thomas Jefferson\n4) Abraham Lincoln");
        break;
    case 4: ui->label->setText("Wer sollte sich mit der Zwanzig nach vier-Stellung auskennen? \n1) Fahrlehrer\n2) Karatemeister\n3) Kellner\n4) Landwirtschaftler");
        break;
    case 5: ui->label->setText("Ein Diamant entsteht aus dem chemischen Element… \n1) Beryllium\n2) Francium\n3) Krypton\n4) Kohlenstoff");
        break;
    case 6: ui->label->setText("Wer ist der römische Kriegsgott? \n1) Poseidon\n2) Hermes\n3) Ares\n4) Hephaestus");
        break;
    case 7: ui->label->setText("Welcher ist der längste Fluss der Welt? \n1) Amazonas\n2) Kongo-Fluss\n3) Nil\n4) Yangtze");
        break;
    case 8: ui->label->setText("Welches Jahr ist für den französischen Nationalfeiertag \nbesonders wichtig? \n1) 1776\n2) 1848\n3) 1789\n4) 1990");
        break;
    case 9:
        if (richtigeAntwort>=6) {
            ui->label->setText("Herzlichen Glückwunsch, du bist ein richtiger Genie!!! \n:)");
        }
        else {
             ui->label->setText("Leider muss ich dir mitteilen, dass du noch ein Noob bist. \nViel Glück beim nächsten Mal. :(");
        }
        break;
    }
}
