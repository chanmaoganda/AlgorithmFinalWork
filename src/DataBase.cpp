#include "../include/DataBase.h"

AlgorithmData::AlgorithmData(int targetValue, int maxSize) :
    targetValue_(targetValue),
    maxSize_(maxSize),
    values_(std::move( std::vector<int> (0) ) ),
    resolutions_(Resolutions(maxSize)) {
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

void AlgorithmData::AssignResolutions(std::initializer_list<int> initializerList1,
                                      std::initializer_list<int> initializerList2,
                                      std::initializer_list<int> initializerList3) {
    resolutions_.Assign(initializerList1, initializerList2, initializerList3);
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

Resolutions &AlgorithmData::getResolutions() {
    return resolutions_;
}

Resolutions::Resolutions(int maxSize,
                         std::initializer_list<int> initializerList1,
                         std::initializer_list<int> initializerList2,
                         std::initializer_list<int> initializerList3) :
    maxSize_(maxSize),
    resolutionArray_(new std::vector<int>[3] ) {
    Assign(initializerList1, initializerList2, initializerList3);
}

Resolutions::~Resolutions() {
    delete [] resolutionArray_;
}

std::vector<int> *Resolutions::getResolutionArray() const {
    return resolutionArray_;
}

int Resolutions::getMaxSize() const {
    return maxSize_;
}

std::vector<int> Resolutions::SingleAssign(std::initializer_list<int> list) {
    std::vector<int> singleArray;
    for(int number : list)
        singleArray.push_back(number);
    return singleArray;
}

void Resolutions::Assign(std::initializer_list<int> initializerList1, std::initializer_list<int> initializerList2,
                         std::initializer_list<int> initializerList3) {
    resolutionArray_[0] = std::move( SingleAssign(initializerList1) );
    resolutionArray_[1] = std::move( SingleAssign(initializerList2) );
    resolutionArray_[2] = std::move( SingleAssign(initializerList3) );
}

