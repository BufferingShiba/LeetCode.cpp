#include "leetcode/core.h"

namespace leetcode {
namespace problem_2857 {

using Func = std::function<int(vector<vector<int>>&, int)>;

class CountPairsOfPointsWithDistanceKSolution : public SolutionBase<Func> {
 public:
  //! 2857. Count Pairs of Points With Distance k
  //! https://leetcode.com/problems/count-pairs-of-points-with-distance-k/
  int countPairs(vector<vector<int>>& coordinates, int k);

  CountPairsOfPointsWithDistanceKSolution();
};

}  // namespace problem_2857
}  // namespace leetcode
