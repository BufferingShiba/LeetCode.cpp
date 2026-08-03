#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/robot-return-to-origin.h"

namespace leetcode::problem_657 {

class RobotReturnToOriginTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  RobotReturnToOriginSolution solution_;
};

TEST_P(RobotReturnToOriginTest, Example1) {
  EXPECT_TRUE(solution_.judgeCircle("UD"));
}

TEST_P(RobotReturnToOriginTest, Example2) {
  EXPECT_FALSE(solution_.judgeCircle("LL"));
}

TEST_P(RobotReturnToOriginTest, SelfAuthored1) {
  EXPECT_TRUE(solution_.judgeCircle("RRDDLLUU"));
}

TEST_P(RobotReturnToOriginTest, SelfAuthored2) {
  EXPECT_FALSE(solution_.judgeCircle("URDLU"));
}

INSTANTIATE_TEST_SUITE_P(
    RobotReturnToOriginTest, RobotReturnToOriginTest,
    ::testing::ValuesIn(RobotReturnToOriginSolution().getStrategyNames()));

}  // namespace leetcode::problem_657
