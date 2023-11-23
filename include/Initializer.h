#ifndef INITIALIZER_H
#define INITIALIZER_H

#include "DataBase.h"

AlgorithmData* pAlgorithmData1 = new AlgorithmData(53, 8);
AlgorithmData* pAlgorithmData2 = new AlgorithmData(50, 10);
AlgorithmData* pAlgorithmData3 = new AlgorithmData(100, 9);

static void OnInitialize() {
    pAlgorithmData1->Assign({15, 22, 14, 26, 32, 9, 16, 8});
    pAlgorithmData2->Assign({41, 34, 21, 20, 8, 7, 7, 4, 3, 3});
    pAlgorithmData3->Assign({81, 80, 43, 40, 30, 26, 12, 11, 9});

}

#endif //INITIALIZER_H