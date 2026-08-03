#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_FLIPS_TO_MAKE_BINARY_GRID_PALINDROMIC_I_H__
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_FLIPS_TO_MAKE_BINARY_GRID_PALINDROMIC_I_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3239 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MinimumNumberOfFlipsToMakeBinaryGridPalindromicISolution
    : public SolutionBase<Func> {
 public:
  MinimumNumberOfFlipsToMakeBinaryGridPalindromicISolution();

  int minFlips(std::vector<std::vector<int>>& grid);
};

}  // namespace problem_3239
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_FLIPS_TO_MAKE_BINARY_GRID_PALINDROMIC_I_H__
