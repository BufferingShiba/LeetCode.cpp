#ifndef LEETCODE_PROBLEMS_FIND_THE_WIDTH_OF_COLUMNS_OF_A_GRID_H__
#define LEETCODE_PROBLEMS_FIND_THE_WIDTH_OF_COLUMNS_OF_A_GRID_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2639 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&)>;

class FindTheWidthOfColumnsOfAGrid : public SolutionBase<Func> {
 public:
  std::vector<int> findColumnWidth(std::vector<std::vector<int>>& grid);
};

class FindTheWidthOfColumnsOfAGridSolution : public FindTheWidthOfColumnsOfAGrid {
 public:
  FindTheWidthOfColumnsOfAGridSolution();
};

}  // namespace problem_2639
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_WIDTH_OF_COLUMNS_OF_A_GRID_H__
