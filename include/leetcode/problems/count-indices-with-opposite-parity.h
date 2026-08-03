#ifndef LEETCODE_PROBLEMS_COUNT_INDICES_WITH_OPPOSITE_PARITY_H__
#define LEETCODE_PROBLEMS_COUNT_INDICES_WITH_OPPOSITE_PARITY_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_3917 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class CountIndicesWithOppositeParitySolution
    : public SolutionBase<Func> {
 public:
  CountIndicesWithOppositeParitySolution();

  std::vector<int> countOppositeParity(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3917

#endif  // LEETCODE_PROBLEMS_COUNT_INDICES_WITH_OPPOSITE_PARITY_H__
