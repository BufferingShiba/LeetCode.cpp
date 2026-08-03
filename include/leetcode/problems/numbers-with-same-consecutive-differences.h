#include "leetcode/core.h"

namespace leetcode {
namespace problem_967 {

using Func = std::function<vector<int>(int, int)>;

class NumbersWithSameConsecutiveDifferencesSolution : public SolutionBase<Func> {
 public:
  //! 967. Numbers With Same Consecutive Differences
  //! https://leetcode.com/problems/numbers-with-same-consecutive-differences/
  vector<int> numsSameConsecDiff(int n, int k);

  NumbersWithSameConsecutiveDifferencesSolution();
};

}  // namespace problem_967
}  // namespace leetcode
