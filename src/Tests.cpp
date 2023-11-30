#include "../include/Tests.h"

Tests::Tests() :
    dataController_(new DataController()),
    isValid_(true){
}

Tests::~Tests() {
    delete dataController_;
}

void Tests::OutputFinalResults() const {
    if(isValid_)
        std::cout << "\033[32m all databases and algorithms passed!\n"
                     "\tCongratulations!\033[0m\n";
    else
        std::cout << "some bugs maybe still exist, come on, man!\n";
}

void Tests::Processing() {
    isValid_ = Algorithms::CheckAllDataBases(dataController_);
    OutputFinalResults();
}
