#include <utility>

#include "../include/Algorithms.h"

bool Algorithms::CheckAllDataBases(DataController* dataController) {
    bool validation = true;
//    validation &= Algorithms::CheckIsValidOfSingleAlgorithm(Algorithms::BackTracing, *dataController, "BackTracing");
    validation &= Algorithms::CheckIsValidOfSingleAlgorithm(Algorithms::DynamicAssignments, *dataController, "DynamicAssignments");
//    validation &= Algorithms::CheckIsValidOfSingleAlgorithm(Algorithms::BranchAndBound, *dataController, "BranchAndBound");
    return validation;
}

bool Algorithms::CheckIsValidOfSingleAlgorithm(Algorithms::SolveProblem solveProblem, const DataController& dataController, const char* algorithmName) {
    BenchMark benchMark(algorithmName);
    AlgorithmData* algorithmData;
    bool validation = true;

//    algorithmData = dataController.getPAlgorithmData1();
//    validation &= solveProblem(algorithmData->getValues(),
//                               algorithmData->getSolutions(),
//                               algorithmData->getTargetValue());
//
//    algorithmData = dataController.getPAlgorithmData2();
//    validation &= solveProblem(algorithmData->getValues(),
//                               algorithmData->getSolutions(),
//                               algorithmData->getTargetValue());

    algorithmData = dataController.getPAlgorithmData3();
    validation &= solveProblem(algorithmData->getValues(),
                               algorithmData->getSolutions(),
                               algorithmData->getTargetValue());
    return benchMark.setValidation(validation);
}

bool Algorithms::CompareSolutions(const std::vector<int> &solved, const std::vector<int> &targeted) {
    if(solved.size() != targeted.size())
        return false;
    auto solve = solved.cbegin();
    auto target = targeted.cbegin();
    while(solve != solved.cend()) {
        if(*solve++ != *target++)
            return false;
    }
    if(solve != solved.cend() || target != targeted.cend())
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

void Algorithms::Bitset2Vector(std::string bitset, std::vector<int> &results) {
    while(bitset.size() < results.size())
        bitset += '0';
    for(int i = 0; i < results.size(); i++)
        results[i] = bitset[i] - '0';
}

bool Algorithms::JudgeIfTargetReached(const int &currentValue, const int &targetValue, std::string bitset, std::vector<int> &resultsStored) {
    if(currentValue != targetValue)
        return false;
    // we need to complete the missing elements of `bitset`, cause the total useful size is smaller than the targeted solution size always
    Bitset2Vector(std::move(bitset), resultsStored);
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

Slot::Slot() :
validLevel_(0), isReachable_(false), bitset_(std::string("")){

}

Slot::Slot(int level, bool isReachable, std::string bitset) :
        validLevel_(level), isReachable_(isReachable), bitset_(std::move(bitset)) {
}

int Slot::getValidLevel_() const {
    return validLevel_;
}

bool Slot::getIsReachable() const {
    return isReachable_;
}

std::string Slot::getBitset() const {
    return bitset_;
}

Slot& Slot::setValidLevel(int validLevel) {
    if(validLevel < validLevel_)
        validLevel_ = validLevel;
    return *this;
}

Slot& Slot::setIsReachable(bool isReachable) {
    isReachable_ = isReachable;
    return *this;
}

Slot& Slot::setBitset(std::string bitset) {
    bitset_ = std::move(bitset);
    return *this;
}

Slot& Slot::addBitset(char ch) {
    bitset_ += ch;
    return *this;
}

bool Algorithms::findIsValid(const std::vector<Slot*> &slots, int level, int targetValue) {
    if(slots[targetValue]->getValidLevel_() == 0 && targetValue != 0)
        return false;
    if(slots[targetValue]->getIsReachable())
        return slots[targetValue]->getValidLevel_() <= level;
    return false;
}

bool Algorithms::generateBiggerSlot(const std::vector<int> &dataBase, std::vector<Slot*> &slots, int level, int targetValue) {
    Slot* slot = slots[targetValue];
    if (slot->getIsReachable()) {
        slot->addBitset('0');
        return true;
    }
    if (dataBase[level - 1] > targetValue) {
        if (findIsValid(slots, level - 1, targetValue)) {
            slot->setIsReachable(true)
            .setValidLevel(level)
            .addBitset('0');
            return true;
        }
        return false;   //by default, we set the Slot(reachAble:false, validLevel:0)
    }
    if (findIsValid(slots, level - 1, targetValue - dataBase[level - 1])) {
        slot->setIsReachable(true)
        .setValidLevel(level)
        .setBitset(slots[targetValue - dataBase[level - 1]]->getBitset() + '1');
        return true;
    }
    if (findIsValid(slots, level - 1, targetValue)) {
        slot->setIsReachable(true)
        .setValidLevel(level)
        .addBitset('0');
        return false;
    }
    slot->addBitset('0');
    return false;
}






