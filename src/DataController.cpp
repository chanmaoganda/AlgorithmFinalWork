#include <utility>

#include "../include/DataController.h"

DataController::DataController() :
    pAlgorithmData1( new AlgorithmData(50, 10)),
    pAlgorithmData2( new AlgorithmData(100, 9)),
    pAlgorithmData3( new AlgorithmData(22, 6)){
    OnInitialize();
}

DataController::~DataController() {
    delete pAlgorithmData1;
    delete pAlgorithmData2;
    delete pAlgorithmData3;
}

void DataController::OnInitialize() {
    pAlgorithmData1->AssignValues({41, 34, 21, 20, 8, 7, 7, 4, 3, 3});
    pAlgorithmData2->AssignValues({81, 80, 43, 40, 30, 26, 12, 11, 9});
    pAlgorithmData3->AssignValues({1, 2, 4, 8, 16, 32});

    pAlgorithmData1->AssignSolutions({0, 0, 1, 0, 1, 1, 1, 1, 1, 0});
    pAlgorithmData2->AssignSolutions({0, 1, 0, 0, 0, 0, 0, 1, 1});
    pAlgorithmData3->AssignSolutions({0, 1, 1, 0, 1, 0});
}

AlgorithmData *DataController::getPAlgorithmData1() const {
    return pAlgorithmData1;
}

AlgorithmData *DataController::getPAlgorithmData2() const {
    return pAlgorithmData2;
}

AlgorithmData *DataController::getPAlgorithmData3() const {
    return pAlgorithmData3;
}

DataController::DataController(DataController &&dataController)  noexcept :
    pAlgorithmData1(dataController.pAlgorithmData1),
    pAlgorithmData2(dataController.pAlgorithmData2),
    pAlgorithmData3(dataController.pAlgorithmData3) {
}

