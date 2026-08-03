#ifndef LEETCODE_PROBLEM_MAXIMUM_SCORE_OF_A_GOOD_SUBARRAY_H
#define LEETCODE_PROBLEM_MAXIMUM_SCORE_OF_A_GOOD_SUBARRAY_H

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1793 {

using Func = std::function<int(std::vector<int>&, int)>;

class MaximumScoreOfAGoodSubarraySolution : public SolutionBase<Func> {
public:
  int maximumScore(std::vector<int>& nums, int k);

  MaximumScoreOfAGoodSubarraySolution();
};

} // namespace problem_1793
} // namespace leetcode

#endif
