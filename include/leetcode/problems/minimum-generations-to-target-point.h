#ifndef LEETCODE_PROBLEMS_MINIMUM_GENERATIONS_TO_TARGET_POINT_H_
#define LEETCODE_PROBLEMS_MINIMUM_GENERATIONS_TO_TARGET_POINT_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3923 {

using Func = std::function<int(std::vector<std::vector<int>>&, std::vector<int>&)>;

class MinimumGenerationsToTargetPointSolution
    : public SolutionBase<Func> {
 public:
  MinimumGenerationsToTargetPointSolution();

  int minGenerations(std::vector<std::vector<int>>& points,
                     std::vector<int>& target) {
    return getSolution()(points, target);
  }
};

}  // namespace problem_3923
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_GENERATIONS_TO_TARGET_POINT_H_
