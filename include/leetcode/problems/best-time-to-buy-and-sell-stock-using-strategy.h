#ifndef LEETCODE_PROBLEMS_BEST_TIME_TO_BUY_AND_SELL_STOCK_USING_STRATEGY_H_
#define LEETCODE_PROBLEMS_BEST_TIME_TO_BUY_AND_SELL_STOCK_USING_STRATEGY_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3652 {

using Func = std::function<long long(std::vector<int>&, std::vector<int>&, int)>;

class BestTimeToBuyAndSellStockUsingStrategySolution : public SolutionBase<Func> {
 public:
  BestTimeToBuyAndSellStockUsingStrategySolution();

  long long maxProfit(std::vector<int>& prices, std::vector<int>& strategy, int k);
};

}  // namespace problem_3652
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BEST_TIME_TO_BUY_AND_SELL_STOCK_USING_STRATEGY_H_
