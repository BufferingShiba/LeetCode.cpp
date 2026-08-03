#ifndef LEETCODE_PROBLEMS_ADJACENT_INCREASING_SUBARRAYS_DETECTION_I_H_
#define LEETCODE_PROBLEMS_ADJACENT_INCREASING_SUBARRAYS_DETECTION_I_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3349 {

using Func = std::function<bool(std::vector<int>&, int)>;

class AdjacentIncreasingSubarraysDetectionISolution : public SolutionBase<Func> {
 public:
  AdjacentIncreasingSubarraysDetectionISolution();

  bool hasIncreasingSubarrays(std::vector<int>& nums, int k);
};

}  // namespace problem_3349
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ADJACENT_INCREASING_SUBARRAYS_DETECTION_I_H_
