#ifndef LEETCODE_PROBLEMS_MAXIMUM_SCORE_USING_EXACTLY_K_PAIRS_H_
#define LEETCODE_PROBLEMS_MAXIMUM_SCORE_USING_EXACTLY_K_PAIRS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3836 {

using Func = std::function<long long(std::vector<int>&, std::vector<int>&, int)>;

class MaximumScoreUsingExactlyKPairsSolution : public SolutionBase<Func> {
 public:
  MaximumScoreUsingExactlyKPairsSolution();

  long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k);
};

}  // namespace problem_3836
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SCORE_USING_EXACTLY_K_PAIRS_H_
