#ifndef LEETCODE_PROBLEMS_CLIMBING_STAIRS_II_H_
#define LEETCODE_PROBLEMS_CLIMBING_STAIRS_II_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3693 {

using Func = std::function<int(int, std::vector<int>&)>;

class ClimbingStairsIiSolution : public SolutionBase<Func> {
 public:
  ClimbingStairsIiSolution();

  int climbStairs(int n, std::vector<int>& costs);
};

}  // namespace problem_3693
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CLIMBING_STAIRS_II_H_
