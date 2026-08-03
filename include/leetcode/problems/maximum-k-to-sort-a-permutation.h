#ifndef LEETCODE_PROBLEMS_MAXIMUM_K_TO_SORT_A_PERMUTATION_H_
#define LEETCODE_PROBLEMS_MAXIMUM_K_TO_SORT_A_PERMUTATION_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3644 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumKToSortAPermutationSolution : public SolutionBase<Func> {
 public:
  MaximumKToSortAPermutationSolution();

  int sortPermutation(std::vector<int>& nums);
};

}  // namespace problem_3644
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_K_TO_SORT_A_PERMUTATION_H_
