#include "leetcode/problems/richest-customer-wealth.h"

namespace leetcode {
namespace problem_1672 {

namespace {

int maximumWealthImpl(std::vector<std::vector<int>>& accounts) {
  int best = 0;
  for (const auto& customer : accounts) {
    int wealth = 0;
    for (int money : customer) {
      wealth += money;
    }
    if (wealth > best) {
      best = wealth;
    }
  }
  return best;
}

}  // namespace

RichestCustomerWealthSolution::RichestCustomerWealthSolution() {
  setMetaInfo({.id = 1672,
               .title = "Richest Customer Wealth",
               .url = "https://leetcode.com/problems/richest-customer-wealth/"});

  registerStrategy({.name = "LinearScan",
                    .expected = "Accepted",
                    .time_complexity = "O(m*n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Matrix"}},
                   maximumWealthImpl);
}

int RichestCustomerWealthSolution::maximumWealth(
    std::vector<std::vector<int>>& accounts) {
  return getSolution()(accounts);
}

}  // namespace problem_1672
}  // namespace leetcode
