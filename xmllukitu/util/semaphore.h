#pragma once
#include <mutex>
#include <condition_variable>
using namespace std;

class semaphore {
public:
    semaphore(int count=0) : _count(count) {
    }
    void acquire() {
        unique_lock<mutex> lock(_mutex, defer_lock_t());
        lock.lock();
        for(;;) {
            if (_count > 0) {
                _count--;
                lock.unlock();
                break;
            }
            _cv.wait(lock);
        }
    }
    void release() {
        _mutex.lock();
        _count++;
        _mutex.unlock();
        _cv.notify_one();
    }
private:
    int _count;
    mutex _mutex;
    condition_variable _cv;
};

