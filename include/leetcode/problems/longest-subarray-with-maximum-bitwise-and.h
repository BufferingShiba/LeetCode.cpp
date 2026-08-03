#ifndef LEETCODE_PROBLEMS_LONGEST_SUBARRAY_WITH_MAXIMUM_BITWISE_AND_H__
#define LEETCODE_PROBLEMS_LONGEST_SUBARRAY_WITH_MAXIMUM_BITWISE_AND_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2419 {

using Func = std::function<int(std::vector<int>&)>;

class LongestSubarrayWithMaximumBitwiseAndSolution
    : public SolutionBase<Func> {
public:
    LongestSubarrayWithMaximumBitwiseAndSolution();

    int longestSubarray(std::vector<int>& nums);
};

}  // namespace problem_2419
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_SUBARRAY_WITH_MAXIMUM_BITWISE_AND_H__
