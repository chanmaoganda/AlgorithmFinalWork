#ifndef INITIALIZER_H
#define INITIALIZER_H

#include "DataBase.h"


class Initializer{
public:
    Initializer();

    ~Initializer();

    void OnInitialize();

    _GLIBCXX_NODISCARD
    AlgorithmData *getPAlgorithmData1() const;

    _GLIBCXX_NODISCARD
    AlgorithmData *getPAlgorithmData2() const;

    _GLIBCXX_NODISCARD
    AlgorithmData *getPAlgorithmData3() const;

protected:
    AlgorithmData* pAlgorithmData1;
    AlgorithmData* pAlgorithmData2;
    AlgorithmData* pAlgorithmData3;
};

#endif //INITIALIZER_H