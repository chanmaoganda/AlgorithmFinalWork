#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <deque>
#include <algorithm>
#include "DataController.h"

class Algorithms{
public:
    typedef bool(*SolveProblem)(const std::vector<int>& dataBases, const Solutions &solutions, const int& targetValue);
    typedef std::vector<int>::const_iterator Iterator;

    Algorithms() = default;

    ~Algorithms() = default;

    static bool CheckAllDataBases(DataController* dataController);

    static bool CheckIsValidOfSingleAlgorithm(SolveProblem solveProblem, const DataController& dataController);

    // those three methods shall judge whether the algorithm result is valid of the solutions given
    static bool DynamicAssignments(const std::vector<int>& dataBases, const Solutions &solutions, const int& targetValue) ;

    static bool BackTracing(const std::vector<int>& dataBases, const Solutions &solutions, const int& targetValue);

    static bool BranchAndBound(const std::vector<int>& dataBases, const Solutions &solutions, const int& targetValue) ;

protected:
    static bool CompareSolutions(const std::vector<int>& solved, const std::vector<int>& targeted);

    static int sumValues(const std::vector<int>& values);

    static bool BackTracing_(const std::vector<int>& dataBases, std::vector<int>& results, const int& targetValue,
                             int currentValue, int leftValue, Iterator iterator);

    static std::vector<int> BranchAndBound_(const std::vector<int> &dataBases, const int &targetValue, Algorithms::Iterator iterator);
    static void PrintDataBaseInfo(DataController *dataController);
};

//动态规划 回溯 分支限界





#endif //ALGORITHMS_H
