#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-number-of-flips-to-reverse-binary-string.h"

namespace leetcode {
namespace problem_3750 {
namespace {

class MinimumNumberOfFlipsToReverseBinaryStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumNumberOfFlipsToReverseBinaryStringSolution solution;
};

TEST_P(MinimumNumberOfFlipsToReverseBinaryStringTest, Example1) {
  EXPECT_EQ(0, solution.minimumFlips(7));
}

TEST_P(MinimumNumberOfFlipsToReverseBinaryStringTest, Example2) {
  EXPECT_EQ(4, solution.minimumFlips(10));
}

TEST_P(MinimumNumberOfFlipsToReverseBinaryStringTest, SelfAuthoredSingleBit) {
  // n = 1 -> "1", reverse "1", no flips.
  EXPECT_EQ(0, solution.minimumFlips(1));
}

TEST_P(MinimumNumberOfFlipsToReverseBinaryStringTest, SelfAuthoredPalindromeBits) {
  // n = 21 -> "10101", palindrome, 0 flips.
  EXPECT_EQ(0, solution.minimumFlips(21));
}

TEST_P(MinimumNumberOfFlipsToReverseBinaryStringTest, SelfAuthoredAllDifferent) {
  // n = 12 -> "1100", reverse "0011", all 4 differ.
  EXPECT_EQ(4, solution.minimumFlips(12));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfFlipsToReverseBinaryStringTests,
    MinimumNumberOfFlipsToReverseBinaryStringTest,
    ::testing::ValuesIn(
        MinimumNumberOfFlipsToReverseBinaryStringSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3750
}  // namespace leetcode
