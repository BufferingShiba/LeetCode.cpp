#include "leetcode/problems/maximum-area-of-longest-diagonal-rectangle.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3000 {

class MaximumAreaOfLongestDiagonalRectangleTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumAreaOfLongestDiagonalRectangleSolution solution_;
};

TEST_P(MaximumAreaOfLongestDiagonalRectangleTest, Example1) {
  std::vector<std::vector<int>> dimensions = {{9, 3}, {8, 6}};
  EXPECT_EQ(48, solution_.areaOfMaxDiagonal(dimensions));
}

TEST_P(MaximumAreaOfLongestDiagonalRectangleTest, Example2) {
  std::vector<std::vector<int>> dimensions = {{3, 4}, {4, 3}};
  EXPECT_EQ(12, solution_.areaOfMaxDiagonal(dimensions));
}

TEST_P(MaximumAreaOfLongestDiagonalRectangleTest, SelfAuthoredSingleRectangle) {
  std::vector<std::vector<int>> dimensions = {{5, 12}};
  EXPECT_EQ(60, solution_.areaOfMaxDiagonal(dimensions));
}

TEST_P(MaximumAreaOfLongestDiagonalRectangleTest, SelfAuthoredEqualDiagonalPickLargerArea) {
  std::vector<std::vector<int>> dimensions = {{1, 2}, {2, 1}};
  EXPECT_EQ(2, solution_.areaOfMaxDiagonal(dimensions));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumAreaOfLongestDiagonalRectangleTestSuite,
    MaximumAreaOfLongestDiagonalRectangleTest,
    ::testing::ValuesIn(
        MaximumAreaOfLongestDiagonalRectangleSolution().getStrategyNames()));

}  // namespace problem_3000
}  // namespace leetcode
