#include "../include/DataBase.h"

AlgorithmData::AlgorithmData(int targetValue, int maxSize) :
    targetValue_(targetValue),
    maxSize_(maxSize),
    values_(std::move( std::vector<int> (0) ) ),
    solutions_(Solutions(maxSize)) {
}
//TODO: why values_ initialization can be passed by std::move, while resolutions cannot???

void AlgorithmData::AssignValues(std::initializer_list<int> list) {
    for(int number : list)
        values_.push_back(number);
}

void AlgorithmData::Print() {
    for(int number : values_)
        std::cout << number << " ";
    std::cout << "\n";
}

void AlgorithmData::AssignSolutions(std::initializer_list<int> initializerList1,
                                      std::initializer_list<int> initializerList2,
                                      std::initializer_list<int> initializerList3) {
    solutions_.Assign(initializerList1, initializerList2, initializerList3);
}

int AlgorithmData::getTargetValue() const {
    return targetValue_;
}

int AlgorithmData::getMaxSize() const {
    return maxSize_;
}

std::vector<int> &AlgorithmData::getValues() {
    return values_;
}

Solutions &AlgorithmData::getSolutions() {
    return solutions_;
}


Solutions::Solutions(int maxSize) :
    maxSize_(maxSize),
    solutionArray_(new std::vector<int>[3] ){
}

Solutions::Solutions(int maxSize,
                     std::initializer_list<int> initializerList1,
                     std::initializer_list<int> initializerList2,
                     std::initializer_list<int> initializerList3) :
    maxSize_(maxSize),
    solutionArray_(new std::vector<int>[3] ) {
    Assign(initializerList1, initializerList2, initializerList3);
}

Solutions::~Solutions() {
    delete [] solutionArray_;
}

std::vector<int> *Solutions::getResolutionArray() const {
    return solutionArray_;
}

int Solutions::getMaxSize() const {
    return maxSize_;
}

std::vector<int> Solutions::SingleAssign(std::initializer_list<int> list) {
    std::vector<int> singleArray;
    for(int number : list)
        singleArray.push_back(number);
    return singleArray;
}

void Solutions::Assign(std::initializer_list<int> initializerList1, std::initializer_list<int> initializerList2,
                       std::initializer_list<int> initializerList3) {
    solutionArray_[0] = std::move( SingleAssign(initializerList1) );
    solutionArray_[1] = std::move( SingleAssign(initializerList2) );
    solutionArray_[2] = std::move( SingleAssign(initializerList3) );
}

