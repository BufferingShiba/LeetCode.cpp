#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_A_UNI_VALUE_GRID_H_
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_A_UNI_VALUE_GRID_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2033 {

using Func = std::function<int(std::vector<std::vector<int>>&, int)>;

class MinimumOperationsToMakeAUniValueGridSolution : public SolutionBase<Func> {
 public:
  MinimumOperationsToMakeAUniValueGridSolution();

  int minOperations(std::vector<std::vector<int>>& grid, int x) {
    return getSolution()(grid, x);
  }
};

}  // namespace leetcode::problem_2033

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_A_UNI_VALUE_GRID_H_
