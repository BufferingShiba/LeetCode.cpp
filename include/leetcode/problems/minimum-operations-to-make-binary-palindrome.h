#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_BINARY_PALINDROME_H
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_BINARY_PALINDROME_H

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3766 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class MinimumOperationsToMakeBinaryPalindromeSolution : public SolutionBase<Func> {
 public:
  MinimumOperationsToMakeBinaryPalindromeSolution();

  std::vector<int> minOperations(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3766

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_BINARY_PALINDROME_H
