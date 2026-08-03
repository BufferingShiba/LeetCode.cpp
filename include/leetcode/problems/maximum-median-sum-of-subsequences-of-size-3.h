#include "leetcode/core.h"

namespace leetcode {
namespace problem_3627 {

using Func = std::function<long long(vector<int>&)>;

class MaximumMedianSumOfSubsequencesOfSize3Solution : public SolutionBase<Func> {
 public:
  //! 3627. Maximum Median Sum of Subsequences of Size 3
  //! https://leetcode.com/problems/maximum-median-sum-of-subsequences-of-size-3/
  long long maximumMedianSum(vector<int>& nums);

  MaximumMedianSumOfSubsequencesOfSize3Solution();
};

}  // namespace problem_3627
}  // namespace leetcode
