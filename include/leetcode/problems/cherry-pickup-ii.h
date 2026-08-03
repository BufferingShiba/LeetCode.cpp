#ifndef LEETCODE_PROBLEMS_CHERRY_PICKUP_II_H__
#define LEETCODE_PROBLEMS_CHERRY_PICKUP_II_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1463 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class CherryPickupIiSolution : public SolutionBase<Func> {
 public:
  CherryPickupIiSolution();
  int cherryPickup(std::vector<std::vector<int>>& grid);
};

}  // namespace leetcode::problem_1463

#endif  // LEETCODE_PROBLEMS_CHERRY_PICKUP_II_H__
