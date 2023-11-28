#ifndef DATA_H
#define DATA_H

#include <vector>
#include <bitset>
#include <iostream>

class Solutions{
public:
    explicit Solutions(int maxSize);

    explicit Solutions(int maxSize, std::initializer_list<int> initializerList1, std::initializer_list<int> initializerList2,
                       std::initializer_list<int> initializerList3);

    ~Solutions();

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
    std::vector<int>* solutionArray_;
    int maxSize_;
};

class AlgorithmData {

public:
    AlgorithmData(int targetValue, int maxSize);
    ~AlgorithmData() = default;

public:
    void AssignValues(std::initializer_list<int> list);

    void AssignSolutions(std::initializer_list<int> initializerList1,
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
    Solutions &getSolutions();

protected:
    int targetValue_;
    int maxSize_;
    std::vector<int> values_;
    Solutions solutions_;
};



#endif //DATA_H