#ifndef LEETCODE_PROBLEMS_MINIMUM_SIZE_SUBARRAY_IN_INFINITE_ARRAY_H_
#define LEETCODE_PROBLEMS_MINIMUM_SIZE_SUBARRAY_IN_INFINITE_ARRAY_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2875 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumSizeSubarrayInInfiniteArraySolution : public SolutionBase<Func> {
 public:
  MinimumSizeSubarrayInInfiniteArraySolution();

  int minSizeSubarray(std::vector<int>& nums, int target);
};

}  // namespace problem_2875
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_SIZE_SUBARRAY_IN_INFINITE_ARRAY_H_
