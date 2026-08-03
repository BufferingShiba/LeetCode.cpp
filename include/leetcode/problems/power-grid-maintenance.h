#ifndef LEETCODE_PROBLEMS_POWER_GRID_MAINTENANCE_H__
#define LEETCODE_PROBLEMS_POWER_GRID_MAINTENANCE_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3607 {

class PowerGridMaintenanceSolution
    : public SolutionBase<std::function<std::vector<int>(
          int, std::vector<std::vector<int>>&, std::vector<std::vector<int>>&)>> {
 public:
  using Func = std::function<std::vector<int>(
      int, std::vector<std::vector<int>>&, std::vector<std::vector<int>>&)>;

  PowerGridMaintenanceSolution();

  std::vector<int> processQueries(int c, std::vector<std::vector<int>>& connections,
                                  std::vector<std::vector<int>>& queries);
};

}  // namespace leetcode::problem_3607

#endif  // LEETCODE_PROBLEMS_POWER_GRID_MAINTENANCE_H__
