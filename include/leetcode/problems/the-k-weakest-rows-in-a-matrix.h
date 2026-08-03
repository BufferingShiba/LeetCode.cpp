#ifndef LEETCODE_PROBLEMS_THE_K_WEAKEST_ROWS_IN_A_MATRIX_H__
#define LEETCODE_PROBLEMS_THE_K_WEAKEST_ROWS_IN_A_MATRIX_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1337 {

using Func =
    std::function<std::vector<int>(std::vector<std::vector<int>>&, int)>;

class TheKWeakestRowsInAMatrixSolution
    : public SolutionBase<Func> {
 public:
  TheKWeakestRowsInAMatrixSolution();

  std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k);
};

}  // namespace problem_1337
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_THE_K_WEAKEST_ROWS_IN_A_MATRIX_H__
