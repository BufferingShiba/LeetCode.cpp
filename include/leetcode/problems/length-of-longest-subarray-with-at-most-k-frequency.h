#ifndef LEETCODE_PROBLEMS_LENGTH_OF_LONGEST_SUBARRAY_WITH_AT_MOST_K_FREQUENCY_H
#define LEETCODE_PROBLEMS_LENGTH_OF_LONGEST_SUBARRAY_WITH_AT_MOST_K_FREQUENCY_H

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2958 {

using Func = std::function<int(std::vector<int>&, int)>;

class LengthOfLongestSubarrayWithAtMostKFrequencySolution
    : public SolutionBase<Func> {
 public:
  LengthOfLongestSubarrayWithAtMostKFrequencySolution();

  int maxSubarrayLength(std::vector<int>& nums, int k);
};

}  // namespace problem_2958
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LENGTH_OF_LONGEST_SUBARRAY_WITH_AT_MOST_K_FREQUENCY_H
