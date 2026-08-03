#include "leetcode/problems/minimum-money-required-before-transactions.h"

#include <algorithm>

namespace leetcode {
namespace problem_2412 {

static long long minimumMoneyImpl(std::vector<std::vector<int>>& transactions) {
  long long total_net_loss = 0;
  long long max_cashback_loss = 0;
  long long max_cost_gain = 0;

  for (const auto& t : transactions) {
    int cost = t[0];
    int cashback = t[1];
    if (cost > cashback) {
      total_net_loss += (static_cast<long long>(cost) - cashback);
      if (cashback > max_cashback_loss) {
        max_cashback_loss = cashback;
      }
    } else {
      if (cost > max_cost_gain) {
        max_cost_gain = cost;
      }
    }
  }

  return total_net_loss + std::max(max_cashback_loss, max_cost_gain);
}

MinimumMoneyRequiredBeforeTransactionsSolution::MinimumMoneyRequiredBeforeTransactionsSolution() {
  setMetaInfo({.id = 2412,
               .title = "Minimum Money Required Before Transactions",
               .url = "https://leetcode.com/problems/minimum-money-required-before-transactions/"});

  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy"}},
      minimumMoneyImpl);
}

long long MinimumMoneyRequiredBeforeTransactionsSolution::minimumMoney(
    std::vector<std::vector<int>>& transactions) {
  return getSolution()(transactions);
}

}  // namespace problem_2412
}  // namespace leetcode