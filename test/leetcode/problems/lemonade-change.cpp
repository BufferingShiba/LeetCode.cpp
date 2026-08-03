#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/lemonade-change.h"

namespace leetcode::problem_860 {

class LemonadeChangeTest : public ::testing::TestWithParam<std::string> {
 protected:
  LemonadeChangeSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(LemonadeChangeTest, Example1) {
  std::vector<int> bills{5, 5, 5, 10, 20};
  EXPECT_TRUE(solution.lemonadeChange(bills));
}

TEST_P(LemonadeChangeTest, Example2) {
  std::vector<int> bills{5, 5, 10, 10, 20};
  EXPECT_FALSE(solution.lemonadeChange(bills));
}

TEST_P(LemonadeChangeTest, SelfAuthoredOnlyFive) {
  std::vector<int> bills{5, 5, 5, 5, 5};
  EXPECT_TRUE(solution.lemonadeChange(bills));
}

TEST_P(LemonadeChangeTest, SelfAuthoredCannotChangeFirst) {
  std::vector<int> bills{10, 10};
  EXPECT_FALSE(solution.lemonadeChange(bills));
}

INSTANTIATE_TEST_SUITE_P(LemonadeChangeTestSuite, LemonadeChangeTest,
                         ::testing::ValuesIn(LemonadeChangeSolution().getStrategyNames()));

}  // namespace leetcode::problem_860
