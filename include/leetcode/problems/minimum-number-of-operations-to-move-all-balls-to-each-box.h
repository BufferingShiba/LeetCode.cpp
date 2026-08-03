#include "leetcode/core.h"

namespace leetcode {
namespace problem_1769 {

using Func = std::function<vector<int>(string)>;

class MinimumNumberOfOperationsToMoveAllBallsToEachBoxSolution : public SolutionBase<Func> {
 public:
  //! 1769. Minimum Number of Operations to Move All Balls to Each Box
  //! https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
  vector<int> minOperations(string boxes);

  MinimumNumberOfOperationsToMoveAllBallsToEachBoxSolution();
};

}  // namespace problem_1769
}  // namespace leetcode
