#include "../include/DataBase.h"

AlgorithmData::AlgorithmData(int targetValue, int maxSize) :
    targetValue_(targetValue),
    maxSize_(maxSize),
    solutions_(Solutions(maxSize)) {
}
//TODO: why values_ initialization can be passed by std::move, while resolutions cannot???

void AlgorithmData::AssignValues(std::initializer_list<int> list) {
    for(int number : list) {
        values_.push_back(number);
    }
}

void AlgorithmData::Print() {
    std::cout << "number list :\n";
    for(int number : values_)
        std::cout << number << " ";
    std::cout << "\n\n";
}

void AlgorithmData::AssignSolutions(std::initializer_list<int> list) {
    solutions_.Assign(list);
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
    solutionArray_(std::vector<int>()){
}

Solutions::Solutions(int maxSize,
                     std::initializer_list<int> initializerList) :
    maxSize_(maxSize),
    solutionArray_(std::vector<int>()) {
    Assign(initializerList);
}

std::vector<int> Solutions::getSolutionArray() const {
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

void Solutions::Assign(std::initializer_list<int> list) {
    solutionArray_ = std::move( SingleAssign(list) );
}

