#include "../include/Algorithms.h"


//TODO : compare various results to given
bool Algorithms::CheckIsValid(bool (*solvingProblem)(const std::vector<int> &, const std::vector<int> &)) {
    if(solvingProblem(dataController.getPAlgorithmData1()->getValues(),
                  dataController.getPAlgorithmData1()->getResolutions().getResolutionArray()[0]))
        return true;
    return false;
}
