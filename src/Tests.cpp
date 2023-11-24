#include "../include/Tests.h"

Tests::Tests(DataController& dataController) :
    dataController_(new DataController(std::move(dataController))){
}
