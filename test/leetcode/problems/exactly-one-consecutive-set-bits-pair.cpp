#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/exactly-one-consecutive-set-bits-pair.h"

namespace leetcode::problem_3950 {

class ExactlyOneConsecutiveSetBitsPairTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  ExactlyOneConsecutiveSetBitsPairSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(ExactlyOneConsecutiveSetBitsPairTest, Example1) {
  EXPECT_TRUE(solution.consecutiveSetBits(6));
}

TEST_P(ExactlyOneConsecutiveSetBitsPairTest, Example2) {
  EXPECT_FALSE(solution.consecutiveSetBits(5));
}

TEST_P(ExactlyOneConsecutiveSetBitsPairTest, SelfAuthoredNoSetBits) {
  EXPECT_FALSE(solution.consecutiveSetBits(0));
}

TEST_P(ExactlyOneConsecutiveSetBitsPairTest, SelfAuthoredSingleSetBit) {
  EXPECT_FALSE(solution.consecutiveSetBits(4));  // 100
}

TEST_P(ExactlyOneConsecutiveSetBitsPairTest, SelfAuthoredThreeConsecutiveOnes) {
  EXPECT_FALSE(solution.consecutiveSetBits(7));  // 111 -> two pairs
}

INSTANTIATE_TEST_SUITE_P(
    ExactlyOneConsecutiveSetBitsPairTests,
    ExactlyOneConsecutiveSetBitsPairTest,
    ::testing::ValuesIn(
        ExactlyOneConsecutiveSetBitsPairSolution().getStrategyNames()));

}  // namespace leetcode::problem_3950
