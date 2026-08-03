#ifndef LEETCODE_PROBLEMS_BURST_BALLOONS_H__
#define LEETCODE_PROBLEMS_BURST_BALLOONS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_312 {

using Func = std::function<int(std::vector<int>&)>;

class BurstBalloonsSolution : public SolutionBase<Func> {
 public:
  BurstBalloonsSolution();

  int maxCoins(std::vector<int>& nums);
};

}  // namespace leetcode::problem_312

#endif  // LEETCODE_PROBLEMS_BURST_BALLOONS_H__
