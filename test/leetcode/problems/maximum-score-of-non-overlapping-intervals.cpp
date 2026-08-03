#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-score-of-non-overlapping-intervals.h"

namespace leetcode {
namespace problem_3414 {

class MaximumScoreOfNonOverlappingIntervalsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumScoreOfNonOverlappingIntervalsSolution solution;
};

TEST_P(MaximumScoreOfNonOverlappingIntervalsTest, Example1) {
  std::vector<std::vector<int>> intervals = {
      {1, 3, 2}, {4, 5, 2}, {1, 5, 5}, {6, 9, 3}, {6, 7, 1}, {8, 9, 1}};
  EXPECT_EQ(solution.maximumWeight(intervals), std::vector<int>({2, 3}));
}

TEST_P(MaximumScoreOfNonOverlappingIntervalsTest, Example2) {
  std::vector<std::vector<int>> intervals = {
      {5, 8, 1}, {6, 7, 7}, {4, 7, 3}, {9, 10, 6},
      {7, 8, 2}, {11, 14, 3}, {3, 5, 5}};
  EXPECT_EQ(solution.maximumWeight(intervals), std::vector<int>({1, 3, 5, 6}));
}

TEST_P(MaximumScoreOfNonOverlappingIntervalsTest, SelfAuthoredSingleInterval) {
  std::vector<std::vector<int>> intervals = {{1, 1, 10}};
  EXPECT_EQ(solution.maximumWeight(intervals), std::vector<int>({0}));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumScoreOfNonOverlappingIntervalsTestSuite,
    MaximumScoreOfNonOverlappingIntervalsTest,
    ::testing::ValuesIn(MaximumScoreOfNonOverlappingIntervalsSolution()
                            .getStrategyNames()));

}  // namespace problem_3414
}  // namespace leetcode
