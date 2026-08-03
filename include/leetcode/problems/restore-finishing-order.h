#ifndef LEETCODE_PROBLEMS_RESTORE_FINISHING_ORDER_H__
#define LEETCODE_PROBLEMS_RESTORE_FINISHING_ORDER_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3668 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<int>&)>;

class RestoreFinishingOrderSolution : public SolutionBase<Func> {
 public:
  RestoreFinishingOrderSolution();
  std::vector<int> recoverOrder(std::vector<int>& order, std::vector<int>& friends);
};

}  // namespace leetcode::problem_3668

#endif  // LEETCODE_PROBLEMS_RESTORE_FINISHING_ORDER_H__
