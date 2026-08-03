#ifndef LEETCODE_PROBLEMS_LONGEST_SUBSEQUENCE_WITH_NON_ZERO_BITWISE_XOR_H__
#define LEETCODE_PROBLEMS_LONGEST_SUBSEQUENCE_WITH_NON_ZERO_BITWISE_XOR_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3702 {

using Func = std::function<int(std::vector<int>&)>;

class LongestSubsequenceWithNonZeroBitwiseXorSolution
    : public SolutionBase<Func> {
 public:
  LongestSubsequenceWithNonZeroBitwiseXorSolution();

  int longestSubsequence(std::vector<int>& nums);
};

}  // namespace problem_3702
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_SUBSEQUENCE_WITH_NON_ZERO_BITWISE_XOR_H__
