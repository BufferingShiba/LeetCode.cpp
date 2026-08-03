#ifndef LEETCODE_PROBLEM_2871_H_
#define LEETCODE_PROBLEM_2871_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2871 {

using Func = std::function<int(std::vector<int>&)>;

class SplitArrayIntoMaximumNumberOfSubarraysSolution : public SolutionBase<Func> {
 public:
  SplitArrayIntoMaximumNumberOfSubarraysSolution();

  int maxSubarrays(std::vector<int>& nums);
};

}  // namespace problem_2871
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2871_H_
