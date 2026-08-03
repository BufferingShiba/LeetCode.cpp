#ifndef LEETCODE_PROBLEMS_BEST_TIME_TO_BUY_AND_SELL_STOCK_H__
#define LEETCODE_PROBLEMS_BEST_TIME_TO_BUY_AND_SELL_STOCK_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_121 {

using Func = std::function<int(std::vector<int>&)>;

class BestTimeToBuyAndSellStockSolution
    : public SolutionBase<Func> {
 public:
  BestTimeToBuyAndSellStockSolution();

  int maxProfit(std::vector<int>& prices);
};

}  // namespace leetcode::problem_121

#endif  // LEETCODE_PROBLEMS_BEST_TIME_TO_BUY_AND_SELL_STOCK_H__
