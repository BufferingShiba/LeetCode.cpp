#ifndef LEETCODE_PROBLEMS_DETERMINE_WHETHER_MATRIX_CAN_BE_OBTAINED_BY_ROTATION_H__
#define LEETCODE_PROBLEMS_DETERMINE_WHETHER_MATRIX_CAN_BE_OBTAINED_BY_ROTATION_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_1886 {

using Func = std::function<bool(std::vector<std::vector<int>>&,
                                std::vector<std::vector<int>>&)>;

class DetermineWhetherMatrixCanBeObtainedByRotationSolution : public SolutionBase<Func> {
public:
    DetermineWhetherMatrixCanBeObtainedByRotationSolution();

    bool findRotation(std::vector<std::vector<int>>& mat,
                      std::vector<std::vector<int>>& target);
};

}  // namespace leetcode::problem_1886

#endif  // LEETCODE_PROBLEMS_DETERMINE_WHETHER_MATRIX_CAN_BE_OBTAINED_BY_ROTATION_H__
