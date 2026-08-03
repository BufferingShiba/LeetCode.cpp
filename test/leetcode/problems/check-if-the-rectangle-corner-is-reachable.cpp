#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/check-if-the-rectangle-corner-is-reachable.h"

using namespace leetcode::problem_3235;

class CheckIfTheRectangleCornerIsReachableTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  CheckIfTheRectangleCornerIsReachableSolution solution_;
};

TEST_P(CheckIfTheRectangleCornerIsReachableTest, Example1) {
  std::vector<std::vector<int>> circles = {{2, 1, 1}};
  EXPECT_EQ(solution_.canReachCorner(3, 4, circles), true);
}

TEST_P(CheckIfTheRectangleCornerIsReachableTest, Example2) {
  std::vector<std::vector<int>> circles = {{1, 1, 2}};
  EXPECT_EQ(solution_.canReachCorner(3, 3, circles), false);
}

TEST_P(CheckIfTheRectangleCornerIsReachableTest, Example3) {
  std::vector<std::vector<int>> circles = {{2, 1, 1}, {1, 2, 1}};
  EXPECT_EQ(solution_.canReachCorner(3, 3, circles), false);
}

TEST_P(CheckIfTheRectangleCornerIsReachableTest, Example4) {
  std::vector<std::vector<int>> circles = {{5, 5, 1}};
  EXPECT_EQ(solution_.canReachCorner(4, 4, circles), true);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, CheckIfTheRectangleCornerIsReachableTest,
    testing::ValuesIn(
        CheckIfTheRectangleCornerIsReachableSolution().getStrategyNames()));
