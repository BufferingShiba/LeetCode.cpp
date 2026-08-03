#include "leetcode/core.h"

namespace leetcode {
namespace problem_3281 {

using Func = std::function<int(vector<int>&, int)>;

class MaximizeScoreOfNumbersInRangesSolution : public SolutionBase<Func> {
 public:
  //! 3281. Maximize Score of Numbers in Ranges
  //! https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/
  int maxPossibleScore(vector<int>& start, int d);

  MaximizeScoreOfNumbersInRangesSolution();
};

}  // namespace problem_3281
}  // namespace leetcode
