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

int Algorithms::sumValues(const std::vector<int> &dataBases) {
    int sum = 0;
    for(auto &number : dataBases)
        sum += number;
    return sum;
}

void Algorithms::PrintDataBaseInfo(DataController* dataController) {
    std::cout << "\n" <<
                 "      Database 1\n";
    dataController->getPAlgorithmData1()->Print();
    std::cout << "      Database 2\n";
    dataController->getPAlgorithmData2()->Print();
    std::cout << "      Database 3\n";
    dataController->getPAlgorithmData3()->Print();
}

bool Algorithms::JudgeIfTargetReached(const int &currentValue, const int &targetValue, std::string bitset, std::vector<int> &resultsStored) {
    if(currentValue != targetValue)
        return false;
    while(bitset.size() < resultsStored.size())
        bitset += '0';
    for(int i = 0; i < resultsStored.size(); i++) {
        resultsStored[i] = bitset[i] - '0';
    }
    return true;
}

// value pass in parameter, the copy happens in the passing process
Node::Node(std::string bitset, Algorithms::Iterator iterator, int currentValue, int leftValue) :
bitset_(std::move(bitset)), iterator_(iterator), currentValue_(currentValue), leftValue_(leftValue) {
}

std::string Node::getBitset() const {
    return bitset_;
}

const Algorithms::Iterator &Node::getIterator() const {
    return iterator_;
}

int Node::getCurrentValue() const {
    return currentValue_;
}

int Node::getLeftValue() const {
    return leftValue_;
}

bool Algorithms::CheckAllDataBases(DataController* dataController) {
    PrintDataBaseInfo(dataController);
    bool validation = true;
    validation &= Algorithms::CheckIsValidOfSingleAlgorithm(Algorithms::BackTracing, *dataController);
//    validation &= Algorithms::CheckIsValidOfSingleAlgorithm(Algorithms::DynamicAssignments, *dataController);
    validation &= Algorithms::CheckIsValidOfSingleAlgorithm(Algorithms::BranchAndBound, *dataController);
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
    std::vector<int> resultsStored = std::vector<int>(dataBases.size());
    if(BranchAndBound_(dataBases, targetValue, resultsStored))
        return CompareSolutions(resultsStored, solutions.getSolutionArray());
    return false;
}

bool Algorithms::BackTracing_(const std::vector<int> &dataBases, std::vector<int>& results, const int &targetValue,
                              int currentValue, int leftValue, Algorithms::Iterator iterator) {
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

bool Algorithms::BranchAndBound_(const std::vector<int> &dataBases, const int &targetValue, std::vector<int> &resultsStored) {
    std::queue<Node> queue = std::queue<Node>();
    auto iterator = dataBases.cbegin();
    int currentValue = 0;
    int leftValue = sumValues(dataBases);
    Node node = Node(std::string(""), iterator, currentValue, leftValue);
    queue.push(node);

    while(!queue.empty()) {
        node = queue.front();
        queue.pop();

        iterator = node.getIterator();
        currentValue = node.getCurrentValue();
        leftValue = node.getLeftValue();

        if(JudgeIfTargetReached(currentValue, targetValue, node.getBitset(), resultsStored))
            return true;

        leftValue -= *iterator;
        if(currentValue + *iterator <= targetValue) {
            currentValue += *iterator;
            queue.emplace(node.getBitset() + '1', iterator + 1, currentValue, leftValue);
            currentValue -= *iterator;
        }
        if(leftValue + currentValue >= targetValue)
            queue.emplace(node.getBitset() + '0', iterator + 1, currentValue, leftValue);
    }
    //TODO : how to store various results in order and saves it?
    return false;
}




