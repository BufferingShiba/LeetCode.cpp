#ifndef LEETCODE_LONGEST_ARITHMETIC_SUBSEQUENCE_H
#define LEETCODE_LONGEST_ARITHMETIC_SUBSEQUENCE_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1027 {

using Func = std::function<int(std::vector<int>&)>;

class LongestArithmeticSubsequenceSolution : public SolutionBase<Func> {
 public:
  LongestArithmeticSubsequenceSolution();

  int longestArithSeqLength(std::vector<int>& nums);
};

}  // namespace problem_1027
}  // namespace leetcode

#endif
