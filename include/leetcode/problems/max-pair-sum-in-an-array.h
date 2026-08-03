#ifndef LEETCODE_PROBLEMS_MAX_PAIR_SUM_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_MAX_PAIR_SUM_IN_AN_ARRAY_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2815 {

using Func = std::function<int(std::vector<int>&)>;

class MaxPairSumInAnArraySolution : public SolutionBase<Func> {
 public:
  MaxPairSumInAnArraySolution();
  int maxSum(std::vector<int>& nums);
};

}  // namespace problem_2815
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAX_PAIR_SUM_IN_AN_ARRAY_H__
