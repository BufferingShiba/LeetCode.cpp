#ifndef LEETCODE_PROBLEMS_CHECK_IF_MATRIX_IS_X_MATRIX_H__
#define LEETCODE_PROBLEMS_CHECK_IF_MATRIX_IS_X_MATRIX_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2319 {

using Func = std::function<bool(std::vector<std::vector<int>>&)>;

class CheckIfMatrixIsXMatrixSolution : public SolutionBase<Func> {
 public:
  CheckIfMatrixIsXMatrixSolution();

  bool checkXMatrix(std::vector<std::vector<int>>& grid);
};

}  // namespace problem_2319
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_MATRIX_IS_X_MATRIX_H__
