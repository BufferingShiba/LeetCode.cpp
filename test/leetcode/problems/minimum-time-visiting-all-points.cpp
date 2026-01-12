#include "leetcode/problems/minimum-time-visiting-all-points.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1266 {

class MinimumTimeVisitingAllPointsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumTimeVisitingAllPointsSolution solution;
};

TEST_P(MinimumTimeVisitingAllPointsTest, Example1) {
  vector<vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};
  int expected = 7;
  int result = solution.minTimeToVisitAllPoints(points);
  EXPECT_EQ(expected, result);
}

TEST_P(MinimumTimeVisitingAllPointsTest, Example2) {
  vector<vector<int>> points = {{3, 2}, {-2, 2}};
  int expected = 5;
  int result = solution.minTimeToVisitAllPoints(points);
  EXPECT_EQ(expected, result);
}

TEST_P(MinimumTimeVisitingAllPointsTest, SinglePoint) {
  vector<vector<int>> points = {{0, 0}};
  int expected = 0;
  int result = solution.minTimeToVisitAllPoints(points);
  EXPECT_EQ(expected, result);
}

TEST_P(MinimumTimeVisitingAllPointsTest, TwoPointsHorizontal) {
  vector<vector<int>> points = {{0, 0}, {5, 0}};
  int expected = 5;  // dx=5, dy=0, max=5
  int result = solution.minTimeToVisitAllPoints(points);
  EXPECT_EQ(expected, result);
}

TEST_P(MinimumTimeVisitingAllPointsTest, TwoPointsVertical) {
  vector<vector<int>> points = {{0, 0}, {0, 3}};
  int expected = 3;  // dx=0, dy=3, max=3
  int result = solution.minTimeToVisitAllPoints(points);
  EXPECT_EQ(expected, result);
}

TEST_P(MinimumTimeVisitingAllPointsTest, TwoPointsDiagonal) {
  vector<vector<int>> points = {{1, 1}, {4, 4}};
  int expected = 3;  // dx=3, dy=3, max=3
  int result = solution.minTimeToVisitAllPoints(points);
  EXPECT_EQ(expected, result);
}

TEST_P(MinimumTimeVisitingAllPointsTest, MultiplePoints) {
  vector<vector<int>> points = {{0, 0}, {1, 1}, {1, 2}, {3, 4}, {2, 3}};
  // 0->1: max(1,1)=1
  // 1->2: max(0,1)=1
  // 2->3: max(2,2)=2
  // 3->4: max(1,1)=1 (注意：从(3,4)到(2,3)：dx=1, dy=1)
  int expected = 1 + 1 + 2 + 1;  // =5
  int result = solution.minTimeToVisitAllPoints(points);
  EXPECT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumTimeVisitingAllPointsTest,
    ::testing::ValuesIn(MinimumTimeVisitingAllPointsSolution().getStrategyNames()));

}  // namespace problem_1266
}  // namespace leetcode