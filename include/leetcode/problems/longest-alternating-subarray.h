#ifndef LEETCODE_PROBLEMS_LONGEST_ALTERNATING_SUBARRAY_H__
#define LEETCODE_PROBLEMS_LONGEST_ALTERNATING_SUBARRAY_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2765 {

using Func = std::function<int(std::vector<int>&)>;

class LongestAlternatingSubarraySolution
    : public SolutionBase<Func> {
 public:
  LongestAlternatingSubarraySolution();
  int alternatingSubarray(std::vector<int>& nums);
};

}  // namespace problem_2765
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_ALTERNATING_SUBARRAY_H__
