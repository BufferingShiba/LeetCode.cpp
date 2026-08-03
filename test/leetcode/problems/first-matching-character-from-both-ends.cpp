#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/first-matching-character-from-both-ends.h"

namespace leetcode::problem_3884 {

class FirstMatchingCharacterFromBothEndsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FirstMatchingCharacterFromBothEndsSolution solution_;
};

TEST_P(FirstMatchingCharacterFromBothEndsTest, Example1) {
  EXPECT_EQ(solution_.firstMatchingIndex("abcacbd"), 1);
}

TEST_P(FirstMatchingCharacterFromBothEndsTest, Example2) {
  EXPECT_EQ(solution_.firstMatchingIndex("abc"), 1);
}

TEST_P(FirstMatchingCharacterFromBothEndsTest, Example3) {
  EXPECT_EQ(solution_.firstMatchingIndex("abcdab"), -1);
}

TEST_P(FirstMatchingCharacterFromBothEndsTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution_.firstMatchingIndex("a"), 0);
}

TEST_P(FirstMatchingCharacterFromBothEndsTest, SelfAuthoredPalindrome) {
  EXPECT_EQ(solution_.firstMatchingIndex("abccba"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    FirstMatchingCharacterFromBothEndsTestCases,
    FirstMatchingCharacterFromBothEndsTest,
    ::testing::ValuesIn(FirstMatchingCharacterFromBothEndsSolution().getStrategyNames()));

}  // namespace leetcode::problem_3884
