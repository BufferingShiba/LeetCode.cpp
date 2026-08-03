#pragma once

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_3977 {

using Func = std::function<std::vector<long long>(int, std::vector<std::vector<int>>&, int, std::vector<int>&, int, int)>;

class MinimumTimeToReachTargetWithLimitedPowerSolution : public SolutionBase<Func> {
 public:
  MinimumTimeToReachTargetWithLimitedPowerSolution();

  std::vector<long long> minTimeMaxPower(int n, std::vector<std::vector<int>>& edges, int power,
                                         std::vector<int>& cost, int source, int target);
};

}  // namespace leetcode::problem_3977
