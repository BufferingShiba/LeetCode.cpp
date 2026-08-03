#ifndef LEETCODE_PROBLEMS_COUNT_SQUARE_SUBMATRICES_WITH_ALL_ONES_H__
#define LEETCODE_PROBLEMS_COUNT_SQUARE_SUBMATRICES_WITH_ALL_ONES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1277 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class CountSquareSubmatricesWithAllOnesSolution
    : public SolutionBase<Func> {
 public:
  CountSquareSubmatricesWithAllOnesSolution();

  int countSquares(std::vector<std::vector<int>>& matrix);
};

}  // namespace problem_1277
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_SQUARE_SUBMATRICES_WITH_ALL_ONES_H__
