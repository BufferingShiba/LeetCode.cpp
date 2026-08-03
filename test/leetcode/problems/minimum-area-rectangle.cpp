#include <gtest/gtest.h>

#include "leetcode/problems/minimum-area-rectangle.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_939 {
namespace {

class MinimumAreaRectangleTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumAreaRectangleSolution solution;
};

TEST_P(MinimumAreaRectangleTest, Example1) {
  std::vector<std::vector<int>> points = {
      {1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2}};
  EXPECT_EQ(4, solution.minAreaRect(points));
}

TEST_P(MinimumAreaRectangleTest, Example2) {
  std::vector<std::vector<int>> points = {
      {1, 1}, {1, 3}, {3, 1}, {3, 3}, {4, 1}, {4, 3}};
  EXPECT_EQ(2, solution.minAreaRect(points));
}

TEST_P(MinimumAreaRectangleTest, SelfAuthoredSinglePointNoRectangle) {
  std::vector<std::vector<int>> points = {{1, 1}};
  EXPECT_EQ(0, solution.minAreaRect(points));
}

TEST_P(MinimumAreaRectangleTest, SelfAuthoredTwoPointsSameRowNoRectangle) {
  std::vector<std::vector<int>> points = {{0, 0}, {2, 0}};
  EXPECT_EQ(0, solution.minAreaRect(points));
}

TEST_P(MinimumAreaRectangleTest, SelfAuthoredNoRectangle) {
  std::vector<std::vector<int>> points = {{0, 0}, {1, 0}, {0, 1}};
  EXPECT_EQ(0, solution.minAreaRect(points));
}

TEST_P(MinimumAreaRectangleTest, SelfAuthoredMultipleRowsSmallestArea) {
  // Rows y=0 and y=2 share x=0 and x=3 => area 6.
  // Rows y=0 and y=1 share x=1 and x=2 => area 1.
  std::vector<std::vector<int>> points = {
      {0, 0}, {1, 0}, {2, 0}, {3, 0},
      {1, 1}, {2, 1},
      {0, 2}, {3, 2}};
  EXPECT_EQ(1, solution.minAreaRect(points));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumAreaRectangleTestSuite, MinimumAreaRectangleTest,
    ::testing::ValuesIn(MinimumAreaRectangleSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_939
}  // namespace leetcode
