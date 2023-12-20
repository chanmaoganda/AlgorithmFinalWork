#include "../include/Algorithms.h"

bool Algorithms::DynamicAssignments(const std::vector<int> &dataBases, const Solutions &solutions, const int& targetValue) {
    std::vector<int> resultsStored = std::vector<int>(dataBases.size());
    if(DynamicAssignments_(dataBases, targetValue, resultsStored))
        return CompareSolutions(resultsStored, solutions.getSolutionArray());
    return false;
}

bool Algorithms::BackTracing(const std::vector<int> &dataBases, const Solutions &solutions, const int& targetValue) {
    std::vector<int> resultsStored = std::vector<int>(dataBases.size());
    if( BackTracing_(dataBases, resultsStored, targetValue, 0, sumValues(dataBases),dataBases.cbegin()) )
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

        ReInitData(node, iterator, currentValue, leftValue);

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
    return false;
}

bool Algorithms::DynamicAssignments_(const std::vector<int> &dataBases, const int &targetValue, std::vector<int> &resultsStored) {
    std::vector<Slot*> slots = std::vector<Slot*>(targetValue + 1); // allow zero to be pushed in
    for(auto &slot : slots)
        slot = new Slot(0, false, "");
    slots[0]->setIsReachable(true);
    for(int level = 1; level < dataBases.size(); level++) {
        for(int target = 1; target <= targetValue; target++) {
            generateBiggerSlot(dataBases, slots, level, target);
        }
    }
    if(slots[targetValue]->getIsReachable()) {
        Bitset2Vector(slots[targetValue]->getBitset(), resultsStored);
        return true;
    }
    for(auto &slot : slots)
        delete slot;
    return false;
}















