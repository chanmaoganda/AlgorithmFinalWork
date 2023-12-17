#include "BenchMark.h"

BenchMark::BenchMark(const char* message) : timer_() , testName_(message), validation_(false){
}

BenchMark::~BenchMark() {
    std::cout << "\n";
    long long costTime = timer_.StopTiming();
    std::cout << "\033[1;36m TESTING CASE""  " << testName_ << "  \033[0m\n" ;
    if(validation_)
        std::cout << "\033[32m Time costs : " << costTime << "ms " << "(" << double(costTime) * 0.001 << "s )\033[0m\n";
    else
        std::cout << "\033[31m this test does not pass! \033[0m\n";
}

bool BenchMark::setValidation(bool validation) {
    validation_ = validation;
    return validation;
}
