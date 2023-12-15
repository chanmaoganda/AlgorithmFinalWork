#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "Timer.h"
class BenchMark{
public:
    explicit BenchMark(const char* message);

    ~BenchMark();
private:
    Timer timer_;

    std::string testName_;
};

#endif //BENCHMARK_H
