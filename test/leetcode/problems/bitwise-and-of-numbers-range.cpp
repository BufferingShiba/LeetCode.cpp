#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/bitwise-and-of-numbers-range.h"

namespace leetcode {
namespace problem_201 {

class BitwiseAndOfNumbersRangeTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BitwiseAndOfNumbersRangeSolution solution;
};

TEST_P(BitwiseAndOfNumbersRangeTest, Example1) {
  EXPECT_EQ(solution.rangeBitwiseAnd(5, 7), 4);
}

TEST_P(BitwiseAndOfNumbersRangeTest, Example2) {
  EXPECT_EQ(solution.rangeBitwiseAnd(0, 0), 0);
}

TEST_P(BitwiseAndOfNumbersRangeTest, Example3) {
  EXPECT_EQ(solution.rangeBitwiseAnd(1, 2147483647), 0);
}

TEST_P(BitwiseAndOfNumbersRangeTest, SelfAuthoredSameNumber) {
  EXPECT_EQ(solution.rangeBitwiseAnd(42, 42), 42);
}

TEST_P(BitwiseAndOfNumbersRangeTest, SelfAuthoredConsecutive) {
  // 6 (110) & 7 (111) = 6 (110)
  EXPECT_EQ(solution.rangeBitwiseAnd(6, 7), 6);
}

TEST_P(BitwiseAndOfNumbersRangeTest, SelfAuthoredPowerOfTwoRange) {
  // 8 (1000) to 15 (1111): all share bit 8? No, 8..15: 8&9&10&...&15 = 8
  EXPECT_EQ(solution.rangeBitwiseAnd(8, 15), 8);
}

TEST_P(BitwiseAndOfNumbersRangeTest, SelfAuthoredLargeRangeAllZero) {
  // 0 to INT_MAX -> 0
  EXPECT_EQ(solution.rangeBitwiseAnd(0, 2147483647), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    BitwiseAndOfNumbersRangeTest,
    testing::ValuesIn(
        BitwiseAndOfNumbersRangeSolution().getStrategyNames()));

}  // namespace problem_201
}  // namespace leetcode
