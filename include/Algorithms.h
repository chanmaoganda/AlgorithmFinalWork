#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include<map>

#include "DataController.h"

class Algorithms{
public:
    Algorithms() = default;

    ~Algorithms() = default;

    static void Check();

    static bool CheckIsValid(bool (*SolvingProblem) (const std::vector<int>& dataBases, const std::vector<int>& solutions, const int&),
                      const DataController& dataController);

    static bool DynamicAssignments(const std::vector<int>& dataBases, const std::vector<int>& solutions, const int& targetValue) ;

    static bool BackTracing(const std::vector<int>& dataBases, const std::vector<int>& solutions, const int& targetValue) ;

    static bool BranchAndBound(const std::vector<int>& dataBases, const std::vector<int>& solutions, const int& targetValue) ;

protected:
    static bool CompareSolutions(const std::vector<int>& solved, const std::vector<int>& targeted);

};

//动态规划 回溯 分支限界





#endif //ALGORITHMS_H
