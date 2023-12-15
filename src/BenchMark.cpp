#include "BenchMark.h"

BenchMark::BenchMark(const char* message) : timer_() , testName_(message){
}

BenchMark::~BenchMark() {
    std::cout << "\n";
    long long costTime = timer_.StopTiming();
    std::cout << " TESTING CASE""  " << testName_ << "  \n" ;
    std::cout << "Time costs : " << costTime << "ms " << "(" << double(costTime) * 0.001 << "s )\n";
}
