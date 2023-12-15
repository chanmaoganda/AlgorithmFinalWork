#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>

class Timer{
public:
    explicit Timer();

    ~Timer();

    long long StopTiming();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startPoint_;
};

#endif //TIMER_H
