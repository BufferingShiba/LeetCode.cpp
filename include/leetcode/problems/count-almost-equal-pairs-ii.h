#ifndef LEETCODE_PROBLEMS_COUNT_ALMOST_EQUAL_PAIRS_II_H_
#define LEETCODE_PROBLEMS_COUNT_ALMOST_EQUAL_PAIRS_II_H_

#include "leetcode/core.h"

namespace leetcode::problem_3267 {

using Func = std::function<int(std::vector<int>&)>;

class CountAlmostEqualPairsIiSolution : public SolutionBase<Func> {
 public:
  CountAlmostEqualPairsIiSolution();

  int countPairs(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3267

#endif  // LEETCODE_PROBLEMS_COUNT_ALMOST_EQUAL_PAIRS_II_H_
