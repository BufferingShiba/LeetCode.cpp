#include "leetcode/problems/minimum-generations-to-target-point.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3923 {
namespace {

class MinimumGenerationsToTargetPointTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumGenerationsToTargetPointSolution solution;
};

TEST_P(MinimumGenerationsToTargetPointTest, Example1) {
  std::vector<std::vector<int>> points = {{0, 0, 0}, {6, 6, 6}};
  std::vector<int> target = {3, 3, 3};
  EXPECT_EQ(solution.getSolution()(points, target), 1);
}

TEST_P(MinimumGenerationsToTargetPointTest, Example2) {
  std::vector<std::vector<int>> points = {{0, 0, 0}, {5, 5, 5}};
  std::vector<int> target = {1, 1, 1};
  EXPECT_EQ(solution.getSolution()(points, target), 2);
}

TEST_P(MinimumGenerationsToTargetPointTest, Example3) {
  std::vector<std::vector<int>> points = {{0, 0, 0}, {2, 2, 2}, {3, 3, 3}};
  std::vector<int> target = {2, 2, 2};
  EXPECT_EQ(solution.getSolution()(points, target), 0);
}

TEST_P(MinimumGenerationsToTargetPointTest, Example4) {
  std::vector<std::vector<int>> points = {{1, 2, 3}};
  std::vector<int> target = {5, 5, 5};
  EXPECT_EQ(solution.getSolution()(points, target), -1);
}

TEST_P(MinimumGenerationsToTargetPointTest, SelfAuthoredAlreadyTarget) {
  std::vector<std::vector<int>> points = {{0, 0, 0}, {4, 4, 4}};
  std::vector<int> target = {4, 4, 4};
  EXPECT_EQ(solution.getSolution()(points, target), 0);
}

TEST_P(MinimumGenerationsToTargetPointTest, SelfAuthoredTwoPointTowardExtreme) {
  // With {0,0,0} and {6,6,6}: gen1 -> {3,3,3}; gen2 -> {1,1,1}/{4,4,4}/{1,1,1}...
  // target {1,1,1} requires 2 generations.
  std::vector<std::vector<int>> points = {{0, 0, 0}, {6, 6, 6}};
  std::vector<int> target = {1, 1, 1};
  EXPECT_EQ(solution.getSolution()(points, target), 2);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumGenerationsToTargetPointSuite, MinimumGenerationsToTargetPointTest,
    ::testing::ValuesIn(MinimumGenerationsToTargetPointSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3923
}  // namespace leetcode
