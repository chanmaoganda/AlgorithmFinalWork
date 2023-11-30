#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include<map>

#include "DataController.h"


class Algorithms{
public:
    typedef bool(*SolveProblem)(const std::vector<int>& dataBases, const Solutions &solutions, const int& targetValue);
    typedef std::vector<int>::const_iterator Iterator;
    typedef std::pair<bool, std::vector<int>> Pair;

    Algorithms() = default;

    ~Algorithms() = default;

    static void Check();

    static bool CheckIsValid(SolveProblem solveProblem, const DataController& dataController);

    // those three methods shall judge whether the algorithm result is valid of the solutions given
    static bool DynamicAssignments(const std::vector<int>& dataBases, const Solutions &solutions, const int& targetValue) ;

    static bool BackTracing(const std::vector<int>& dataBases, const Solutions &solutions, const int& targetValue);

    static bool BranchAndBound(const std::vector<int>& dataBases, const Solutions &solutions, const int& targetValue) ;

protected:
    static bool CompareSolutions(const std::vector<int>& solved, const std::vector<int>& targeted);

    static void BackTracing_(const std::vector<int>& dataBases, std::vector<int> solutions, const int& targetValue, int currentValue, Iterator iterator,
                             std::vector<int>& resultsStored);

};

//动态规划 回溯 分支限界





#endif //ALGORITHMS_H
