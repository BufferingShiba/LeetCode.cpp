#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/valid-word.h"

namespace leetcode::problem_3136 {

class ValidWordTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ValidWordSolution solution;
};

TEST_P(ValidWordTest, Example1) {
  EXPECT_TRUE(solution.isValid("234Adas"));
}

TEST_P(ValidWordTest, Example2) {
  EXPECT_FALSE(solution.isValid("b3"));
}

TEST_P(ValidWordTest, Example3) {
  EXPECT_FALSE(solution.isValid("a3$e"));
}

TEST_P(ValidWordTest, SelfAuthoredVowelOnlyNoConsonant) {
  EXPECT_FALSE(solution.isValid("aE"));
}

TEST_P(ValidWordTest, SelfAuthoredConsonantOnlyNoVowel) {
  EXPECT_FALSE(solution.isValid("bcd"));
}

TEST_P(ValidWordTest, SelfAuthoredDigitsWithLetters) {
  EXPECT_TRUE(solution.isValid("a1b"));
}

INSTANTIATE_TEST_SUITE_P(
    ValidWordTests, ValidWordTest,
    ::testing::ValuesIn(ValidWordSolution().getStrategyNames()));

}  // namespace leetcode::problem_3136
