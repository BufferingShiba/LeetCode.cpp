#ifndef LEETCODE_PROBLEM_3553_H_
#define LEETCODE_PROBLEM_3553_H_

#include "leetcode/core.h"

namespace leetcode::problem_3553 {

using Func = std::function<std::vector<int>(
    std::vector<std::vector<int>>&, std::vector<std::vector<int>>&)>;

class MinimumWeightedSubgraphWithTheRequiredPathsIiSolution
    : public SolutionBase<Func> {
 public:
  MinimumWeightedSubgraphWithTheRequiredPathsIiSolution();

  std::vector<int> minimumWeight(std::vector<std::vector<int>>& edges,
                                 std::vector<std::vector<int>>& queries);
};

}  // namespace leetcode::problem_3553

#endif  // LEETCODE_PROBLEM_3553_H_
