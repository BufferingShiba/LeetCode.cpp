#ifndef LEETCODE_PROBLEMS_COUNT_BINARY_PALINDROMIC_NUMBERS_H_
#define LEETCODE_PROBLEMS_COUNT_BINARY_PALINDROMIC_NUMBERS_H_

#include <functional>
#include "leetcode/core.h"

namespace leetcode::problem_3677 {

using Func = std::function<int(long long)>;

class CountBinaryPalindromicNumbersSolution : public SolutionBase<Func> {
 public:
  CountBinaryPalindromicNumbersSolution();

  int countBinaryPalindromes(long long n);
};

}  // namespace leetcode::problem_3677

#endif  // LEETCODE_PROBLEMS_COUNT_BINARY_PALINDROMIC_NUMBERS_H_
