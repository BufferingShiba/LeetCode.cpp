#ifndef LEETCODE_PROBLEMS_LONGEST_PALINDROME_H__
#define LEETCODE_PROBLEMS_LONGEST_PALINDROME_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_409 {

using Func = std::function<int(std::string)>;

class LongestPalindromeSolution : public SolutionBase<Func> {
 public:
  LongestPalindromeSolution();

  int longestPalindrome(std::string s);
};

}  // namespace problem_409
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_PALINDROME_H__
