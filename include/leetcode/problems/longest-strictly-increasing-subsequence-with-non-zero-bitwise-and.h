#ifndef LEETCODE_PROBLEMS_LONGEST_STRICTLY_INCREASING_SUBSEQUENCE_WITH_NON_ZERO_BITWISE_AND_H
#define LEETCODE_PROBLEMS_LONGEST_STRICTLY_INCREASING_SUBSEQUENCE_WITH_NON_ZERO_BITWISE_AND_H

#include "leetcode/core.h"

namespace leetcode::problem_3825 {

using LongestStrictlyIncreasingSubsequenceWithNonZeroBitwiseAnd =
    SolutionBase<std::function<int(std::vector<int>&)>>;

class LongestStrictlyIncreasingSubsequenceWithNonZeroBitwiseAndSolution
    : public LongestStrictlyIncreasingSubsequenceWithNonZeroBitwiseAnd {
 public:
  LongestStrictlyIncreasingSubsequenceWithNonZeroBitwiseAndSolution();
  int longestSubsequence(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3825

#endif  // LEETCODE_PROBLEMS_LONGEST_STRICTLY_INCREASING_SUBSEQUENCE_WITH_NON_ZERO_BITWISE_AND_H
