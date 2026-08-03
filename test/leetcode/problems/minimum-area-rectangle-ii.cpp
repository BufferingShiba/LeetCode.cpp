#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-area-rectangle-ii.h"

namespace leetcode::problem_963 {
namespace {

using StrategyParams = std::string;

class MinimumAreaRectangleIiTest
    : public ::testing::TestWithParam<StrategyParams> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumAreaRectangleIiSolution solution;
};

TEST_P(MinimumAreaRectangleIiTest, Example1) {
  std::vector<std::vector<int>> points = {{1, 2}, {2, 1}, {1, 0}, {0, 1}};
  EXPECT_DOUBLE_EQ(2.0, solution.minAreaFreeRect(points));
}

TEST_P(MinimumAreaRectangleIiTest, Example2) {
  std::vector<std::vector<int>> points = {
      {0, 1}, {2, 1}, {1, 1}, {1, 0}, {2, 0}};
  EXPECT_DOUBLE_EQ(1.0, solution.minAreaFreeRect(points));
}

TEST_P(MinimumAreaRectangleIiTest, Example3) {
  std::vector<std::vector<int>> points = {
      {0, 3}, {1, 2}, {3, 1}, {1, 3}, {2, 1}};
  EXPECT_DOUBLE_EQ(0.0, solution.minAreaFreeRect(points));
}

TEST_P(MinimumAreaRectangleIiTest, SelfAuthoredTooFewPoints) {
  std::vector<std::vector<int>> points = {{0, 0}, {1, 0}, {0, 1}};
  EXPECT_DOUBLE_EQ(0.0, solution.minAreaFreeRect(points));
}

TEST_P(MinimumAreaRectangleIiTest, SelfAuthoredAxisAlignedSquare) {
  std::vector<std::vector<int>> points = {
      {0, 0}, {2, 0}, {2, 2}, {0, 2}};
  EXPECT_DOUBLE_EQ(4.0, solution.minAreaFreeRect(points));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumAreaRectangleIiTestSuite, MinimumAreaRectangleIiTest,
    ::testing::ValuesIn(MinimumAreaRectangleIiSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_963
