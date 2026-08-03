#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate.h"

namespace leetcode {
namespace problem_1779 {
namespace {

class FindNearestPointThatHasTheSameXOrYCoordinateTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindNearestPointThatHasTheSameXOrYCoordinateSolution solution_;
};

TEST_P(FindNearestPointThatHasTheSameXOrYCoordinateTest, Example1) {
  std::vector<std::vector<int>> points = {{1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}};
  EXPECT_EQ(solution_.nearestValidPoint(3, 4, points), 2);
}

TEST_P(FindNearestPointThatHasTheSameXOrYCoordinateTest, Example2) {
  std::vector<std::vector<int>> points = {{3, 4}};
  EXPECT_EQ(solution_.nearestValidPoint(3, 4, points), 0);
}

TEST_P(FindNearestPointThatHasTheSameXOrYCoordinateTest, Example3) {
  std::vector<std::vector<int>> points = {{2, 3}};
  EXPECT_EQ(solution_.nearestValidPoint(3, 4, points), -1);
}

TEST_P(FindNearestPointThatHasTheSameXOrYCoordinateTest, SelfAuthoredSingleInvalid) {
  std::vector<std::vector<int>> points = {{1, 1}};
  EXPECT_EQ(solution_.nearestValidPoint(2, 3, points), -1);
}

TEST_P(FindNearestPointThatHasTheSameXOrYCoordinateTest, SelfAuthoredTieBreakSmallestIndex) {
  std::vector<std::vector<int>> points = {{3, 5}, {3, 3}, {5, 4}};
  EXPECT_EQ(solution_.nearestValidPoint(3, 4, points), 0);
}

INSTANTIATE_TEST_SUITE_P(
    FindNearestPointThatHasTheSameXOrYCoordinateTests,
    FindNearestPointThatHasTheSameXOrYCoordinateTest,
    ::testing::ValuesIn(
        FindNearestPointThatHasTheSameXOrYCoordinateSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace problem_1779
}  // namespace leetcode
