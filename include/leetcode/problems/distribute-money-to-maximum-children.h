#ifndef LEETCODE_PROBLEMS_DISTRIBUTE_MONEY_TO_MAXIMUM_CHILDREN_H__
#define LEETCODE_PROBLEMS_DISTRIBUTE_MONEY_TO_MAXIMUM_CHILDREN_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2591 {

using Func = std::function<int(int, int)>;

class DistributeMoneyToMaximumChildrenSolution
    : public SolutionBase<Func> {
 public:
  DistributeMoneyToMaximumChildrenSolution();

  int distMoney(int money, int children);
};

}  // namespace problem_2591
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DISTRIBUTE_MONEY_TO_MAXIMUM_CHILDREN_H__
