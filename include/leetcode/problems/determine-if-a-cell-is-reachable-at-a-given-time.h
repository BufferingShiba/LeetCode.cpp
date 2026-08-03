#include "leetcode/core.h"

namespace leetcode {
namespace problem_2849 {

using Func = std::function<bool(int, int, int, int, int)>;

class DetermineIfACellIsReachableAtAGivenTimeSolution : public SolutionBase<Func> {
 public:
  //! 2849. Determine if a Cell Is Reachable at a Given Time
  //! https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/
  bool isReachableAtTime(int sx, int sy, int fx, int fy, int t);

  DetermineIfACellIsReachableAtAGivenTimeSolution();
};

}  // namespace problem_2849
}  // namespace leetcode
