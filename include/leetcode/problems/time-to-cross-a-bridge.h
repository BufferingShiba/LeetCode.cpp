#ifndef LEETCODE_PROBLEMS_TIME_TO_CROSS_A_BRIDGE_H__
#define LEETCODE_PROBLEMS_TIME_TO_CROSS_A_BRIDGE_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2532 {

using Func = std::function<int(int, int, std::vector<std::vector<int>>&)>;

class TimeToCrossABridgeSolution : public SolutionBase<Func> {
 public:
  TimeToCrossABridgeSolution();

  int findCrossingTime(int n, int k, std::vector<std::vector<int>>& time);
};

}  // namespace problem_2532
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TIME_TO_CROSS_A_BRIDGE_H__
