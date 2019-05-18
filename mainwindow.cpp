#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //map signals of clicking the answer buttons 1-4 to the same general answer button click signal which still knows which button was clicked
    connect(ui->btnAnswer1, SIGNAL(clicked()), this, SLOT(on_btnAnswer_clicked()));
    connect(ui->btnAnswer2, SIGNAL(clicked()), this, SLOT(on_btnAnswer_clicked()));
    connect(ui->btnAnswer3, SIGNAL(clicked()), this, SLOT(on_btnAnswer_clicked()));
    connect(ui->btnAnswer4, SIGNAL(clicked()), this, SLOT(on_btnAnswer_clicked()));

    QString one_answers[] = {"5", "6", "7", "4"};
    //Question zero("Wie viele Ringe gibt's auf der Olympischen Flagge?", zero_answers); lässt später nicht darauf zugreifen
    one = new Question("Wie viele Ringe gibt's auf der Olympischen Flagge?", one_answers);

    QString two_answers[] = {"Sauerstoff", "Eisen", "Kohlenstoff", "Calcium"};
    two = new Question("Welches chemische Element macht mehr als die Hälfte der Masse \ndes menschlichen Körpers aus?", two_answers);

    QString three_answers[] = {"Ägäisches Meer", "Ionisches Meer", "Adriatisches Meer", "Kaspisches Meer"};
    three = new Question("Welches Meer ist nach einem mythologischen König benannt, der \nsich dort hineingestürzt haben soll?", three_answers);

    QString four_answers[] = {"Portugiesisch", "Spanisch", "Italienisch", "Französisch"};
    four = new Question("Die Amtssprache in Brasilien ist…", four_answers);

    QString five_answers[] = {"George Washington", "Benjamin Franklin", "Thomas Jefferson", "Abraham Lincoln"};
    five = new Question("Welche der folgenden war der erste Präsident von Amerika?", five_answers);

    QString six_answers[] = {"Kellner", "Fahrlehrer", "Karatemeister", "Landwirtschaftler"};
    six = new Question("Wer sollte sich mit der Zwanzig nach vier-Stellung auskennen?", six_answers);

    QString seven_answers[] = {"Kohlenstoff", "Beryllium", "Francium", "Krypton"};
    seven = new Question("Ein Diamant entsteht aus dem chemischen Element…", seven_answers);

    QString eight_answers[] = {"Ares", "Poseidon", "Hermes", "Hephaestus"};
    eight = new Question("Wer ist der römische Kriegsgott?", eight_answers);

    QString nine_answers[] = {"Nil", "Amazonas", "Kongo-Fluss", "Yangtze"};
    nine = new Question("Welcher ist der längste Fluss der Welt?", nine_answers);

    QString ten_answers[] = {"1789", "1776", "1848", "1990"};
    ten = new Question("Welches Jahr ist für den französischen Nationalfeiertag \nbesonders wichtig?", ten_answers);

    displayLevel(one);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayLevel(Question *obj)
{
    ui->lblQuestion->setText(obj->getQuestion());

    int random[] = {0,1,2,3};
    srand(time(nullptr)); //initialize random seed
    random_shuffle(std::begin(random), std::end(random)); //randomly shuffle array to display questions

    ui->btnAnswer1->setText(obj->getAnswers()[random[0]]);
    ui->btnAnswer2->setText(obj->getAnswers()[random[1]]);
    ui->btnAnswer3->setText(obj->getAnswers()[random[2]]);
    ui->btnAnswer4->setText(obj->getAnswers()[random[3]]);
}

void MainWindow::nextQuestion()
{
    ui->lblQuestionCounterValue->setText(QString::number(ui->lblQuestionCounterValue->text().toInt() + 1));
    switch (ui->lblQuestionCounterValue->text().toInt()){
    //case 1 should never entry because one must have viewed question 0 before which doesn't exist
    case 2:  displayLevel(two);   break;
    case 3:  displayLevel(three); break;
    case 4:  displayLevel(four);  break;
    case 5:  displayLevel(five);  break;
    case 6:  displayLevel(six);   break;
    case 7:  displayLevel(seven); break;
    case 8:  displayLevel(eight); break;
    case 9:  displayLevel(nine);  break;
    case 10: displayLevel(ten);   break;
    case 11:
        ui->btnAnswer1->hide();
        ui->btnAnswer2->hide();
        ui->btnAnswer3->hide();
        ui->btnAnswer4->hide();
        ui->chkCorrectAnswers->hide();
        ui->lblQuestionCounter->hide();
        ui->lblQuestionCounterValue->hide();
        if (ui->lblAnsweredCorrectlyValue->text().toInt() >= 6)
            ui->lblQuestion->setText("Herzlichen Glückwunsch, du bist ein richtiges Genie!!! \n:)");
        else
            ui->lblQuestion->setText("Leider muss ich dir mitteilen, dass du noch ein Noob bist. \nViel Glück beim nächsten Mal. :(");
        break;
    }
}

void MainWindow::validateAnswer(QString userAnswer)
{
    //Determine current question to be able to determine the currently correct answer
    Question *currentQuestion;
    switch (ui->lblQuestionCounterValue->text().toInt()){
    case 1: currentQuestion = one;   break;
    case 2: currentQuestion = two;   break;
    case 3: currentQuestion = three; break;
    case 4: currentQuestion = four;  break;
    case 5: currentQuestion = five;  break;
    case 6: currentQuestion = six;   break;
    case 7: currentQuestion = seven; break;
    case 8: currentQuestion = eight; break;
    case 9: currentQuestion = nine;  break;
    case 10: currentQuestion = ten;  break;
    default: currentQuestion = nullptr;
    }

    //Actually validate answer
    if (userAnswer == currentQuestion->getAnswers()[0]) {
        ui->lblAnsweredCorrectlyValue->setText(QString::number(ui->lblAnsweredCorrectlyValue->text().toInt() + 1));
    }
    else {
        ui->lblAnsweredWrongValue->setText(QString::number(ui->lblAnsweredWrongValue->text().toInt() + 1));
        if (ui->chkCorrectAnswers->checkState())
            QMessageBox(QMessageBox::Information, "Korrektur", "Die richtige Antwort wäre " + currentQuestion->getAnswers()[0] + " gewesen.", QMessageBox::Ok).exec();
    }
    updateScore();
}

void MainWindow::updateScore()
{
    ui->lblScoreValue->setText(QString::number(ui->lblAnsweredCorrectlyValue->text().toInt() - ui->lblAnsweredWrongValue->text().toInt())); //recalculate
}

void MainWindow::on_btnAnswer_clicked()
{
    validateAnswer(QObject::sender()->property("text").toString()); //sender is the button which was clicked by the user and initiated/called this slot, compare its text to the correct answer of the question
    nextQuestion();
}

void MainWindow::on_btnReset_clicked()
{
    ui->lblQuestionCounterValue->setText("1");
    ui->lblAnsweredCorrectlyValue->setText("0");
    ui->lblAnsweredWrongValue->setText("0");
    ui->btnAnswer1->show();
    ui->btnAnswer2->show();
    ui->btnAnswer3->show();
    ui->btnAnswer4->show();
    ui->lblQuestionCounter->show();
    ui->lblQuestionCounterValue->show();
    ui->chkCorrectAnswers->show();
    updateScore();
    displayLevel(one);
}
