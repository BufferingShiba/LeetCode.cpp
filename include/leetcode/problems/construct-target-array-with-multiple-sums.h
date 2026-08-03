#ifndef LEETCODE_PROBLEMS_CONSTRUCT_TARGET_ARRAY_WITH_MULTIPLE_SUMS_H__
#define LEETCODE_PROBLEMS_CONSTRUCT_TARGET_ARRAY_WITH_MULTIPLE_SUMS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1354 {

using Func = std::function<bool(std::vector<int>&)>;

class ConstructTargetArrayWithMultipleSumsSolution
    : public SolutionBase<Func> {
 public:
  ConstructTargetArrayWithMultipleSumsSolution();

  bool isPossible(std::vector<int>& target);
};

}  // namespace leetcode::problem_1354

#endif  // LEETCODE_PROBLEMS_CONSTRUCT_TARGET_ARRAY_WITH_MULTIPLE_SUMS_H__
