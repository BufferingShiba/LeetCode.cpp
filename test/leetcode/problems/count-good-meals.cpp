#include "leetcode/problems/count-good-meals.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_1711 {
namespace {

class CountGoodMealsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountGoodMealsSolution solution;
};

TEST_P(CountGoodMealsTest, Example1) {
  std::vector<int> deliciousness = {1, 3, 5, 7, 9};
  EXPECT_EQ(solution.countPairs(deliciousness), 4);
}

TEST_P(CountGoodMealsTest, Example2) {
  std::vector<int> deliciousness = {1, 1, 1, 3, 3, 3, 7};
  EXPECT_EQ(solution.countPairs(deliciousness), 15);
}

TEST_P(CountGoodMealsTest, SelfAuthoredSingleElement) {
  std::vector<int> deliciousness = {5};
  EXPECT_EQ(solution.countPairs(deliciousness), 0);
}

TEST_P(CountGoodMealsTest, SelfAuthoredBothZero) {
  const int n = 3;
  std::vector<int> deliciousness(n, 0);
  // 0 + 0 = 0 = 2^?; 2^0 = 1, but 0 is not a power of two.
  // So no valid pairs here.
  EXPECT_EQ(solution.countPairs(deliciousness), 0);
}

INSTANTIATE_TEST_SUITE_P(
    CountGoodMealsTestSuite, CountGoodMealsTest,
    ::testing::ValuesIn(CountGoodMealsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1711
}  // namespace leetcode
