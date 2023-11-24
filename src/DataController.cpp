#include "../include/DataController.h"

DataController::DataController() :
    pAlgorithmData1( new AlgorithmData(53, 8)),
    pAlgorithmData2( new AlgorithmData(50, 10)),
    pAlgorithmData3( new AlgorithmData(100, 9)) {
    OnInitialize();
}

DataController::~DataController() {
    delete pAlgorithmData1;
    delete pAlgorithmData2;
    delete pAlgorithmData3;
}

void DataController::OnInitialize() {
        pAlgorithmData1->AssignValues({15, 22, 14, 26, 32, 9, 16, 8});
        pAlgorithmData2->AssignValues({41, 34, 21, 20, 8, 7, 7, 4, 3, 3});
        pAlgorithmData3->AssignValues({81, 80, 43, 40, 30, 26, 12, 11, 9});
        pAlgorithmData1->AssignResolutions({}, {}, {});
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


