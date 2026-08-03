#ifndef LEETCODE_PROBLEMS_MAXIMIZE_SUBARRAYS_AFTER_REMOVING_ONE_CONFLICTING_PAIR_H_
#define LEETCODE_PROBLEMS_MAXIMIZE_SUBARRAYS_AFTER_REMOVING_ONE_CONFLICTING_PAIR_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3480 {

using Func = std::function<long long(int, std::vector<std::vector<int>>&)>;

class MaximizeSubarraysAfterRemovingOneConflictingPairSolution
    : public SolutionBase<Func> {
 public:
  MaximizeSubarraysAfterRemovingOneConflictingPairSolution();

  long long maxSubarrays(int n, std::vector<std::vector<int>>& conflictingPairs);
};

}  // namespace problem_3480
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMIZE_SUBARRAYS_AFTER_REMOVING_ONE_CONFLICTING_PAIR_H_
