#include "leetcode/problems/buy-two-chocolates.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_2706 {
namespace {

int buyChocoImpl(std::vector<int>& prices, int money) {
  const int n = static_cast<int>(prices.size());
  int min1 = prices[0], min2 = prices[1];
  if (min1 > min2) std::swap(min1, min2);
  for (int i = 2; i < n; ++i) {
    if (prices[i] < min1) {
      min2 = min1;
      min1 = prices[i];
    } else if (prices[i] < min2) {
      min2 = prices[i];
    }
  }
  const int sum = min1 + min2;
  return sum <= money ? money - sum : money;
}

}  // namespace

BuyTwoChocolatesSolution::BuyTwoChocolatesSolution() {
  setMetaInfo({.id = 2706,
               .title = "Buy Two Chocolates",
               .url =
                   "https://leetcode.com/problems/buy-two-chocolates/"});
  registerStrategy(
      {.name = "TwoSmallest",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy", "Sorting"}},
      buyChocoImpl);
}

int BuyTwoChocolatesSolution::buyChoco(std::vector<int>& prices, int money) {
  return getSolution()(prices, money);
}

}  // namespace leetcode::problem_2706
