#pragma once

#include "leetcode/core.h"

#include <functional>

namespace leetcode::problem_3646 {

using Func = std::function<long(long long)>;

class NextSpecialPalindromeNumberSolution : public SolutionBase<Func> {
 public:
  NextSpecialPalindromeNumberSolution();

  long specialPalindrome(long long n);
};

}  // namespace leetcode::problem_3646
