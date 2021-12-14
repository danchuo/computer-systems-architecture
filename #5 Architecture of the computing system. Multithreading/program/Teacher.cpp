#include <iostream>
#include "Teacher.h"

Teacher::Teacher(pthread_barrier_t *bar, int number_of_students) : Thread(bar) {
    this->number_of_students_ = number_of_students;
    number_of_responses_received_ = 0;
    number_of_last_asked_question_ = 0;
    pthread_mutex_init(&mutex_, nullptr);
    current_student = nullptr;
}

void Teacher::run() {
    Thread::run();
    // Учитель работает до тех пор, пока все студенты не получат оценки.
    while (number_of_responses_received_ < number_of_students_) {
        if (current_student != nullptr) {
            auto reason = student_move_ == GET_QUESTION ? "get question" : "answer the question";
            std::cout << "Student " << current_student->student_number << " came to teacher to " << reason << "\n";

            if (student_move_ == GET_QUESTION) {
                current_student->setQuestion(++number_of_last_asked_question_);
            } else {
                current_student->setMark(checkAnswer());
            }

            sleepTime(1);
        }
    }

    std::cout << "\nAll " << number_of_students_ << " students pass exam and teacher went home!\n";
}

void Teacher::sitAtTheTableWithTeacher(Student *student, StudentRequest move) {
    // Критическая секция отображает стол учителя, который может разговаривать только
    // с одним студентом одновременно (сервер обрабатывает только один запрос).
    pthread_mutex_lock(&mutex_);
    current_student = student;
    student_move_ = move;

    if (move == GET_QUESTION) {
        current_student->waitQuestion();
    } else {
        current_student->waitMark();
    }

    current_student = nullptr;
    pthread_mutex_unlock(&mutex_);
}

int Teacher::checkAnswer() {
    int mark = rand() % 10;
    Thread::sleepTime(mark / 2);
    ++number_of_responses_received_;
    std::cout << "Teacher checked the student's " << current_student->student_number
              << " work and gave a grade of " << mark << '\n';
    return mark;
}






