#include <gtest/gtest.h>

#include "leetcode/problems/interval-list-intersections.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_986 {
namespace {

using std::vector;

void EXPECT_INTERVALS(const vector<vector<int>>& actual,
                      const vector<vector<int>>& expected) {
  ASSERT_EQ(expected.size(), actual.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    EXPECT_EQ(expected[i][0], actual[i][0]);
    EXPECT_EQ(expected[i][1], actual[i][1]);
  }
}

}  // namespace

class IntervalListIntersectionsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  IntervalListIntersectionsSolution solution;
};

TEST_P(IntervalListIntersectionsTest, Example1) {
  vector<vector<int>> firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
  vector<vector<int>> secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
  vector<vector<int>> expected = {{1, 2}, {5, 5},  {8, 10},
                                  {15, 23}, {24, 24}, {25, 25}};
  EXPECT_INTERVALS(solution.intervalIntersection(firstList, secondList), expected);
}

TEST_P(IntervalListIntersectionsTest, Example2) {
  vector<vector<int>> firstList = {{1, 3}, {5, 9}};
  vector<vector<int>> secondList = {};
  vector<vector<int>> expected = {};
  EXPECT_INTERVALS(solution.intervalIntersection(firstList, secondList), expected);
}

TEST_P(IntervalListIntersectionsTest, SelfAuthoredNoOverlap) {
  vector<vector<int>> firstList = {{0, 2}, {6, 8}};
  vector<vector<int>> secondList = {{3, 5}, {9, 10}};
  vector<vector<int>> expected = {};
  EXPECT_INTERVALS(solution.intervalIntersection(firstList, secondList), expected);
}

TEST_P(IntervalListIntersectionsTest, SelfAuthoredSinglePointTouching) {
  vector<vector<int>> firstList = {{0, 2}, {5, 10}};
  vector<vector<int>> secondList = {{2, 5}};
  vector<vector<int>> expected = {{2, 2}, {5, 5}};
  EXPECT_INTERVALS(solution.intervalIntersection(firstList, secondList), expected);
}

INSTANTIATE_TEST_SUITE_P(
    IntervalListIntersectionsTests, IntervalListIntersectionsTest,
    ::testing::ValuesIn(IntervalListIntersectionsSolution().getStrategyNames()));

}  // namespace problem_986
}  // namespace leetcode
