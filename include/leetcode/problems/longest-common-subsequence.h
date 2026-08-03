#ifndef LEETCODE_PROBLEMS_LONGEST_COMMON_SUBSEQUENCE_H__
#define LEETCODE_PROBLEMS_LONGEST_COMMON_SUBSEQUENCE_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1143 {

using Func = std::function<int(std::string, std::string)>;

class LongestCommonSubsequenceSolution : public SolutionBase<Func> {
 public:
  LongestCommonSubsequenceSolution();
  int longestCommonSubsequence(std::string text1, std::string text2);
};

}  // namespace leetcode::problem_1143

#endif  // LEETCODE_PROBLEMS_LONGEST_COMMON_SUBSEQUENCE_H__
