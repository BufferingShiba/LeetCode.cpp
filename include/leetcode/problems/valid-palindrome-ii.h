#ifndef LEETCODE_PROBLEMS_VALID_PALINDROME_II_H__
#define LEETCODE_PROBLEMS_VALID_PALINDROME_II_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_680 {

using Func = std::function<bool(std::string)>;

class ValidPalindromeIiSolution : public SolutionBase<Func> {
 public:
  ValidPalindromeIiSolution();

  bool validPalindrome(std::string s);
};

}  // namespace problem_680
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_VALID_PALINDROME_II_H__
