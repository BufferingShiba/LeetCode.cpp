#ifndef LEETCODE_PROBLEMS_CHECK_ARRAY_FORMATION_THROUGH_CONCATENATION_H__
#define LEETCODE_PROBLEMS_CHECK_ARRAY_FORMATION_THROUGH_CONCATENATION_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1640 {

using Func = std::function<bool(std::vector<int>&, std::vector<std::vector<int>>&)>;

class CheckArrayFormationThroughConcatenationSolution
    : public SolutionBase<Func> {
 public:
  CheckArrayFormationThroughConcatenationSolution();

  bool canFormArray(std::vector<int>& arr,
                    std::vector<std::vector<int>>& pieces);
};

}  // namespace leetcode::problem_1640

#endif  // LEETCODE_PROBLEMS_CHECK_ARRAY_FORMATION_THROUGH_CONCATENATION_H__
