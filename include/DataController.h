#ifndef INITIALIZER_H
#define INITIALIZER_H

#include "DataBase.h"
//#include "../thirdLibraries/json/json.h"
//#include "../thirdLibraries/json/json-forwards.h"


class DataController{
public:
    DataController();

    ~DataController();

    DataController(DataController&& dataController) noexcept;

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