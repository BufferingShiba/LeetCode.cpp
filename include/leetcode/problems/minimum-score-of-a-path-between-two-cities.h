#include "leetcode/core.h"

namespace leetcode {
namespace problem_2492 {

using Func = std::function<int(int, vector<vector<int>>&)>;

class MinimumScoreOfAPathBetweenTwoCitiesSolution : public SolutionBase<Func> {
 public:
  //! 2492. Minimum Score of a Path Between Two Cities
  //! https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
  int minScore(int n, vector<vector<int>>& roads);

  MinimumScoreOfAPathBetweenTwoCitiesSolution();
};

}  // namespace problem_2492
}  // namespace leetcode
