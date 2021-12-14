#ifndef __TEACHER__
#define __TEACHER__

#include "Thread.h"
#include "Student.h"

class Student;

enum StudentRequest {
    GET_QUESTION,
    ANSWER_QUESTION
};

class Teacher : public Thread {
public:
    explicit Teacher(pthread_barrier_t *bar, int number_of_students);

    void run() override;

    void sitAtTheTableWithTeacher(Student *student, StudentRequest move);

    int checkAnswer();

    Student *current_student{};

private:
    StudentRequest student_move_{};
    pthread_mutex_t mutex_{};
    int number_of_responses_received_;
    int number_of_students_;
    int number_of_last_asked_question_;
};
#endif
