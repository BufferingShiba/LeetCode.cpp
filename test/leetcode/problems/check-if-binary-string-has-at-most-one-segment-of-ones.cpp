#include <gtest/gtest.h>

#include "leetcode/problems/check-if-binary-string-has-at-most-one-segment-of-ones.h"

using namespace leetcode::problem_1784;

class CheckIfBinaryStringHasAtMostOneSegmentOfOnesTest : public testing::TestWithParam<std::string> {
 protected:
  CheckIfBinaryStringHasAtMostOneSegmentOfOnesSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(CheckIfBinaryStringHasAtMostOneSegmentOfOnesTest, OfficialExamples) {
  EXPECT_FALSE(solution.checkOnesSegment("1001"));
  EXPECT_TRUE(solution.checkOnesSegment("110"));
}

TEST_P(CheckIfBinaryStringHasAtMostOneSegmentOfOnesTest, SelfAuthored) {
  // Single character, one segment
  EXPECT_TRUE(solution.checkOnesSegment("1"));
  // Two segments separated by zero
  EXPECT_FALSE(solution.checkOnesSegment("101"));
  // All ones
  EXPECT_TRUE(solution.checkOnesSegment("111"));
}

INSTANTIATE_TEST_SUITE_P(Strategies, CheckIfBinaryStringHasAtMostOneSegmentOfOnesTest,
                         testing::ValuesIn(CheckIfBinaryStringHasAtMostOneSegmentOfOnesSolution()
                                               .getStrategyNames()));
