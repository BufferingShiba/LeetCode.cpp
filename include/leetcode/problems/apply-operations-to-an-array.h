#ifndef LEETCODE_PROBLEMS_APPLY_OPERATIONS_TO_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_APPLY_OPERATIONS_TO_AN_ARRAY_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_2460 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class ApplyOperationsToAnArraySolution : public SolutionBase<Func> {
public:
    ApplyOperationsToAnArraySolution();

    std::vector<int> applyOperations(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2460

#endif  // LEETCODE_PROBLEMS_APPLY_OPERATIONS_TO_AN_ARRAY_H__
