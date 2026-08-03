#include "leetcode/problems/maximum-number-of-subsequences-after-one-inserting.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode::problem_3628 {

class MaximumNumberOfSubsequencesAfterOneInsertingTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumNumberOfSubsequencesAfterOneInsertingSolution solution_;
};

TEST_P(MaximumNumberOfSubsequencesAfterOneInsertingTest, Examples) {
  EXPECT_EQ(2, solution_.numOfSubsequences("LMCT"));
  EXPECT_EQ(4, solution_.numOfSubsequences("LCCT"));
  EXPECT_EQ(0, solution_.numOfSubsequences("L"));
}

TEST_P(MaximumNumberOfSubsequencesAfterOneInsertingTest, ShortAndTrivial) {
  EXPECT_EQ(0, solution_.numOfSubsequences(""));
  EXPECT_EQ(0, solution_.numOfSubsequences("T"));
  EXPECT_EQ(0, solution_.numOfSubsequences("ABC"));
}

TEST_P(MaximumNumberOfSubsequencesAfterOneInsertingTest, BasicPattern) {
  // "LCT": original 1; insert L at front gives CT pairs = 1 -> 2.
  EXPECT_EQ(2, solution_.numOfSubsequences("LCT"));
  // "LC": insert T at end gives +1 -> 1.
  EXPECT_EQ(1, solution_.numOfSubsequences("LC"));
  // There is no original C, so the best insertion is between L and T.
  EXPECT_EQ(1, solution_.numOfSubsequences("LT"));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfSubsequencesAfterOneInsertingTests,
    MaximumNumberOfSubsequencesAfterOneInsertingTest,
    ::testing::ValuesIn(
        MaximumNumberOfSubsequencesAfterOneInsertingSolution{}
            .getStrategyNames()));

}  // namespace leetcode::problem_3628
