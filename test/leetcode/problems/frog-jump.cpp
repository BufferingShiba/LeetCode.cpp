#include <gtest/gtest.h>
#include "leetcode/problems/frog-jump.h"

using namespace leetcode::problem_403;

class FrogJumpTest : public ::testing::TestWithParam<std::string> {
 protected:
  FrogJumpSolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(FrogJumpTest, Example1) {
  std::vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
  EXPECT_TRUE(solution.canCross(stones));
}

TEST_P(FrogJumpTest, Example2) {
  std::vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};
  EXPECT_FALSE(solution.canCross(stones));
}

TEST_P(FrogJumpTest, SelfAuthoredTwoStonesReachable) {
  std::vector<int> stones = {0, 1};
  EXPECT_TRUE(solution.canCross(stones));
}

TEST_P(FrogJumpTest, SelfAuthoredTwoStonesUnreachable) {
  std::vector<int> stones = {0, 2};
  EXPECT_FALSE(solution.canCross(stones));
}

TEST_P(FrogJumpTest, SelfAuthoredThreeStonesReachable) {
  std::vector<int> stones = {0, 1, 2};
  EXPECT_TRUE(solution.canCross(stones));
}

TEST_P(FrogJumpTest, SelfAuthoredThreeStonesReachable2) {
  std::vector<int> stones = {0, 1, 3};
  EXPECT_TRUE(solution.canCross(stones));
}

TEST_P(FrogJumpTest, SelfAuthoredThreeStonesUnreachable) {
  std::vector<int> stones = {0, 1, 4};
  EXPECT_FALSE(solution.canCross(stones));
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    FrogJumpTest,
    ::testing::ValuesIn(FrogJumpSolution().getStrategyNames())
);
