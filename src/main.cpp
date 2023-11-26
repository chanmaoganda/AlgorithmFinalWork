#include <iostream>
#include "../include/DataController.h"
#include "../include/Tests.h"
#include "../include/Algorithms.h"

int main() {
    DataController initializer = DataController();

    initializer.getPAlgorithmData1()->Print();

    Algorithms algorithms = Algorithms();


    return 0;
}