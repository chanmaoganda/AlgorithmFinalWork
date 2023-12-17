#include "../include/Tests.h"

Tests::Tests() :
    dataController_(new DataController()),
    isValid_(true){
}

Tests::~Tests() {
    delete dataController_;
}

void Tests::OutputFinalResults() const {
    std::cout << "\n";
    if(isValid_)
        std::cout << "\033[32m all databases and algorithms passed!\n"
                     "\tCongratulations!\033[0m\n";
    else
        std::cout << "\033[31m" << "some bugs maybe still exist, come on, man!\033[0m\n";
}

void Tests::Processing() {
    isValid_ = Algorithms::CheckAllDataBases(dataController_);
    OutputFinalResults();
    std::cin.get();
}

DataController *Tests::getDataController() const {
    return dataController_;
}
