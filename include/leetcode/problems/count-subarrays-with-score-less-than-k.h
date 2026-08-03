#ifndef LEETCODE_PROBLEMS_COUNT_SUBARRAYS_WITH_SCORE_LESS_THAN_K_H_
#define LEETCODE_PROBLEMS_COUNT_SUBARRAYS_WITH_SCORE_LESS_THAN_K_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2302 {

using Func = std::function<long long(std::vector<int>&, long long)>;

class CountSubarraysWithScoreLessThanKSolution : public SolutionBase<Func> {
 public:
  CountSubarraysWithScoreLessThanKSolution();

  long long countSubarrays(std::vector<int>& nums, long long k);
};

}  // namespace leetcode::problem_2302

#endif  // LEETCODE_PROBLEMS_COUNT_SUBARRAYS_WITH_SCORE_LESS_THAN_K_H_
