#ifndef LEETCODE_PROBLEMS_LONGEST_ALTERNATING_SUBARRAY_AFTER_REMOVING_AT_MOST_ONE_ELEMENT_H__
#define LEETCODE_PROBLEMS_LONGEST_ALTERNATING_SUBARRAY_AFTER_REMOVING_AT_MOST_ONE_ELEMENT_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3830 {

using Func = std::function<int(std::vector<int>&)>;

class LongestAlternatingSubarrayAfterRemovingAtMostOneElementSolution
    : public SolutionBase<Func> {
 public:
  LongestAlternatingSubarrayAfterRemovingAtMostOneElementSolution();

  int longestAlternating(std::vector<int>& nums);
};

}  // namespace problem_3830
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_ALTERNATING_SUBARRAY_AFTER_REMOVING_AT_MOST_ONE_ELEMENT_H__
