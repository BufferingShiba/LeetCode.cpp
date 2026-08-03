#ifndef LEETCODE_PROBLEMS_MAXIMUM_PROFIT_OF_OPERATING_A_CENTENNIAL_WHEEL_H_
#define LEETCODE_PROBLEMS_MAXIMUM_PROFIT_OF_OPERATING_A_CENTENNIAL_WHEEL_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1599 {

using Func = std::function<int(std::vector<int>&, int, int)>;

class MaximumProfitOfOperatingACentennialWheelSolution : public SolutionBase<Func> {
 public:
  MaximumProfitOfOperatingACentennialWheelSolution();

  int minOperationsMaxProfit(std::vector<int>& customers, int boardingCost,
                              int runningCost);
};

}  // namespace leetcode::problem_1599

#endif  // LEETCODE_PROBLEMS_MAXIMUM_PROFIT_OF_OPERATING_A_CENTENNIAL_WHEEL_H_
