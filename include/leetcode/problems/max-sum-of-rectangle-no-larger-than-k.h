#ifndef LEETCODE_PROBLEMS_MAX_SUM_OF_RECTANGLE_NO_LARGER_THAN_K_H__
#define LEETCODE_PROBLEMS_MAX_SUM_OF_RECTANGLE_NO_LARGER_THAN_K_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_363 {

using MaxSumSubmatrixFunc =
    std::function<int(std::vector<std::vector<int>>&, int)>;

class MaxSumOfRectangleNoLargerThanKSolution
    : public SolutionBase<MaxSumSubmatrixFunc> {
 public:
  MaxSumOfRectangleNoLargerThanKSolution();

  int maxSumSubmatrix(std::vector<std::vector<int>>& matrix, int k);
};

}  // namespace problem_363
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAX_SUM_OF_RECTANGLE_NO_LARGER_THAN_K_H__
