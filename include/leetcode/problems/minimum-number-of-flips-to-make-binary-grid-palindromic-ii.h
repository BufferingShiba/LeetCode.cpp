#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_FLIPS_TO_MAKE_BINARY_GRID_PALINDROMIC_II_H__
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_FLIPS_TO_MAKE_BINARY_GRID_PALINDROMIC_II_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3240 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiSolution
    : public SolutionBase<Func> {
 public:
  MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiSolution();

  int minFlips(std::vector<std::vector<int>>& grid);
};

}  // namespace leetcode::problem_3240

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_FLIPS_TO_MAKE_BINARY_GRID_PALINDROMIC_II_H__
