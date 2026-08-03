#ifndef LEETCODE_PROBLEMS_LONGEST_EVEN_ODD_SUBARRAY_WITH_THRESHOLD_H__
#define LEETCODE_PROBLEMS_LONGEST_EVEN_ODD_SUBARRAY_WITH_THRESHOLD_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2760 {

using Func = std::function<int(std::vector<int>&, int)>;

class LongestEvenOddSubarrayWithThresholdSolution
    : public SolutionBase<Func> {
 public:
  LongestEvenOddSubarrayWithThresholdSolution();

  int longestAlternatingSubarray(std::vector<int>& nums, int threshold);
};

}  // namespace problem_2760
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_EVEN_ODD_SUBARRAY_WITH_THRESHOLD_H__
