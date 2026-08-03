#ifndef LEETCODE_PROBLEMS_LONGEST_INCREASING_PATH_IN_A_MATRIX_H__
#define LEETCODE_PROBLEMS_LONGEST_INCREASING_PATH_IN_A_MATRIX_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_329 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class LongestIncreasingPathInAMatrixSolution
    : public SolutionBase<Func> {
 public:
  LongestIncreasingPathInAMatrixSolution();
  int longestIncreasingPath(std::vector<std::vector<int>>& matrix);
};

}  // namespace problem_329
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_INCREASING_PATH_IN_A_MATRIX_H__
