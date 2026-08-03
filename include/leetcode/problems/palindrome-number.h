#ifndef LEETCODE_PROBLEMS_PALINDROME_NUMBER_H__
#define LEETCODE_PROBLEMS_PALINDROME_NUMBER_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_9 {

using Func = std::function<bool(int)>;

class PalindromeNumberSolution : public SolutionBase<Func> {
 public:
  PalindromeNumberSolution();

  bool isPalindrome(int x);
};

}  // namespace problem_9
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PALINDROME_NUMBER_H__
