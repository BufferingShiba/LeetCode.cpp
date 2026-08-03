#ifndef LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_PALINDROME_H_
#define LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_PALINDROME_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2697 {

using Func = std::function<std::string(std::string)>;

class LexicographicallySmallestPalindromeSolution : public SolutionBase<Func> {
 public:
  LexicographicallySmallestPalindromeSolution();

  std::string makeSmallestPalindrome(std::string s);
};

}  // namespace leetcode::problem_2697

#endif  // LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_PALINDROME_H_
