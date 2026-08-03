#ifndef LEETCODE_PROBLEMS_SHORTEST_PALINDROME_H__
#define LEETCODE_PROBLEMS_SHORTEST_PALINDROME_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_214 {

using Func = std::function<std::string(std::string)>;

class ShortestPalindromeSolution : public SolutionBase<Func> {
 public:
  ShortestPalindromeSolution();

  std::string shortestPalindrome(std::string s);
};

}  // namespace leetcode::problem_214

#endif  // LEETCODE_PROBLEMS_SHORTEST_PALINDROME_H__
