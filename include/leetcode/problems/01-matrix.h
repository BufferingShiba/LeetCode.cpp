#include "leetcode/core.h"

namespace leetcode {
namespace problem_542 {

using Func = std::function<vector<vector<int>>(vector<vector<int>>&)>;

class Problem01MatrixSolution : public SolutionBase<Func> {
 public:
  //! 542. 01 Matrix
  //! https://leetcode.com/problems/01-matrix/
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat);

  Problem01MatrixSolution();
};

}  // namespace problem_542
}  // namespace leetcode
