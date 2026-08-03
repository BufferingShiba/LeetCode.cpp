#ifndef LEETCODE_PROBLEMS_LONGEST_STRICTLY_INCREASING_OR_STRICTLY_DECREASING_SUBARRAY_H__
#define LEETCODE_PROBLEMS_LONGEST_STRICTLY_INCREASING_OR_STRICTLY_DECREASING_SUBARRAY_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3105 {

using Func = std::function<int(std::vector<int>&)>;

class LongestStrictlyIncreasingOrStrictlyDecreasingSubarraySolution
    : public SolutionBase<Func> {
 public:
  LongestStrictlyIncreasingOrStrictlyDecreasingSubarraySolution();

  int longestMonotonicSubarray(std::vector<int>& nums);
};

}  // namespace problem_3105
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_STRICTLY_INCREASING_OR_STRICTLY_DECREASING_SUBARRAY_H__
