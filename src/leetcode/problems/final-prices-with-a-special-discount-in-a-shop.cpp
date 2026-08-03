#include "leetcode/problems/final-prices-with-a-special-discount-in-a-shop.h"

#include <stack>
#include <vector>

namespace leetcode::problem_1475 {

namespace {

std::vector<int> finalPricesMonotonicStack(std::vector<int>& prices) {
  const int n = static_cast<int>(prices.size());
  std::vector<int> answer = prices;
  std::stack<int> st;
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && st.top() > prices[i]) {
      st.pop();
    }
    if (!st.empty()) {
      answer[i] -= st.top();
    }
    st.push(prices[i]);
  }
  return answer;
}

}  // namespace

FinalPricesWithASpecialDiscountInAShopSolution::
    FinalPricesWithASpecialDiscountInAShopSolution() {
  setMetaInfo({.id = 1475,
               .title = "Final Prices With a Special Discount in a Shop",
               .url = "https://leetcode.com/problems/final-prices-with-a-special-"
                       "discount-in-a-shop/"});
  registerStrategy(
      {.name = "MonotonicStack",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Stack", "Monotonic Stack"}},
      finalPricesMonotonicStack);
}

std::vector<int> FinalPricesWithASpecialDiscountInAShopSolution::finalPrices(
    std::vector<int>& prices) {
  return getSolution()(prices);
}

}  // namespace leetcode::problem_1475
