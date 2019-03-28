#include "question.h"

Question::Question(QString question, QString answers[]) //the answers[0] answer is supposed to be the correct answer (for validation purposes)
{
    this->question = question;
    for (int i = 0; i < 4; i++){
        this->answers[i] = answers[i];
    }
}

QString Question::getQuestion() const
{
    return question;
}

QString* Question::getAnswers()
{
    QString *fillarray[4] = {
        &this->answers[0], //& gibt die Adresse aus
        &this->answers[1],
        &this->answers[2],
        &this->answers[3]
    };

    return *fillarray;
}
