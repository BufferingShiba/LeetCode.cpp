#ifndef LEETCODE_PROBLEMS_LONGEST_PALINDROMIC_SUBSTRING_H_
#define LEETCODE_PROBLEMS_LONGEST_PALINDROMIC_SUBSTRING_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_5 {

using Func = std::function<std::string(std::string)>;

class LongestPalindromicSubstringSolution : public SolutionBase<Func> {
 public:
  LongestPalindromicSubstringSolution();

  std::string longestPalindrome(std::string s);
};

}  // namespace leetcode::problem_5

#endif  // LEETCODE_PROBLEMS_LONGEST_PALINDROMIC_SUBSTRING_H_
