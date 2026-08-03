#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-least-frequent-digit.h"

namespace leetcode {
namespace problem_3663 {
namespace {

class FindTheLeastFrequentDigitTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheLeastFrequentDigitSolution solution;
};

TEST_P(FindTheLeastFrequentDigitTest, Example1) {
  EXPECT_EQ(solution.getLeastFrequentDigit(1553322), 1);
}

TEST_P(FindTheLeastFrequentDigitTest, Example2) {
  EXPECT_EQ(solution.getLeastFrequentDigit(723344511), 2);
}

TEST_P(FindTheLeastFrequentDigitTest, SelfAuthoredSingleDigit) {
  EXPECT_EQ(solution.getLeastFrequentDigit(9), 9);
}

TEST_P(FindTheLeastFrequentDigitTest, SelfAuthoredAllRepeatingOneDigit) {
  EXPECT_EQ(solution.getLeastFrequentDigit(1111), 1);
}

TEST_P(FindTheLeastFrequentDigitTest, SelfAuthoredMinimumValue) {
  EXPECT_EQ(solution.getLeastFrequentDigit(1), 1);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheLeastFrequentDigitTestSuite, FindTheLeastFrequentDigitTest,
    ::testing::ValuesIn(FindTheLeastFrequentDigitSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3663
}  // namespace leetcode
