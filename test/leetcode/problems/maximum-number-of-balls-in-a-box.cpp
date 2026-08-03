#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-number-of-balls-in-a-box.h"

namespace leetcode {
namespace problem_1742 {

class MaximumNumberOfBallsInABoxTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumNumberOfBallsInABoxSolution solution_;
};

TEST_P(MaximumNumberOfBallsInABoxTest, Example1) {
  EXPECT_EQ(solution_.countBalls(1, 10), 2);
}

TEST_P(MaximumNumberOfBallsInABoxTest, Example2) {
  EXPECT_EQ(solution_.countBalls(5, 15), 2);
}

TEST_P(MaximumNumberOfBallsInABoxTest, Example3) {
  EXPECT_EQ(solution_.countBalls(19, 28), 2);
}

TEST_P(MaximumNumberOfBallsInABoxTest, SingleBall) {
  EXPECT_EQ(solution_.countBalls(1, 1), 1);
}

TEST_P(MaximumNumberOfBallsInABoxTest, MaximumRange) {
  EXPECT_EQ(solution_.countBalls(99991, 100000), 1);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfBallsInABoxSuite, MaximumNumberOfBallsInABoxTest,
    ::testing::ValuesIn(
        MaximumNumberOfBallsInABoxSolution().getStrategyNames()));

}  // namespace problem_1742
}  // namespace leetcode
