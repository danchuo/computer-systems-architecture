#ifndef __THREAD__
#define __THREAD__

#include <pthread.h>

class Thread {
public:
    explicit Thread(pthread_barrier_t *bar);
    virtual ~Thread() = default;
    virtual void run();
    virtual int start();
    virtual int wait() const;
    static void sleepTime(int time);
protected:
    pthread_t ThreadId{};
    static void *thread_func(void *d) {
        (static_cast <Thread *>(d))->run();
        return nullptr;
    }
    pthread_barrier_t *bar;
};
#endif
