#ifndef LEETCODE_PROBLEMS_BUY_TWO_CHOCOLATES_H__
#define LEETCODE_PROBLEMS_BUY_TWO_CHOCOLATES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2706 {

using Func = std::function<int(std::vector<int>&, int)>;

class BuyTwoChocolatesSolution : public SolutionBase<Func> {
 public:
  BuyTwoChocolatesSolution();

  int buyChoco(std::vector<int>& prices, int money);
};

}  // namespace leetcode::problem_2706

#endif  // LEETCODE_PROBLEMS_BUY_TWO_CHOCOLATES_H__
