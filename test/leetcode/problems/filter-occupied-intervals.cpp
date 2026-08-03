#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/filter-occupied-intervals.h"

namespace leetcode {
namespace problem_3975 {

class FilterOccupiedIntervalsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FilterOccupiedIntervalsSolution solution_;
};

TEST_P(FilterOccupiedIntervalsTest, Example1) {
  std::vector<std::vector<int>> occupied = {
      {2, 6}, {4, 8}, {10, 10}, {10, 12}, {14, 16}};
  int freeStart = 7;
  int freeEnd = 11;

  auto result = solution_.filterOccupiedIntervals(occupied, freeStart, freeEnd);
  std::vector<std::vector<int>> expected = {{2, 6}, {12, 12}, {14, 16}};

  EXPECT_EQ(result, expected);
}

TEST_P(FilterOccupiedIntervalsTest, Example2) {
  std::vector<std::vector<int>> occupied = {{1, 5}, {2, 3}};
  int freeStart = 3;
  int freeEnd = 8;

  auto result = solution_.filterOccupiedIntervals(occupied, freeStart, freeEnd);
  std::vector<std::vector<int>> expected = {{1, 2}};

  EXPECT_EQ(result, expected);
}

TEST_P(FilterOccupiedIntervalsTest, SelfAuthoredNoOverlapWithFree) {
  std::vector<std::vector<int>> occupied = {{1, 3}, {7, 9}};
  int freeStart = 4;
  int freeEnd = 6;

  auto result = solution_.filterOccupiedIntervals(occupied, freeStart, freeEnd);
  std::vector<std::vector<int>> expected = {{1, 3}, {7, 9}};

  EXPECT_EQ(result, expected);
}

TEST_P(FilterOccupiedIntervalsTest, SelfAuthoredFreeCoversAll) {
  std::vector<std::vector<int>> occupied = {{1, 10}};
  int freeStart = 1;
  int freeEnd = 10;

  auto result = solution_.filterOccupiedIntervals(occupied, freeStart, freeEnd);
  std::vector<std::vector<int>> expected = {};

  EXPECT_EQ(result, expected);
}

TEST_P(FilterOccupiedIntervalsTest, SelfAuthoredTouchingIntervals) {
  std::vector<std::vector<int>> occupied = {{1, 1}, {2, 2}, {3, 3}};
  int freeStart = 2;
  int freeEnd = 2;

  auto result = solution_.filterOccupiedIntervals(occupied, freeStart, freeEnd);
  std::vector<std::vector<int>> expected = {{1, 1}, {3, 3}};

  EXPECT_EQ(result, expected);
}

TEST_P(FilterOccupiedIntervalsTest, SelfAuthoredFreeAtLeftEdge) {
  std::vector<std::vector<int>> occupied = {{5, 10}};
  int freeStart = 1;
  int freeEnd = 5;

  auto result = solution_.filterOccupiedIntervals(occupied, freeStart, freeEnd);
  std::vector<std::vector<int>> expected = {{6, 10}};

  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, FilterOccupiedIntervalsTest,
    ::testing::ValuesIn(FilterOccupiedIntervalsSolution().getStrategyNames()));

}  // namespace problem_3975
}  // namespace leetcode
