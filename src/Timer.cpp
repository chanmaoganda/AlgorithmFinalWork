#include "Timer.h"

Timer::Timer() {
    startPoint_ = std::chrono::high_resolution_clock::now();
}

Timer::~Timer() = default;

long long Timer::StopTiming() {
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    return std::chrono::time_point_cast<std::chrono::microseconds>(end).time_since_epoch().count() -
            std::chrono::time_point_cast<std::chrono::microseconds>(startPoint_).time_since_epoch().count();
}


