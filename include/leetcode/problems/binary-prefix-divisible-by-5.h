#ifndef LEETCODE_PROBLEMS_BINARY_PREFIX_DIVISIBLE_BY_5_H_
#define LEETCODE_PROBLEMS_BINARY_PREFIX_DIVISIBLE_BY_5_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_1018 {

using Func = std::function<std::vector<bool>(std::vector<int>&)>;

class BinaryPrefixDivisibleBy5Solution : public SolutionBase<Func> {
 public:
  BinaryPrefixDivisibleBy5Solution();

  std::vector<bool> prefixesDivBy5(std::vector<int>& nums);
};

}  // namespace leetcode::problem_1018

#endif  // LEETCODE_PROBLEMS_BINARY_PREFIX_DIVISIBLE_BY_5_H_
