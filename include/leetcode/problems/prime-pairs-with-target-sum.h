#include "leetcode/core.h"

namespace leetcode {
namespace problem_2761 {

using Func = std::function<vector<vector<int>>(int)>;

class PrimePairsWithTargetSumSolution : public SolutionBase<Func> {
 public:
  //! 2761. Prime Pairs With Target Sum
  //! https://leetcode.com/problems/prime-pairs-with-target-sum/
  vector<vector<int>> findPrimePairs(int n);

  PrimePairsWithTargetSumSolution();
};

}  // namespace problem_2761
}  // namespace leetcode
