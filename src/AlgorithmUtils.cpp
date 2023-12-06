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
    // we need to complete the missing elements of `bitset`, cause the total useful size is smaller than the targeted solution size always
    while(bitset.size() < resultsStored.size())
        bitset += '0';
    for(int i = 0; i < resultsStored.size(); i++) {
        resultsStored[i] = bitset[i] - '0';
    }
    return true;
}

void Algorithms::ReInitData(const Node &node, Algorithms::Iterator &iterator, int &currentValue, int &leftValue) {
    iterator = node.getIterator();
    currentValue = node.getCurrentValue();
    leftValue = node.getLeftValue();
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