#include <iostream>
#include "../include/DataController.h"
#include "../include/Tests.h"

int main() {
    DataController initializer = DataController();

    initializer.getPAlgorithmData1()->Print();

    return 0;
}