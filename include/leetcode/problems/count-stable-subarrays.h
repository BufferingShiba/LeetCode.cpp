#ifndef LEETCODE_PROBLEMS_COUNT_STABLE_SUBARRAYS_H_
#define LEETCODE_PROBLEMS_COUNT_STABLE_SUBARRAYS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3748 {

using Func = std::function<std::vector<long long>(std::vector<int>&, std::vector<std::vector<int>>&)>;

class CountStableSubarraysSolution : public SolutionBase<Func> {
 public:
  CountStableSubarraysSolution();

  std::vector<long long> countStableSubarrays(std::vector<int>& nums, std::vector<std::vector<int>>& queries);
};

}  // namespace problem_3748
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_STABLE_SUBARRAYS_H_
