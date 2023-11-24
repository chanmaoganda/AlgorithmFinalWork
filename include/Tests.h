#ifndef TESTS_H
#define TESTS_H

#include "DataController.h"

class Tests{
public:
    explicit Tests(DataController& dataController);

protected:
    DataController* dataController_;
};

#endif //TESTS_H