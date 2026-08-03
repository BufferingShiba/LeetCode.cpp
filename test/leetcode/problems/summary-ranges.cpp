#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/summary-ranges.h"

namespace leetcode::problem_228 {

class SummaryRangesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SummaryRangesSolution solution;
};

TEST_P(SummaryRangesTest, Example1) {
  std::vector<int> nums = {0, 1, 2, 4, 5, 7};
  std::vector<std::string> expected = {"0->2", "4->5", "7"};
  EXPECT_EQ(solution.summaryRanges(nums), expected);
}

TEST_P(SummaryRangesTest, Example2) {
  std::vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
  std::vector<std::string> expected = {"0", "2->4", "6", "8->9"};
  EXPECT_EQ(solution.summaryRanges(nums), expected);
}

TEST_P(SummaryRangesTest, SelfAuthoredEmptyArray) {
  std::vector<int> nums = {};
  std::vector<std::string> expected = {};
  EXPECT_EQ(solution.summaryRanges(nums), expected);
}

TEST_P(SummaryRangesTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  std::vector<std::string> expected = {"5"};
  EXPECT_EQ(solution.summaryRanges(nums), expected);
}

TEST_P(SummaryRangesTest, SelfAuthoredIntMinToIntMax) {
  std::vector<int> nums = {-2147483648, -2147483647, 2147483646, 2147483647};
  std::vector<std::string> expected = {"-2147483648->-2147483647",
                                       "2147483646->2147483647"};
  EXPECT_EQ(solution.summaryRanges(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    SummaryRangesTestCases, SummaryRangesTest,
    ::testing::ValuesIn(SummaryRangesSolution().getStrategyNames()));

}  // namespace leetcode::problem_228
