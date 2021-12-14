#include <cstdlib>
#include <iostream>
#include "Teacher.h"
#include "Student.h"

static pthread_barrier_t bar;

bool waitAll(Student **students, int number_of_students) {
    bool result = false;

    for (int i = 0; i < number_of_students; ++i) {
        result |= students[i]->wait();
    }
    return result;
}

int validateInputNumber(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "You only need to enter 1 parameter - number of students!\n";
        return -1;
    }

    auto number_of_students = atoi(argv[1]);

    if ((number_of_students < 1) || (number_of_students > 1000)) {
        std::cout << "Incorrect number of students = " <<
                  number_of_students <<
                  ". Set 0 < number <= 1000\n";
        return -1;
    }

    return number_of_students;
}

int main(int argc, char *argv[]) {
    int number_of_students = validateInputNumber(argc, argv);
    if (number_of_students == -1) {
        return 1;
    }

    pthread_barrier_init(&bar, nullptr, number_of_students + 2);

    auto *teacher = new Teacher(&bar, number_of_students);
    auto **students = new Student *[number_of_students];

    for (int i = 0; i < number_of_students; ++i) {
        students[i] = new Student(&bar, teacher, i + 1);
    }

    teacher->start();

    for (int i = 0; i < number_of_students; ++i) {
        students[i]->start();
    }

    // Использование барьера, для того, чтобы преподаватель и студенты одновременно
    // зашли в аудиторию.
    pthread_barrier_wait(&bar);
    pthread_barrier_destroy(&bar);

    return teacher->wait() || waitAll(students, number_of_students) ? EXIT_FAILURE : EXIT_SUCCESS;
}
