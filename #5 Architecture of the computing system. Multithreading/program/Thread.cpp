#include <pthread.h>
#include <unistd.h>
#include "Thread.h"

int Thread::start() {
    return pthread_create(&ThreadId, nullptr, Thread::thread_func, this);
}

int Thread::wait() const {
    return pthread_join(ThreadId, nullptr);
}

void Thread::sleepTime(int time) {
    sleep(time);
}

Thread::Thread(pthread_barrier_t *bar) {
    this->bar = bar;
}
// Общий барьер для всех потоков, который откроется, когда все потоки
// будут инициализированы.
void Thread::run() {
    pthread_barrier_wait(bar);
}

