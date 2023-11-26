#include "../include/Algorithms.h"


//TODO : compare various results to given
bool Algorithms::CheckIsValid(bool (*SolvingProblem)(const std::vector<int> &, const std::vector<int> &, const int&), const DataController& dataController) {
    AlgorithmData* algorithmData = dataController.getPAlgorithmData1();
    if(SolvingProblem(algorithmData->getValues(),
                      algorithmData->getResolutions().getResolutionArray()[0],
                      algorithmData->getTargetValue()))
        return true;
    return false;
}

// two kinds of assignments: divided by sum / divided by numbers of the subset
bool Algorithms::DynamicAssignments(const std::vector<int> &dataBases, const std::vector<int> &solutions, const int& targetValue) {
    std::vector<int> solve = std::vector<int>();

    return false;
}

bool Algorithms::BackTracing(const std::vector<int> &dataBases, const std::vector<int> &solutions, const int& targetValue) {
    return false;
}

bool Algorithms::BranchAndBound(const std::vector<int> &dataBases, const std::vector<int> &solutions, const int& targetValue) {
    return false;
}

void Algorithms::Check() {

}

bool Algorithms::CompareSolutions(const std::vector<int> &solved, const std::vector<int> &targeted) {
    if(solved.size() != targeted.size())
        return false;
    auto solve = solved.cbegin();
    auto target = targeted.cbegin();
    while(solve != solved.cend() && target != targeted.cend()) {
        if(*solve != *target)
            return false;
        solve++;
        target++;
    }

    if(solve != solved.cend())
        return false;
    if(target != targeted.cend())
        return false;
    return true;
}


