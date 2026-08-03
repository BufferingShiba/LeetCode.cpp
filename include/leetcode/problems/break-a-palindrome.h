#ifndef LEETCODE_PROBLEMS_BREAK_A_PALINDROME_H__
#define LEETCODE_PROBLEMS_BREAK_A_PALINDROME_H__

#include <functional>
#include <string>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_1328 {

using Func = std::function<std::string(std::string)>;

class BreakAPalindromeSolution : public SolutionBase<Func> {
 public:
  BreakAPalindromeSolution();

  std::string breakPalindrome(std::string palindrome);
};

}  // namespace problem_1328
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BREAK_A_PALINDROME_H__
