#pragma once

#include "leetcode/core.h"

namespace leetcode::problem_2398 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&, long long)>;

class MaximumNumberOfRobotsWithinBudgetSolution : public SolutionBase<Func> {
 public:
  MaximumNumberOfRobotsWithinBudgetSolution();

  int maximumRobots(std::vector<int>& chargeTimes,
                    std::vector<int>& runningCosts,
                    long long budget);
};

}  // namespace leetcode::problem_2398
