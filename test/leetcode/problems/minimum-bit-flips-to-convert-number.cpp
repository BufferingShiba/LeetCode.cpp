#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/minimum-bit-flips-to-convert-number.h"

namespace leetcode {
namespace problem_2220 {
namespace {

class MinimumBitFlipsToConvertNumberTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumBitFlipsToConvertNumberSolution solution;
};

TEST_P(MinimumBitFlipsToConvertNumberTest, Example1) {
  EXPECT_EQ(solution.minBitFlips(10, 7), 3);
}

TEST_P(MinimumBitFlipsToConvertNumberTest, Example2) {
  EXPECT_EQ(solution.minBitFlips(3, 4), 3);
}

TEST_P(MinimumBitFlipsToConvertNumberTest, SelfAuthoredEqualNumbers) {
  EXPECT_EQ(solution.minBitFlips(0, 0), 0);
  EXPECT_EQ(solution.minBitFlips(1000000000, 1000000000), 0);
}

TEST_P(MinimumBitFlipsToConvertNumberTest, SelfAuthoredSingleBit) {
  EXPECT_EQ(solution.minBitFlips(1, 2), 2);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumBitFlipsToConvertNumberTestSuite,
    MinimumBitFlipsToConvertNumberTest,
    ::testing::ValuesIn(
        MinimumBitFlipsToConvertNumberSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2220
}  // namespace leetcode
