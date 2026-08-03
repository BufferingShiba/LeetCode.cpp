#ifndef LEETCODE_PROBLEMS_3SUM_CLOSEST_H__
#define LEETCODE_PROBLEMS_3SUM_CLOSEST_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_16 {

using Func = std::function<int(std::vector<int>&, int)>;

class ThreeSumClosestSolution : public SolutionBase<Func> {
 public:
  ThreeSumClosestSolution();
  int threeSumClosest(std::vector<int>& nums, int target);
};

}  // namespace problem_16
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_3SUM_CLOSEST_H__
