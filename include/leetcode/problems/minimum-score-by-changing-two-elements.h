#ifndef LEETCODE_PROBLEMS_MINIMUM_SCORE_BY_CHANGING_TWO_ELEMENTS_H_
#define LEETCODE_PROBLEMS_MINIMUM_SCORE_BY_CHANGING_TWO_ELEMENTS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2567 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumScoreByChangingTwoElementsSolution : public SolutionBase<Func> {
 public:
  int minimizeSum(std::vector<int>& nums);

  MinimumScoreByChangingTwoElementsSolution();
};

}  // namespace problem_2567
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_SCORE_BY_CHANGING_TWO_ELEMENTS_H_
