#include <mutex>
#include <condition_variable>
#include "Semaforo.h"
using namespace std;

Semaforo::Semaforo(unsigned long c) {
    count_ = c;
}

void Semaforo::post() {
    unique_lock<decltype(mutex_)> lock(mutex_);
    ++count_;
    condition_.notify_one();
}

void Semaforo::wait() {
    unique_lock<decltype(mutex_)> lock(mutex_);
    while (!count_)
        condition_.wait(lock);
    --count_;
}

void Semaforo::init(unsigned long valor) {
    count_ = valor;
}