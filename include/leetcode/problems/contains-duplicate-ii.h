#ifndef LEETCODE_PROBLEMS_CONTAINS_DUPLICATE_II_H__
#define LEETCODE_PROBLEMS_CONTAINS_DUPLICATE_II_H__

#include "leetcode/core.h"

namespace leetcode::problem_219 {

using Func = std::function<bool(std::vector<int>&, int)>;

class ContainsDuplicateIiSolution : public SolutionBase<Func> {
 public:
  ContainsDuplicateIiSolution();

  bool containsNearbyDuplicate(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_219

#endif  // LEETCODE_PROBLEMS_CONTAINS_DUPLICATE_II_H__
