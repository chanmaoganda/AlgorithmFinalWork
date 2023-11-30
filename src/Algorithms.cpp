#include "../include/Algorithms.h"

bool Algorithms::CompareSolutions(const std::vector<int> &solved, const std::vector<int> &targeted) {
    if(solved.size() != targeted.size())
        return false;
    auto solve = solved.cbegin();
    auto target = targeted.cbegin();
    while(solve != solved.cend()) {
        if(*solve++ != *target++)
            return false;
    }

    if(solve != solved.cend())
        return false;
    if(target != targeted.cend())
        return false;
    return true;
}

int Algorithms::sumValues(const std::vector<int> &values) {
    int sum = 0;
    for(auto &number : values)
        sum += number;
    return sum;
}

void Algorithms::PrintDataBaseInfo(DataController* dataController) {
    std::cout << "\n      Database 1\n";
    dataController->getPAlgorithmData1()->Print();
    std::cout << "      Database 2\n";
    dataController->getPAlgorithmData2()->Print();
    std::cout << "      Database 3\n";
    dataController->getPAlgorithmData3()->Print();
}

bool Algorithms::CheckAllDataBases(DataController* dataController) {
    PrintDataBaseInfo(dataController);
    bool validation = true;
    validation &= Algorithms::CheckIsValidOfSingleAlgorithm(Algorithms::BackTracing, *dataController);
//    validation &= Algorithms::CheckIsValidOfSingleAlgorithm(Algorithms::DynamicAssignments, *dataController);
//    validation &= Algorithms::CheckIsValidOfSingleAlgorithm(Algorithms::BranchAndBound, *dataController);
    return validation;
}

bool Algorithms::CheckIsValidOfSingleAlgorithm(Algorithms::SolveProblem solveProblem, const DataController& dataController) {
    AlgorithmData* algorithmData;
    bool validation = true;

    algorithmData = dataController.getPAlgorithmData1();
    validation &= solveProblem(algorithmData->getValues(),
                                   algorithmData->getSolutions(),
                                   algorithmData->getTargetValue());

    algorithmData = dataController.getPAlgorithmData2();
    validation &= solveProblem(algorithmData->getValues(),
                               algorithmData->getSolutions(),
                               algorithmData->getTargetValue());

    algorithmData = dataController.getPAlgorithmData3();
    validation &= solveProblem(algorithmData->getValues(),
                               algorithmData->getSolutions(),
                               algorithmData->getTargetValue());

    return validation;
}

bool Algorithms::DynamicAssignments(const std::vector<int> &dataBases, const Solutions &solutions, const int& targetValue) {

    return false;
}

bool Algorithms::BackTracing(const std::vector<int> &dataBases, const Solutions &solutions, const int& targetValue) {
    std::vector<int> resultsStored = std::vector<int>(dataBases.size());
    int sum = sumValues(dataBases);
    if( BackTracing_(dataBases, resultsStored, targetValue, 0, sum,dataBases.cbegin()) )
        return CompareSolutions(resultsStored, solutions.getSolutionArray());
    return false;
}

bool Algorithms::BranchAndBound(const std::vector<int> &dataBases, const Solutions &solutions, const int& targetValue) {
    return false;
}


//void Algorithms::BackTracing_(const std::vector<int> &dataBases, std::vector<int> solutions, const int &targetValue,
//                              int currentValue, Iterator iterator, std::vector<int>& resultsStored) {
//    if(currentValue == targetValue) {
//        resultsStored = std::move(solutions);
//        return;
//    }
//    if(iterator == dataBases.end())
//        return;
//    if(currentValue + *iterator > targetValue) {
//        return BackTracing_(dataBases, solutions, targetValue, currentValue, ++iterator, resultsStored);
//    }
//    solutions[iterator - dataBases.begin()] = 1;
//    currentValue += *iterator;
//    return BackTracing_(dataBases, solutions, targetValue, currentValue, ++iterator, resultsStored);
//}

bool Algorithms::BackTracing_(const std::vector<int> &dataBases, std::vector<int>& results, const int &targetValue,
                              int currentValue, int leftValue, Iterator iterator) {
    // iterator is from the dataBases
    if(iterator == dataBases.cend()) {
        if (currentValue == targetValue)
            return true;
        return false;
    }
    leftValue -= *iterator;
    if(currentValue + *iterator <= targetValue) {
        results[iterator - dataBases.cbegin()] = 1;
        currentValue += *iterator;
        if(BackTracing_(dataBases, results, targetValue, currentValue, leftValue, iterator + 1))
            return true;
        currentValue -= *iterator;
    }
    if(currentValue + leftValue >= targetValue) {
        results[iterator - dataBases.cbegin()] = 0;
        if(BackTracing_(dataBases, results, targetValue, currentValue, leftValue, iterator + 1))
            return true;
    }
    return false;
}



