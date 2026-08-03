// Copyright (c) LeetCode 2025.

#ifndef LEETCODE_PROBLEMS_FACTORIAL_TRAILING_ZEROES_H_
#define LEETCODE_PROBLEMS_FACTORIAL_TRAILING_ZEROES_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_172 {

using Func = std::function<int(int)>;

class FactorialTrailingZeroesSolution : public SolutionBase<Func> {
 public:
  FactorialTrailingZeroesSolution();

  int trailingZeroes(int n);
};

}  // namespace problem_172
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FACTORIAL_TRAILING_ZEROES_H_
