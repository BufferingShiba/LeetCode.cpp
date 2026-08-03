#include <gtest/gtest.h>

#include "leetcode/problems/robot-bounded-in-circle.h"

namespace leetcode::problem_1041 {
namespace {

class RobotBoundedInCircleTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RobotBoundedInCircleSolution solution;
};

TEST_P(RobotBoundedInCircleTest, Example1) {
  EXPECT_TRUE(solution.isRobotBounded("GGLLGG"));
}

TEST_P(RobotBoundedInCircleTest, Example2) {
  EXPECT_FALSE(solution.isRobotBounded("GG"));
}

TEST_P(RobotBoundedInCircleTest, Example3) {
  EXPECT_TRUE(solution.isRobotBounded("GL"));
}

TEST_P(RobotBoundedInCircleTest, SelfAuthored) {
  // Already at origin, no movement
  EXPECT_TRUE(solution.isRobotBounded(""));
  // Only turns, stays at origin
  EXPECT_TRUE(solution.isRobotBounded("L"));
  EXPECT_TRUE(solution.isRobotBounded("R"));
  EXPECT_TRUE(solution.isRobotBounded("LLRR"));
  // Single G: direction unchanged, not back to origin → unbounded
  EXPECT_FALSE(solution.isRobotBounded("G"));
  // Four left turns = full circle, stays at origin
  EXPECT_TRUE(solution.isRobotBounded("LLLL"));
  // Four right turns = full circle, stays at origin
  EXPECT_TRUE(solution.isRobotBounded("RRRR"));
  // Direction changes after one round, bounded
  EXPECT_TRUE(solution.isRobotBounded("GR"));
  EXPECT_TRUE(solution.isRobotBounded("GLGLGLG"));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    RobotBoundedInCircleTest,
    testing::ValuesIn(RobotBoundedInCircleSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_1041
