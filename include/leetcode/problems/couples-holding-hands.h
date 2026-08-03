#ifndef LEETCODE_PROBLEMS_COUPLES_HOLDING_HANDS_H_
#define LEETCODE_PROBLEMS_COUPLES_HOLDING_HANDS_H_

#include "leetcode/core.h"

namespace leetcode::problem_765 {

using Func = std::function<int(std::vector<int>&)>;

class CouplesHoldingHandsSolution : public SolutionBase<Func> {
 public:
  CouplesHoldingHandsSolution();
  int minSwapsCouples(std::vector<int>& row);
};

}  // namespace leetcode::problem_765

#endif  // LEETCODE_PROBLEMS_COUPLES_HOLDING_HANDS_H_
