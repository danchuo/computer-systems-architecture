#ifndef __STUDENT__
#define __STUDENT__
#include "Teacher.h"
#include "Thread.h"

class Teacher;

class Student : public Thread {
public:
    Student(pthread_barrier_t *bar, Teacher *teacher, int student_number);

    void setQuestion(int question);

    void setMark(int input_mark);

    void run() override;

    void getQuestion();

    void answerQuestion();

    void generateAnswer();

    void waitQuestion() const;
    void waitMark() const;

    Teacher *teacher;
    int number_of_question;
    int student_number;
    int mark;
};
#endif
