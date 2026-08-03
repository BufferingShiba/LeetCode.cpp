#include <gtest/gtest.h>

#include "leetcode/problems/non-overlapping-intervals.h"

using namespace leetcode::problem_435;

class NonOverlappingIntervalsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  NonOverlappingIntervalsSolution solution_;
};

TEST_P(NonOverlappingIntervalsTest, Example1) {
  std::vector<std::vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  EXPECT_EQ(solution_.eraseOverlapIntervals(intervals), 1);
}

TEST_P(NonOverlappingIntervalsTest, Example2) {
  std::vector<std::vector<int>> intervals = {{1, 2}, {1, 2}, {1, 2}};
  EXPECT_EQ(solution_.eraseOverlapIntervals(intervals), 2);
}

TEST_P(NonOverlappingIntervalsTest, Example3) {
  std::vector<std::vector<int>> intervals = {{1, 2}, {2, 3}};
  EXPECT_EQ(solution_.eraseOverlapIntervals(intervals), 0);
}

TEST_P(NonOverlappingIntervalsTest, SelfAuthoredSingleInterval) {
  std::vector<std::vector<int>> intervals = {{5, 10}};
  EXPECT_EQ(solution_.eraseOverlapIntervals(intervals), 0);
}

TEST_P(NonOverlappingIntervalsTest, SelfAuthoredAllOverlapAtSameStart) {
  std::vector<std::vector<int>> intervals = {{1, 5}, {1, 4}, {1, 3}, {1, 2}};
  EXPECT_EQ(solution_.eraseOverlapIntervals(intervals), 3);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, NonOverlappingIntervalsTest,
    ::testing::ValuesIn(NonOverlappingIntervalsSolution().getStrategyNames()));
