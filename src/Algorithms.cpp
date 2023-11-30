#include "../include/Algorithms.h"


//TODO : compare various results to given
bool Algorithms::CheckIsValid(Algorithms::SolveProblem solveProblem, const DataController& dataController) {
    AlgorithmData* algorithmData = dataController.getPAlgorithmData1();
    std::vector<int> finalResults = std::vector<int>();

    //TODO : check whether those methods is valid
    return solveProblem(algorithmData->getValues(),
                        algorithmData->getSolutions(),
                        algorithmData->getTargetValue());
}

// two kinds of assignments: divided by sum / divided by numbers of the subset
bool Algorithms::DynamicAssignments(const std::vector<int> &dataBases, const Solutions &solutions, const int& targetValue) {

    return false;
}

bool Algorithms::BackTracing(const std::vector<int> &dataBases, const Solutions &solutions, const int& targetValue) {
    std::vector<int> resultsStored = std::vector<int>();
    BackTracing_(dataBases, std::vector<int>(dataBases.size()), targetValue, 0, dataBases.cbegin(), resultsStored);
    return CompareSolutions(resultsStored, solutions.getSolutionArray());
}

bool Algorithms::BranchAndBound(const std::vector<int> &dataBases, const Solutions &solutions, const int& targetValue) {
    return false;
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

void Algorithms::Check() {

}

void Algorithms::BackTracing_(const std::vector<int> &dataBases, std::vector<int> solutions, const int &targetValue,
                              int currentValue, Iterator iterator, std::vector<int>& resultsStored) {
    if(currentValue == targetValue) {
        resultsStored = std::move(solutions);
        return;
    }
    if(iterator == dataBases.end())
        return;
    if(currentValue + *iterator > targetValue) {
        return BackTracing_(dataBases, solutions, targetValue, currentValue, ++iterator, resultsStored);
    }
    solutions[iterator - dataBases.begin()] = 1;
    currentValue += *iterator;
    return BackTracing_(dataBases, solutions, targetValue, currentValue, ++iterator, resultsStored);
}
