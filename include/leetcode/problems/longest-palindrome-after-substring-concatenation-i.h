#ifndef LEETCODE_PROBLEMS_LONGEST_PALINDROME_AFTER_SUBSTRING_CONCATENATION_I_H_
#define LEETCODE_PROBLEMS_LONGEST_PALINDROME_AFTER_SUBSTRING_CONCATENATION_I_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3503 {

using Func = std::function<int(std::string, std::string)>;

class LongestPalindromeAfterSubstringConcatenationISolution : public SolutionBase<Func> {
 public:
  LongestPalindromeAfterSubstringConcatenationISolution();

  int longestPalindrome(std::string s, std::string t);
};

}  // namespace problem_3503
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_PALINDROME_AFTER_SUBSTRING_CONCATENATION_I_H_
