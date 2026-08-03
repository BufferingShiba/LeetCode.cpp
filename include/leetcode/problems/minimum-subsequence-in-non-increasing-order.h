#ifndef LEETCODE_PROBLEMS_MINIMUM_SUBSEQUENCE_IN_NON_INCREASING_ORDER_H_
#define LEETCODE_PROBLEMS_MINIMUM_SUBSEQUENCE_IN_NON_INCREASING_ORDER_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1403 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class MinimumSubsequenceInNonIncreasingOrderSolution : public SolutionBase<Func> {
 public:
  MinimumSubsequenceInNonIncreasingOrderSolution();

  std::vector<int> minSubsequence(std::vector<int>& nums);
};

}  // namespace problem_1403
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_SUBSEQUENCE_IN_NON_INCREASING_ORDER_H_
