#include "../include/Initializer.h"

Initializer::Initializer() :
pAlgorithmData1( new AlgorithmData(53, 8)),
pAlgorithmData2( new AlgorithmData(50, 10)),
pAlgorithmData3( new AlgorithmData(100, 9)
) {
    OnInitialize();
}

Initializer::~Initializer() {
    delete pAlgorithmData1;
    delete pAlgorithmData2;
    delete pAlgorithmData3;
}

void Initializer::OnInitialize() {
        pAlgorithmData1->Assign({15, 22, 14, 26, 32, 9, 16, 8});
        pAlgorithmData2->Assign({41, 34, 21, 20, 8, 7, 7, 4, 3, 3});
        pAlgorithmData3->Assign({81, 80, 43, 40, 30, 26, 12, 11, 9});
}

AlgorithmData *Initializer::getPAlgorithmData1() const {
    return pAlgorithmData1;
}

AlgorithmData *Initializer::getPAlgorithmData2() const {
    return pAlgorithmData2;
}

AlgorithmData *Initializer::getPAlgorithmData3() const {
    return pAlgorithmData3;
}

