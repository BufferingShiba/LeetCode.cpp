#ifndef LEETCODE_PROBLEMS_SHORTEST_SUBARRAY_WITH_SUM_AT_LEAST_K_H__
#define LEETCODE_PROBLEMS_SHORTEST_SUBARRAY_WITH_SUM_AT_LEAST_K_H__

#include <deque>
#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_862 {

using Func = std::function<int(std::vector<int>&, int)>;

class ShortestSubarrayWithSumAtLeastKSolution
    : public SolutionBase<Func> {
 public:
  ShortestSubarrayWithSumAtLeastKSolution();

  int shortestSubarray(std::vector<int>& nums, int k);
};

}  // namespace problem_862
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SHORTEST_SUBARRAY_WITH_SUM_AT_LEAST_K_H__
