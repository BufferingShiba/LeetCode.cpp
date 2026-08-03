#ifndef LEETCODE_PROBLEMS_MAXIMUM_UNITS_ON_A_TRUCK_H__
#define LEETCODE_PROBLEMS_MAXIMUM_UNITS_ON_A_TRUCK_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1710 {

using Func = std::function<int(std::vector<std::vector<int>>&, int)>;

class MaximumUnitsOnATruck : public SolutionBase<Func> {
 public:
  MaximumUnitsOnATruck();

  int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize);
};

}  // namespace leetcode::problem_1710

#endif  // LEETCODE_PROBLEMS_MAXIMUM_UNITS_ON_A_TRUCK_H__
