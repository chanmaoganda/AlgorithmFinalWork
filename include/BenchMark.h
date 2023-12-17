#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "Timer.h"
class BenchMark{
public:
    explicit BenchMark(const char* message);

    ~BenchMark();

    bool setValidation(bool validation);
private:
    Timer timer_;

    bool validation_;

    std::string testName_;
};

#endif //BENCHMARK_H
