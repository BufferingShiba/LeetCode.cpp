#ifndef LEETCODE_PROBLEMS_CONSTRUCT_PRODUCT_MATRIX_H__
#define LEETCODE_PROBLEMS_CONSTRUCT_PRODUCT_MATRIX_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2906 {

using Func = std::function<std::vector<std::vector<int>>(
    std::vector<std::vector<int>>&)>;

class ConstructProductMatrixSolution : public SolutionBase<Func> {
 public:
  ConstructProductMatrixSolution();

  std::vector<std::vector<int>> constructProductMatrix(
      std::vector<std::vector<int>>& grid);
};

}  // namespace problem_2906
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CONSTRUCT_PRODUCT_MATRIX_H__
