#include "leetcode/core.h"

namespace leetcode {
namespace problem_1292 {

using Func = std::function<int(vector<vector<int>>&, int)>;

class MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdSolution : public SolutionBase<Func> {
 public:
  //! 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
  //! https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
  int maxSideLength(vector<vector<int>>& mat, int threshold);

  MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdSolution();
};

}  // namespace problem_1292
}  // namespace leetcode