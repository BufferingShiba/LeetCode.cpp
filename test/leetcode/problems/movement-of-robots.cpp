#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/movement-of-robots.h"

namespace leetcode {
namespace problem_2731 {
namespace {

class MovementOfRobotsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MovementOfRobotsSolution solution;
};

TEST_P(MovementOfRobotsTest, Example1) {
  std::vector<int> nums = {-2, 0, 2};
  std::string s = "RLL";
  int d = 3;
  EXPECT_EQ(8, solution.sumDistance(nums, s, d));
}

TEST_P(MovementOfRobotsTest, Example2) {
  std::vector<int> nums = {1, 0};
  std::string s = "RL";
  int d = 2;
  EXPECT_EQ(5, solution.sumDistance(nums, s, d));
}

TEST_P(MovementOfRobotsTest, SelfAuthoredAllMonotonicSingleExpected) {
  // 两个机器人同向移动，距离保持不变。
  std::vector<int> nums = {0, 5};
  std::string s = "RR";
  int d = 10;
  EXPECT_EQ(5, solution.sumDistance(nums, s, d));
}

TEST_P(MovementOfRobotsTest, SelfAuthoredSameDirectionOpposite) {
  std::vector<int> nums = {0, 5};
  std::string s = "LR";
  int d = 3;
  // 初始距离 5，相互靠近。最终位置为 [-3, 8]，距离 11。
  EXPECT_EQ(11, solution.sumDistance(nums, s, d));
}

INSTANTIATE_TEST_SUITE_P(
    MovementOfRobotsTests, MovementOfRobotsTest,
    ::testing::ValuesIn(MovementOfRobotsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2731
}  // namespace leetcode
