#ifndef LEETCODE_PROBLEMS_LONGEST_FIBONACCI_SUBARRAY_H__
#define LEETCODE_PROBLEMS_LONGEST_FIBONACCI_SUBARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3708 {

using Func = std::function<int(std::vector<int>&)>;

class LongestFibonacciSubarraySolution : public SolutionBase<Func> {
 public:
  LongestFibonacciSubarraySolution();

  int longestSubarray(std::vector<int>& nums);
};

}  // namespace problem_3708
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_FIBONACCI_SUBARRAY_H__
