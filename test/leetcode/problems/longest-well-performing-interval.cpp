#include "leetcode/problems/longest-well-performing-interval.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_1124 {

class LongestWellPerformingIntervalTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  LongestWellPerformingIntervalSolution solution_;
};

TEST_P(LongestWellPerformingIntervalTest, Example1) {
  std::vector<int> hours = {9, 9, 6, 0, 6, 6, 9};
  EXPECT_EQ(3, solution_.longestWPI(hours));
}

TEST_P(LongestWellPerformingIntervalTest, Example2) {
  std::vector<int> hours = {6, 6, 6};
  EXPECT_EQ(0, solution_.longestWPI(hours));
}

TEST_P(LongestWellPerformingIntervalTest, SelfAuthoredAllTiring) {
  std::vector<int> hours = {9, 10, 9, 9};
  EXPECT_EQ(4, solution_.longestWPI(hours));
}

TEST_P(LongestWellPerformingIntervalTest, SelfAuthoredSingleTiringDay) {
  std::vector<int> hours = {9};
  EXPECT_EQ(1, solution_.longestWPI(hours));
}

INSTANTIATE_TEST_SUITE_P(
    LongestWellPerformingIntervalTestCases,
    LongestWellPerformingIntervalTest,
    ::testing::ValuesIn(
        LongestWellPerformingIntervalSolution().getStrategyNames()));

}  // namespace leetcode::problem_1124
