#ifndef LEETCODE_PROBLEM_LONGEST_SUBARRAY_OF_1S_AFTER_DELETING_ONE_ELEMENT_H_
#define LEETCODE_PROBLEM_LONGEST_SUBARRAY_OF_1S_AFTER_DELETING_ONE_ELEMENT_H_

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1493 {

using Func = std::function<int(std::vector<int>&)>;

class LongestSubarrayOf1sAfterDeletingOneElementSolution : public SolutionBase<Func> {
 public:
  LongestSubarrayOf1sAfterDeletingOneElementSolution();

  int longestSubarray(std::vector<int>& nums);
};

}  // namespace problem_1493
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_LONGEST_SUBARRAY_OF_1S_AFTER_DELETING_ONE_ELEMENT_H_
