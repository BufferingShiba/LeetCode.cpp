#ifndef LEETCODE_PROBLEMS_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_COOLDOWN_H_
#define LEETCODE_PROBLEMS_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_COOLDOWN_H_

#include "leetcode/core.h"

namespace leetcode::problem_309 {

using Func = std::function<int(std::vector<int>&)>;

class BestTimeToBuyAndSellStockWithCooldownSolution : public SolutionBase<Func> {
 public:
  int maxProfit(std::vector<int>& prices);

  BestTimeToBuyAndSellStockWithCooldownSolution();
};

}  // namespace leetcode::problem_309

#endif  // LEETCODE_PROBLEMS_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_COOLDOWN_H_
