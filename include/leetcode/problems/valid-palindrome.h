#ifndef LEETCODE_PROBLEMS_VALID_PALINDROME_H_
#define LEETCODE_PROBLEMS_VALID_PALINDROME_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_125 {

using Func = std::function<bool(std::string)>;

class ValidPalindromeSolution : public SolutionBase<Func> {
 public:
  ValidPalindromeSolution();

  bool isPalindrome(std::string s);
};

}  // namespace problem_125
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_VALID_PALINDROME_H_
