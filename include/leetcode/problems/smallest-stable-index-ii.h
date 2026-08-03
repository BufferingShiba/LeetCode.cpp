#ifndef LEETCODE_PROBLEMS_SMALLEST_STABLE_INDEX_II_H__
#define LEETCODE_PROBLEMS_SMALLEST_STABLE_INDEX_II_H__

#include "leetcode/core.h"

namespace leetcode::problem_3904 {

using Func = std::function<int(std::vector<int>&, int)>;

class SmallestStableIndexIiSolution : public SolutionBase<Func> {
 public:
  SmallestStableIndexIiSolution();
  int firstStableIndex(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_3904

#endif  // LEETCODE_PROBLEMS_SMALLEST_STABLE_INDEX_II_H__
