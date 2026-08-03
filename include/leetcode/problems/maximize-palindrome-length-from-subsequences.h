#ifndef LEETCODE_PROBLEMS_MAXIMIZE_PALINDROME_LENGTH_FROM_SUBSEQUENCES_H__
#define LEETCODE_PROBLEMS_MAXIMIZE_PALINDROME_LENGTH_FROM_SUBSEQUENCES_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode::problem_1771 {

using Func = std::function<int(std::string, std::string)>;

class MaximizePalindromeLengthFromSubsequencesSolution
    : public SolutionBase<Func> {
 public:
  MaximizePalindromeLengthFromSubsequencesSolution();

  int longestPalindrome(std::string word1, std::string word2);
};

}  // namespace leetcode::problem_1771

#endif  // LEETCODE_PROBLEMS_MAXIMIZE_PALINDROME_LENGTH_FROM_SUBSEQUENCES_H__
