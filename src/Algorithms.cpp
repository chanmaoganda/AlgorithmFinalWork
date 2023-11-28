#include "../include/Algorithms.h"


//TODO : compare various results to given
bool Algorithms::CheckIsValid(Algorithms::SolveProblem solveProblem, const DataController& dataController) {
    AlgorithmData* algorithmData = dataController.getPAlgorithmData1();
    std::vector<std::vector<int> > finalResults = std::vector<std::vector<int>>();

    //TODO : check whether those methods is valid
    bool validation = solveProblem(algorithmData->getValues(),  algorithmData->getSolutions(),
                 algorithmData->getTargetValue());

    return validation;
}

// two kinds of assignments: divided by sum / divided by numbers of the subset
bool Algorithms::DynamicAssignments(const std::vector<int> &dataBases, const Solutions &solutions, const int& targetValue) {

    return false;
}

bool Algorithms::BackTracing(const std::vector<int> &dataBases, const Solutions &solutions, const int& targetValue) {
    std::vector<std::vector<int>> resultsStored = std::vector<std::vector<int>>();
    BackTracing_(dataBases, std::vector<int>(dataBases.size()), targetValue, 0, dataBases.cbegin(), resultsStored);
    for(auto &result : resultsStored) {
        bool validation = false;
        for(int i = 0; i < 3; i++)
            validation |= CompareSolutions(result, solutions.getResolutionArray()[i]);
        return validation;
    }
    return false;
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
                              int currentValue, Iterator iterator, std::vector<std::vector<int>>& resultsStored) {
    if(currentValue == targetValue) {
        resultsStored.push_back(std::move(solutions));
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
