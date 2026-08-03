#ifndef LEETCODE_PROBLEMS_MAXIMUM_CONSISTENT_COLUMNS_IN_A_GRID_H__
#define LEETCODE_PROBLEMS_MAXIMUM_CONSISTENT_COLUMNS_IN_A_GRID_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3989 {

using Func = std::function<int(std::vector<std::vector<int>>&, int)>;

class MaximumConsistentColumnsInAGridSolution
    : public SolutionBase<Func> {
 public:
  MaximumConsistentColumnsInAGridSolution();

  int maxConsistentColumns(std::vector<std::vector<int>>& grid, int limit);
};

}  // namespace problem_3989
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_CONSISTENT_COLUMNS_IN_A_GRID_H__
