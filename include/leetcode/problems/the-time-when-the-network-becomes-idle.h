#ifndef LEETCODE_PROBLEMS_THE_TIME_WHEN_THE_NETWORK_BECOMES_IDLE_H__
#define LEETCODE_PROBLEMS_THE_TIME_WHEN_THE_NETWORK_BECOMES_IDLE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2039 {

using Func = std::function<
    int(std::vector<std::vector<int>>&, std::vector<int>&)>;

class TheTimeWhenTheNetworkBecomesIdleSolution
    : public SolutionBase<Func> {
 public:
  int networkBecomesIdle(std::vector<std::vector<int>>& edges,
                         std::vector<int>& patience);

  TheTimeWhenTheNetworkBecomesIdleSolution();
};

}  // namespace leetcode::problem_2039

#endif  // LEETCODE_PROBLEMS_THE_TIME_WHEN_THE_NETWORK_BECOMES_IDLE_H__
