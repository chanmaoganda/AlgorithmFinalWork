#ifndef DATA_H
#define DATA_H

#include <vector>
#include <bitset>
#include <iostream>

class Resolutions{
public:
    explicit Resolutions(int maxSize, std::initializer_list<int> initializerList1, std::initializer_list<int> initializerList2,
                         std::initializer_list<int> initializerList3);

    ~Resolutions();

public:
    _GLIBCXX_NODISCARD
    std::vector<int> *getResolutionArray() const;

    _GLIBCXX_NODISCARD
    int getMaxSize() const;

    void Assign(std::initializer_list<int> initializerList1,
                std::initializer_list<int> initializerList2,
                std::initializer_list<int> initializerList3);

protected:
    _GLIBCXX_NODISCARD
    static std::vector<int> SingleAssign(std::initializer_list<int> list);

protected:
    std::vector<int>* resolutionArray_;
    int maxSize_;
};

class AlgorithmData {

public:
    AlgorithmData(int targetValue, int maxSize);
    ~AlgorithmData() = default;

public:
    void AssignValues(std::initializer_list<int> list);

    void AssignResolutions(std::initializer_list<int> initializerList1,
                           std::initializer_list<int> initializerList2,
                           std::initializer_list<int> initializerList3);

    void Print();

public:
    _GLIBCXX_NODISCARD
    int getTargetValue() const;

    _GLIBCXX_NODISCARD
    int getMaxSize() const;

    _GLIBCXX_NODISCARD
    std::vector<int> &getValues();

    _GLIBCXX_NODISCARD
    Resolutions &getResolutions();

protected:
    int targetValue_;
    int maxSize_;
    std::vector<int> values_;
    Resolutions resolutions_;
};



#endif //DATA_H