#include <gtest/gtest.h>

#include "leetcode/problems/maximum-substrings-with-distinct-start.h"

#include <string>

namespace leetcode::problem_3760 {

class MaximumSubstringsWithDistinctStartTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumSubstringsWithDistinctStartSolution solution;
};

TEST_P(MaximumSubstringsWithDistinctStartTest, Example1Abab) {
  EXPECT_EQ(solution.maxDistinct("abab"), 2);
}

TEST_P(MaximumSubstringsWithDistinctStartTest, Example2Abcd) {
  EXPECT_EQ(solution.maxDistinct("abcd"), 4);
}

TEST_P(MaximumSubstringsWithDistinctStartTest, Example3Aaaa) {
  EXPECT_EQ(solution.maxDistinct("aaaa"), 1);
}

TEST_P(MaximumSubstringsWithDistinctStartTest, SelfAuthoredSingleCharacter) {
  EXPECT_EQ(solution.maxDistinct("a"), 1);
}

TEST_P(MaximumSubstringsWithDistinctStartTest, SelfAuthoredAllDistinctLong) {
  EXPECT_EQ(solution.maxDistinct("zabcdefghijklmnopqrstuvwxy"), 26);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumSubstringsWithDistinctStartTestSuite,
    MaximumSubstringsWithDistinctStartTest,
    ::testing::ValuesIn(
        MaximumSubstringsWithDistinctStartSolution().getStrategyNames()));

}  // namespace leetcode::problem_3760
