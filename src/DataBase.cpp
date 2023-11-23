#include "../include/DataBase.h"

AlgorithmData::AlgorithmData(int targetValue, int maxSize) :
targetValue_(targetValue),
maxSize_(maxSize),
values_(std::move( std::vector<int> (0) ) ),
resolutions_(std::move( std::vector<int>(maxSize_) )) {
}

void AlgorithmData::Assign(std::initializer_list<int> list) {
    for(int number : list)
        values_.push_back(number);
}

void AlgorithmData::Print() {
    for(int number : values_)
        std::cout << number << " ";
    std::cout << "\n";
}
