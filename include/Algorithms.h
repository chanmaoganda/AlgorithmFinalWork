#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "DataController.h"

class Algorithms{
public:
    Algorithms();

    ~Algorithms();

    bool CheckIsValid(bool (*solvingProblem) (const std::vector<int>& dataBases, const std::vector<int>& solutions));
public:
    bool isTrue;
protected:
    DataController dataController;
};

#endif //ALGORITHMS_H
