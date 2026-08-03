#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/largest-number-after-digit-swaps-by-parity.h"

namespace leetcode {
namespace problem_2231 {

class LargestNumberAfterDigitSwapsByParityTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LargestNumberAfterDigitSwapsByParitySolution solution;
};

TEST_P(LargestNumberAfterDigitSwapsByParityTest, Example1) {
  EXPECT_EQ(solution.largestInteger(1234), 3412);
}

TEST_P(LargestNumberAfterDigitSwapsByParityTest, Example2) {
  EXPECT_EQ(solution.largestInteger(65875), 87655);
}

TEST_P(LargestNumberAfterDigitSwapsByParityTest, SelfAuthoredSingleDigit) {
  EXPECT_EQ(solution.largestInteger(7), 7);
}

INSTANTIATE_TEST_SUITE_P(
    LargestNumberAfterDigitSwapsByParityTestSuite,
    LargestNumberAfterDigitSwapsByParityTest,
    ::testing::ValuesIn(
        LargestNumberAfterDigitSwapsByParitySolution().getStrategyNames()));

}  // namespace problem_2231
}  // namespace leetcode
