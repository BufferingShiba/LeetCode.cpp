#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/existence-of-a-substring-in-a-string-and-its-reverse.h"

using leetcode::problem_3083::ExistenceOfASubstringInAStringAndItsReverseSolution;

class ExistenceOfASubstringInAStringAndItsReverseTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ExistenceOfASubstringInAStringAndItsReverseSolution solution_;
};

TEST_P(ExistenceOfASubstringInAStringAndItsReverseTest, Example1) {
  EXPECT_TRUE(solution_.isSubstringPresent("leetcode"));
}

TEST_P(ExistenceOfASubstringInAStringAndItsReverseTest, Example2) {
  EXPECT_TRUE(solution_.isSubstringPresent("abcba"));
}

TEST_P(ExistenceOfASubstringInAStringAndItsReverseTest, Example3) {
  EXPECT_FALSE(solution_.isSubstringPresent("abcd"));
}

TEST_P(ExistenceOfASubstringInAStringAndItsReverseTest, SelfAuthoredSingleCharacter) {
  EXPECT_FALSE(solution_.isSubstringPresent("a"));
}

TEST_P(ExistenceOfASubstringInAStringAndItsReverseTest, SelfAuthoredTwoSameCharacters) {
  EXPECT_TRUE(solution_.isSubstringPresent("aa"));
}

TEST_P(ExistenceOfASubstringInAStringAndItsReverseTest, SelfAuthoredTwoDistinctCharacters) {
  EXPECT_FALSE(solution_.isSubstringPresent("ab"));
}

INSTANTIATE_TEST_SUITE_P(
    ExistenceOfASubstringInAStringAndItsReverseTestInstance,
    ExistenceOfASubstringInAStringAndItsReverseTest,
    ::testing::ValuesIn(
        ExistenceOfASubstringInAStringAndItsReverseSolution()
            .getStrategyNames()));
