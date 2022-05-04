#pragma once
#include <thread>
#include <mutex>
#include <list>
#include "semaphore.h"
#include <functional>

class worker_thread {
public:
    worker_thread() : _thread(&worker_thread::threadFunc, this), _quit(false) {
    }
    void post(const std::function<void()>& func) {
        _mutex.lock();
        _jobs.push_back(func);
        _mutex.unlock();
        _sem.release();
    }
    void postQuit() {
        _mutex.lock();
        _quit = true;
        _mutex.unlock();
        _sem.release();
    }
    void join() {
        _thread.join();
    }
private:

    void threadFunc() {
        while (true) {
            _sem.acquire();
            _mutex.lock();
            if (!_jobs.size()) {
                _mutex.unlock();
                if (_quit) {
                    break;
                }
                continue;
            }
            auto job =  _jobs.front();
            _jobs.pop_front();
            _mutex.unlock();
            job();
        }
    }

    semaphore _sem;
    mutex _mutex;
    bool _quit;
    list<std::function<void()>> _jobs;
    thread _thread;
};
