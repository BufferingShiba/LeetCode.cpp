#ifndef LEETCODE_PROBLEMS_SHORTEST_SUBARRAY_WITH_OR_AT_LEAST_K_I_H
#define LEETCODE_PROBLEMS_SHORTEST_SUBARRAY_WITH_OR_AT_LEAST_K_I_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3095 {

using Func = std::function<int(std::vector<int>&, int)>;

class ShortestSubarrayWithOrAtLeastKISolution : public SolutionBase<Func> {
 public:
  ShortestSubarrayWithOrAtLeastKISolution();

  int minimumSubarrayLength(std::vector<int>& nums, int k);
};

}  // namespace problem_3095
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SHORTEST_SUBARRAY_WITH_OR_AT_LEAST_K_I_H
