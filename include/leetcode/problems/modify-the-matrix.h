#ifndef LEETCODE_PROBLEMS_MODIFY_THE_MATRIX_H__
#define LEETCODE_PROBLEMS_MODIFY_THE_MATRIX_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3033 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<std::vector<int>>&)>;

class ModifyTheMatrixSolution : public SolutionBase<Func> {
 public:
  ModifyTheMatrixSolution();

  std::vector<std::vector<int>> modifiedMatrix(std::vector<std::vector<int>>& matrix);
};

}  // namespace problem_3033
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MODIFY_THE_MATRIX_H__
