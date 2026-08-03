#include <gtest/gtest.h>
#include "leetcode/problems/find-the-losers-of-the-circular-game.h"

using namespace leetcode::problem_2682;

class FindTheLosersOfTheCircularGameTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  FindTheLosersOfTheCircularGameSolution solution_;
};

TEST_P(FindTheLosersOfTheCircularGameTest, Example1) {
  EXPECT_EQ(solution_.circularGameLosers(5, 2), std::vector<int>({4, 5}));
}

TEST_P(FindTheLosersOfTheCircularGameTest, Example2) {
  EXPECT_EQ(solution_.circularGameLosers(4, 4), std::vector<int>({2, 3, 4}));
}

INSTANTIATE_TEST_SUITE_P(, FindTheLosersOfTheCircularGameTest,
                         testing::ValuesIn(FindTheLosersOfTheCircularGameSolution().getStrategyNames()));
