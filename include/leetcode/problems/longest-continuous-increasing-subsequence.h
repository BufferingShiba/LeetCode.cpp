#ifndef LEETCODE_PROBLEMS_LONGEST_CONTINUOUS_INCREASING_SUBSEQUENCE_H__
#define LEETCODE_PROBLEMS_LONGEST_CONTINUOUS_INCREASING_SUBSEQUENCE_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_674 {

using Func = std::function<int(std::vector<int>&)>;

class LongestContinuousIncreasingSubsequenceSolution
    : public SolutionBase<Func> {
 public:
  LongestContinuousIncreasingSubsequenceSolution();

  int findLengthOfLCIS(std::vector<int>& nums) {
    return getSolution()(nums);
  }
};

}  // namespace problem_674
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_CONTINUOUS_INCREASING_SUBSEQUENCE_H__
