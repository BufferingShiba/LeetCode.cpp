#include "leetcode/core.h"

namespace leetcode {
namespace problem_70 {

using Func = std::function<int(int)>;

class ClimbingStairsSolution : public SolutionBase<Func> {
 public:
  //! 70. Climbing Stairs
  //! https://leetcode.com/problems/climbing-stairs/
  int climbStairs(int n);

  ClimbingStairsSolution();
};

}  // namespace problem_70
}  // namespace leetcode
