#include <iostream>
#include "../include/DataController.h"
#include "../include/Tests.h"
#include "../include/Algorithms.h"

int main() {
    DataController initializer = DataController();

    initializer.getPAlgorithmData1()->Print();

    Algorithms algorithms = Algorithms();

    bool valid = Algorithms::CheckIsValid(Algorithms::BackTracing, initializer);

    std::cout << valid << "\n";

    return 0;
}