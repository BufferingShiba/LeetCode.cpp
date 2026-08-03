#ifndef LEETCODE_PROBLEMS_COUNT_NON_ADJACENT_SUBSETS_IN_A_ROOTED_TREE_H
#define LEETCODE_PROBLEMS_COUNT_NON_ADJACENT_SUBSETS_IN_A_ROOTED_TREE_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3939 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&, int)>;

class CountNonAdjacentSubsetsInARootedTreeSolution : public SolutionBase<Func> {
 public:
  CountNonAdjacentSubsetsInARootedTreeSolution();

  int countValidSubsets(std::vector<int>& parent, std::vector<int>& nums, int k);
};

}  // namespace problem_3939
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_NON_ADJACENT_SUBSETS_IN_A_ROOTED_TREE_H
