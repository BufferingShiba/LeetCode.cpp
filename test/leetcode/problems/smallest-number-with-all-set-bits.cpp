#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/smallest-number-with-all-set-bits.h"

namespace leetcode::problem_3370 {

class SmallestNumberWithAllSetBitsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SmallestNumberWithAllSetBitsSolution solution;
};

TEST_P(SmallestNumberWithAllSetBitsTest, Example1) {
  EXPECT_EQ(solution.smallestNumber(5), 7);
}

TEST_P(SmallestNumberWithAllSetBitsTest, Example2) {
  EXPECT_EQ(solution.smallestNumber(10), 15);
}

TEST_P(SmallestNumberWithAllSetBitsTest, Example3) {
  EXPECT_EQ(solution.smallestNumber(3), 3);
}

TEST_P(SmallestNumberWithAllSetBitsTest, SelfAuthoredEdgeCaseNIsOne) {
  EXPECT_EQ(solution.smallestNumber(1), 1);
}

TEST_P(SmallestNumberWithAllSetBitsTest, SelfAuthoredEdgeCasePowerOfTwo) {
  // 8 = 1000 -> 15 = 1111
  EXPECT_EQ(solution.smallestNumber(8), 15);
}

TEST_P(SmallestNumberWithAllSetBitsTest, SelfAuthoredEdgeCaseUpperBound) {
  // 1000 = 1111101000 -> result is 1023
  EXPECT_EQ(solution.smallestNumber(1000), 1023);
}

INSTANTIATE_TEST_SUITE_P(
    SmallestNumberWithAllSetBitsTestSuite,
    SmallestNumberWithAllSetBitsTest,
    ::testing::ValuesIn(
        SmallestNumberWithAllSetBitsSolution().getStrategyNames()));

}  // namespace leetcode::problem_3370
