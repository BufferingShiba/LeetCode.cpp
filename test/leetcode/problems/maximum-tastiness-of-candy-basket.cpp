#include "leetcode/problems/maximum-tastiness-of-candy-basket.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2517 {

class MaximumTastinessOfCandyBasketTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumTastinessOfCandyBasketSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  price = [13,5,1,8,21,2], k = 3
// Output: 8
TEST_P(MaximumTastinessOfCandyBasketTest, OfficialExample1) {
  std::vector<int> price = {13, 5, 1, 8, 21, 2};
  int k = 3;
  int result = solution.maximumTastiness(price, k);
  EXPECT_EQ(8, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  price = [1,3,1], k = 2
// Output: 2
TEST_P(MaximumTastinessOfCandyBasketTest, OfficialExample2) {
  std::vector<int> price = {1, 3, 1};
  int k = 2;
  int result = solution.maximumTastiness(price, k);
  EXPECT_EQ(2, result);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  price = [7,7,7,7], k = 2
// Output: 0
TEST_P(MaximumTastinessOfCandyBasketTest, OfficialExample3) {
  std::vector<int> price = {7, 7, 7, 7};
  int k = 2;
  int result = solution.maximumTastiness(price, k);
  EXPECT_EQ(0, result);
}

// Pick all candies: tastiness is min adjacent difference in sorted order.
// Sorted {1,4,9,13,32}: adjacent diffs 3,5,4,19 -> min = 3.
TEST_P(MaximumTastinessOfCandyBasketTest, SelfAuthoredPickAll) {
  std::vector<int> price = {4, 9, 1, 32, 13};
  int k = 5;
  int result = solution.maximumTastiness(price, k);
  EXPECT_EQ(3, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximumTastinessOfCandyBasketTest,
    ::testing::ValuesIn(MaximumTastinessOfCandyBasketSolution().getStrategyNames()));

}  // namespace problem_2517
}  // namespace leetcode
