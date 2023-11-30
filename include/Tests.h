#ifndef TESTS_H
#define TESTS_H

#include "DataController.h"
#include "Algorithms.h"

class Tests{
public:
    explicit Tests();

    ~Tests();

    void Processing();

    void OutputFinalResults() const;

protected:
    DataController* dataController_;

    bool isValid_;
};

#endif //TESTS_H