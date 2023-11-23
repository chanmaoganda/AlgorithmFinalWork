#ifndef DATA_H
#define DATA_H

#include <vector>
#include <bitset>
#include <iostream>
class AlgorithmData {

public:
    AlgorithmData(int targetValue, int maxSize);
    ~AlgorithmData() = default;

public:
    void Assign(std::initializer_list<int> list);

    void Print();

protected:
    int targetValue_;
    int maxSize_;
    std::vector<int> values_;
    std::vector<int> resolutions_;
};



#endif //DATA_H