#ifndef LEETCODE_PROBLEMS_MAXIMUM_TOTAL_REWARD_USING_OPERATIONS_II_H__
#define LEETCODE_PROBLEMS_MAXIMUM_TOTAL_REWARD_USING_OPERATIONS_II_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3181 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumTotalRewardUsingOperationsIiSolution
    : public SolutionBase<Func> {
 public:
  MaximumTotalRewardUsingOperationsIiSolution();

  int maxTotalReward(std::vector<int>& rewardValues);
};

}  // namespace problem_3181
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_TOTAL_REWARD_USING_OPERATIONS_II_H__
