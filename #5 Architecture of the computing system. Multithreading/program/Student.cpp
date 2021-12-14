#include <iostream>
#include "Student.h"
#include <unistd.h>

Student::Student(pthread_barrier_t *bar, Teacher *teacher,
                 int student_number) : Thread(bar) {
    this->student_number = student_number;
    this->teacher = teacher;
    number_of_question = -1;
    mark = -1;
}

void Student::run() {
    Thread::run();

    getQuestion();

    generateAnswer();

    answerQuestion();
}

void Student::setQuestion(int question) {
    this->number_of_question = question;
    std::cout << "Student " << student_number << " get " << question
              << " number of question and start generating answer\n";
}

void Student::getQuestion() {
    teacher->sitAtTheTableWithTeacher(this, GET_QUESTION);
}

void Student::answerQuestion() {
    teacher->sitAtTheTableWithTeacher(this, ANSWER_QUESTION);
}

void Student::generateAnswer() {
    sleepTime(rand() % 6);
}

void Student::waitQuestion() const {
    while (number_of_question == -1) {
    }
}

void Student::waitMark() const {
    while (mark == -1) {
    }
}

void Student::setMark(int input_mark) {
    mark = input_mark;
    std::cout << "Student " << student_number << " get mark " << mark
              << " and went home\n";
}
