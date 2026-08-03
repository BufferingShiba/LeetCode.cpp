#ifndef LEETCODE_PROBLEMS_MIN_COST_CLIMBING_STAIRS_H__
#define LEETCODE_PROBLEMS_MIN_COST_CLIMBING_STAIRS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_746 {

using Func = std::function<int(std::vector<int>&)>;

class MinCostClimbingStairsSolution : public SolutionBase<Func> {
 public:
  MinCostClimbingStairsSolution();

  // Original problem method.
  int minCostClimbingStairs(std::vector<int>& cost);
};

}  // namespace problem_746
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MIN_COST_CLIMBING_STAIRS_H__
