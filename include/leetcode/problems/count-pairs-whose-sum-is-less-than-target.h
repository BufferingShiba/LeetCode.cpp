#ifndef LEETCODE_PROBLEMS_COUNT_PAIRS_WHOSE_SUM_IS_LESS_THAN_TARGET_H__
#define LEETCODE_PROBLEMS_COUNT_PAIRS_WHOSE_SUM_IS_LESS_THAN_TARGET_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_2824 {

using Func = std::function<int(std::vector<int>&, int)>;

class CountPairsWhoseSumIsLessThanTargetSolution : public SolutionBase<Func> {
 public:
  CountPairsWhoseSumIsLessThanTargetSolution();

  int countPairs(std::vector<int>& nums, int target);
};

}  // namespace problem_2824
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_PAIRS_WHOSE_SUM_IS_LESS_THAN_TARGET_H__
