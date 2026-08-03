#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-number-of-visible-points.h"

namespace leetcode {
namespace problem_1610 {

class MaximumNumberOfVisiblePointsTest
    : public ::testing::TestWithParam<std::string> {
protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumNumberOfVisiblePointsSolution solution;
};

TEST_P(MaximumNumberOfVisiblePointsTest, Example1) {
  std::vector<std::vector<int>> points = {{2, 1}, {2, 2}, {3, 3}};
  int angle = 90;
  std::vector<int> location = {1, 1};
  EXPECT_EQ(3, solution.visiblePoints(points, angle, location));
}

TEST_P(MaximumNumberOfVisiblePointsTest, Example2) {
  std::vector<std::vector<int>> points = {{2, 1}, {2, 2}, {3, 4}, {1, 1}};
  int angle = 90;
  std::vector<int> location = {1, 1};
  EXPECT_EQ(4, solution.visiblePoints(points, angle, location));
}

TEST_P(MaximumNumberOfVisiblePointsTest, Example3) {
  std::vector<std::vector<int>> points = {{1, 0}, {2, 1}};
  int angle = 13;
  std::vector<int> location = {1, 1};
  EXPECT_EQ(1, solution.visiblePoints(points, angle, location));
}

TEST_P(MaximumNumberOfVisiblePointsTest, SelfAuthoredSinglePointOnEast) {
  // A single point directly east from location, always visible.
  std::vector<std::vector<int>> points = {{3, 1}};
  int angle = 0;
  std::vector<int> location = {1, 1};
  EXPECT_EQ(1, solution.visiblePoints(points, angle, location));
}

TEST_P(MaximumNumberOfVisiblePointsTest, SelfAuthoredAngleZeroExactMatch) {
  // angle 0: only points exactly on the same ray are visible.
  std::vector<std::vector<int>> points = {{2, 1}, {1, 2}};
  int angle = 0;
  std::vector<int> location = {1, 1};
  // (2,1) is east direction (angle 0); (1,2) is north (angle 90).
  EXPECT_EQ(1, solution.visiblePoints(points, angle, location));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfVisiblePointsTestSuite, MaximumNumberOfVisiblePointsTest,
    ::testing::ValuesIn(MaximumNumberOfVisiblePointsSolution().getStrategyNames()));

}  // namespace problem_1610
}  // namespace leetcode
