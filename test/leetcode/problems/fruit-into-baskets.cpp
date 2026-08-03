#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/fruit-into-baskets.h"

namespace leetcode {
namespace problem_904 {

namespace {

std::vector<int> makeFruits(std::initializer_list<int> values) {
  return std::vector<int>(values);
}

}  // namespace

class FruitIntoBasketsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FruitIntoBasketsSolution solution;
};

TEST_P(FruitIntoBasketsTest, Example1) {
  auto fruits = makeFruits({1, 2, 1});
  EXPECT_EQ(3, solution.totalFruit(fruits));
}

TEST_P(FruitIntoBasketsTest, Example2) {
  auto fruits = makeFruits({0, 1, 2, 2});
  EXPECT_EQ(3, solution.totalFruit(fruits));
}

TEST_P(FruitIntoBasketsTest, Example3) {
  auto fruits = makeFruits({1, 2, 3, 2, 2});
  EXPECT_EQ(4, solution.totalFruit(fruits));
}

TEST_P(FruitIntoBasketsTest, SelfAuthoredSingleElement) {
  auto fruits = makeFruits({5});
  EXPECT_EQ(1, solution.totalFruit(fruits));
}

TEST_P(FruitIntoBasketsTest, SelfAuthoredAllSameType) {
  auto fruits = makeFruits({7, 7, 7, 7, 7});
  EXPECT_EQ(5, solution.totalFruit(fruits));
}

TEST_P(FruitIntoBasketsTest, SelfAuthoredAlternatingTwoTypes) {
  auto fruits = makeFruits({3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4});
  EXPECT_EQ(5, solution.totalFruit(fruits));
}

INSTANTIATE_TEST_SUITE_P(
    FruitIntoBasketsTests, FruitIntoBasketsTest,
    ::testing::ValuesIn(FruitIntoBasketsSolution().getStrategyNames()));

}  // namespace problem_904
}  // namespace leetcode
