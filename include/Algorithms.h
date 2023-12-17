#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <queue>
#include <algorithm>
#include "DataController.h"
#include "Timer.h"
#include "BenchMark.h"

class Node;
class Slot;

class Algorithms{
public:
    typedef bool(*SolveProblem)(const std::vector<int>& dataBases, const Solutions &solutions, const int& targetValue);
    //back trace
    typedef std::vector<int>::const_iterator Iterator;

    Algorithms() = delete;

    ~Algorithms() = delete;

    static bool CheckAllDataBases(DataController* dataController);

    static bool CheckIsValidOfSingleAlgorithm(SolveProblem solveProblem, const DataController& dataController, const char* algorithmName);

    // those three methods shall judge whether the algorithm result is valid of the solutions given
    static bool DynamicAssignments(const std::vector<int>& dataBases, const Solutions &solutions, const int& targetValue);

    static bool BackTracing(const std::vector<int>& dataBases, const Solutions &solutions, const int& targetValue);

    static bool BranchAndBound(const std::vector<int>& dataBases, const Solutions &solutions, const int& targetValue);

    //some general functions needed
protected:
    static bool CompareSolutions(const std::vector<int>& solved, const std::vector<int>& targeted);

    static int sumValues(const std::vector<int>& dataBases);

    static void PrintDataBaseInfo(DataController *dataController);

protected:

    static bool BackTracing_(const std::vector<int>& dataBases, std::vector<int>& results, const int& targetValue,
                             int currentValue, int leftValue, Iterator iterator);

    static void Bitset2Vector(std::string bitset, std::vector<int> &results);

    static bool JudgeIfTargetReached(const int &currentValue, const int &targetValue, std::string bitset, std::vector<int> &resultsStored);

    static void ReInitData(const Node& node, Algorithms::Iterator &iterator, int &currentValue, int &leftValue);

    static bool BranchAndBound_(const std::vector<int> &dataBases, const int &targetValue, std::vector<int> &resultsStored);

    static bool findIsValid(const std::vector<Slot> &slots, int level, int targetValue);

    static bool generateBiggerSlot(const std::vector<int> &dataBase, std::vector<Slot> &slots, int level, int targetValue);

    static bool DynamicAssignments_(const std::vector<int> &dataBases, const int &targetValue, std::vector<int> &resultsStored);
};

//branch and bound
class Node {
public:
    explicit Node(std::string bitset, Algorithms::Iterator iterator, int currentValue, int leftValue);

    ~Node() = default;

    Node(const Node &) = default;

    _GLIBCXX_NODISCARD
    std::string getBitset() const;

    _GLIBCXX_NODISCARD
    int getCurrentValue() const;

    _GLIBCXX_NODISCARD
    int getLeftValue() const;

    _GLIBCXX_NODISCARD
    const Algorithms::Iterator &getIterator() const;

protected:
    std::string bitset_;
    Algorithms::Iterator iterator_;
    int currentValue_;
    int leftValue_;
};

//dynamic assignment
//https://www.jianshu.com/p/0322014dc357
class Slot {
public:
    explicit Slot();

    explicit Slot(int level, bool isReachable, std::string bitset);


    ~Slot() = default;

    Slot(const Slot &) = default;

    _GLIBCXX_NODISCARD
    int getValidLevel_() const;

    _GLIBCXX_NODISCARD
    bool getIsReachable() const;

    _GLIBCXX_NODISCARD
    std::string getBitset() const;

    Slot& setValidLevel(int validLevel);

    Slot& setIsReachable(bool isReachable);

    Slot& setBitset(std::string bitset);

    Slot& addBitset(char ch);

protected:
    int validLevel_;
    bool isReachable_;
    std::string bitset_;
};

#endif //ALGORITHMS_H





