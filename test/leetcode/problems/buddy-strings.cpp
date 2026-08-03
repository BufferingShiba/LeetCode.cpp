#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/buddy-strings.h"

namespace leetcode {
namespace problem_859 {

class BuddyStringsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BuddyStringsSolution solution;
};

TEST_P(BuddyStringsTest, Example1) {
  EXPECT_TRUE(solution.buddyStrings("ab", "ba"));
}

TEST_P(BuddyStringsTest, Example2) {
  EXPECT_FALSE(solution.buddyStrings("ab", "ab"));
}

TEST_P(BuddyStringsTest, Example3) {
  EXPECT_TRUE(solution.buddyStrings("aa", "aa"));
}

TEST_P(BuddyStringsTest, SelfAuthoredDifferentLengths) {
  EXPECT_FALSE(solution.buddyStrings("ab", "a"));
}

TEST_P(BuddyStringsTest, SelfAuthoredMultiMismatch) {
  EXPECT_FALSE(solution.buddyStrings("abcd", "badc"));
}

TEST_P(BuddyStringsTest, SelfAuthoredTwoMismatchSwapWorks) {
  EXPECT_TRUE(solution.buddyStrings("abca", "acba"));
}

INSTANTIATE_TEST_SUITE_P(
    BuddyStringsStrategies, BuddyStringsTest,
    ::testing::ValuesIn(BuddyStringsSolution().getStrategyNames()));

}  // namespace problem_859
}  // namespace leetcode
