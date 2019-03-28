#ifndef QUESTION_H
#define QUESTION_H
#include <QString>

using namespace std;

class Question
{
public:
    Question(QString question, QString answers[4]);
    QString getQuestion() const;
    QString* getAnswers();
private:
    QString question;
    QString answers[4];
};

#endif // QUESTION_H
