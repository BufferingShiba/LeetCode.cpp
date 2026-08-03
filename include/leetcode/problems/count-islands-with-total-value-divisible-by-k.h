#include "leetcode/core.h"

namespace leetcode {
namespace problem_3619 {

using Func = std::function<int(vector<vector<int>>&, int)>;

class CountIslandsWithTotalValueDivisibleByKSolution : public SolutionBase<Func> {
 public:
  //! 3619. Count Islands With Total Value Divisible by K
  //! https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
  int countIslands(vector<vector<int>>& grid, int k);

  CountIslandsWithTotalValueDivisibleByKSolution();
};

}  // namespace problem_3619
}  // namespace leetcode
