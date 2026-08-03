#ifndef LEETCODE_PROBLEMS_ROW_WITH_MAXIMUM_ONES_H__
#define LEETCODE_PROBLEMS_ROW_WITH_MAXIMUM_ONES_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2643 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&)>;

class RowWithMaximumOnesSolution : public SolutionBase<Func> {
 public:
  RowWithMaximumOnesSolution();

  std::vector<int> rowAndMaximumOnes(std::vector<std::vector<int>>& mat);
};

}  // namespace problem_2643
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ROW_WITH_MAXIMUM_ONES_H__
