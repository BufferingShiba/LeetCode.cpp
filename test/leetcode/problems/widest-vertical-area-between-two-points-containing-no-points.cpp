#include <gtest/gtest.h>

#include "leetcode/problems/widest-vertical-area-between-two-points-containing-no-points.h"

#include <string>
#include <vector>

namespace leetcode::problem_1637 {

class WidestVerticalAreaBetweenTwoPointsContainingNoPointsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  WidestVerticalAreaBetweenTwoPointsContainingNoPointsSolution solution;
};

TEST_P(WidestVerticalAreaBetweenTwoPointsContainingNoPointsTest, Example1) {
  std::vector<std::vector<int>> points = {{8, 7}, {9, 9}, {7, 4}, {9, 7}};
  EXPECT_EQ(solution.maxWidthOfVerticalArea(points), 1);
}

TEST_P(WidestVerticalAreaBetweenTwoPointsContainingNoPointsTest, Example2) {
  std::vector<std::vector<int>> points = {{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};
  EXPECT_EQ(solution.maxWidthOfVerticalArea(points), 3);
}

INSTANTIATE_TEST_SUITE_P(
    WidestVerticalAreaBetweenTwoPointsContainingNoPointsTestSuite,
    WidestVerticalAreaBetweenTwoPointsContainingNoPointsTest,
    ::testing::ValuesIn(
        WidestVerticalAreaBetweenTwoPointsContainingNoPointsSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_1637
