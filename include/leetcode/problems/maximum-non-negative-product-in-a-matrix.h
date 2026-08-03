#include "leetcode/core.h"

namespace leetcode {
namespace problem_1594 {

using Func = std::function<int(vector<vector<int>>&)>;

class MaximumNonNegativeProductInAMatrixSolution : public SolutionBase<Func> {
 public:
  //! 1594. Maximum Non Negative Product in a Matrix
  //! https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
  int maxProductPath(vector<vector<int>>& grid);

  MaximumNonNegativeProductInAMatrixSolution();
};

}  // namespace problem_1594
}  // namespace leetcode
