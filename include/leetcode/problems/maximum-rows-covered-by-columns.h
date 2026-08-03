#ifndef LEETCODE_PROBLEMS_MAXIMUM_ROWS_COVERED_BY_COLUMNS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_ROWS_COVERED_BY_COLUMNS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2397 {

using Func = std::function<int(std::vector<std::vector<int>>&, int)>;

class MaximumRowsCoveredByColumnsSolution : public SolutionBase<Func> {
 public:
  MaximumRowsCoveredByColumnsSolution();

  int maximumRows(std::vector<std::vector<int>>& matrix, int numSelect);
};

}  // namespace leetcode::problem_2397

#endif  // LEETCODE_PROBLEMS_MAXIMUM_ROWS_COVERED_BY_COLUMNS_H__
