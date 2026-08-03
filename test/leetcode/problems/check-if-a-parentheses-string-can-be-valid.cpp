#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/check-if-a-parentheses-string-can-be-valid.h"

namespace leetcode {
namespace problem_2116 {

class CheckIfAParenthesesStringCanBeValidTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CheckIfAParenthesesStringCanBeValidSolution solution_;
};

TEST_P(CheckIfAParenthesesStringCanBeValidTest, Example1) {
  EXPECT_TRUE(solution_.canBeValid("))()))", "010100"));
}

TEST_P(CheckIfAParenthesesStringCanBeValidTest, Example2) {
  EXPECT_TRUE(solution_.canBeValid("()()", "0000"));
}

TEST_P(CheckIfAParenthesesStringCanBeValidTest, Example3) {
  EXPECT_FALSE(solution_.canBeValid(")", "0"));
}

TEST_P(CheckIfAParenthesesStringCanBeValidTest, Example4) {
  EXPECT_TRUE(solution_.canBeValid("(((())(((())", "111111010111"));
}

TEST_P(CheckIfAParenthesesStringCanBeValidTest, OddLength) {
  EXPECT_FALSE(solution_.canBeValid("()(", "000"));
}

TEST_P(CheckIfAParenthesesStringCanBeValidTest, AllLockedValid) {
  EXPECT_TRUE(solution_.canBeValid("()()", "1111"));
}

TEST_P(CheckIfAParenthesesStringCanBeValidTest, AllLockedInvalid) {
  EXPECT_FALSE(solution_.canBeValid("))((", "1111"));
}

TEST_P(CheckIfAParenthesesStringCanBeValidTest, AllUnlockedEven) {
  // 6 chars, all unlocked, can be rearranged to "((()))" for example
  EXPECT_TRUE(solution_.canBeValid(")))(((", "000000"));
}

TEST_P(CheckIfAParenthesesStringCanBeValidTest, SingleCharUnlocked) {
  EXPECT_FALSE(solution_.canBeValid("(", "0"));
}

TEST_P(CheckIfAParenthesesStringCanBeValidTest, SingleCharLocked) {
  EXPECT_FALSE(solution_.canBeValid("(", "1"));
}

TEST_P(CheckIfAParenthesesStringCanBeValidTest, WildcardAsCloseNeeded) {
  // "((" locked="10" — pos 0 locked '(', pos 1 unlocked → need ')' → "()"
  EXPECT_TRUE(solution_.canBeValid("((", "10"));
}

TEST_P(CheckIfAParenthesesStringCanBeValidTest, WildcardAsOpenNeeded) {
  // "))" locked="01" — pos 0 unlocked, pos 1 locked ')' → need '(' → "()"
  EXPECT_TRUE(solution_.canBeValid("))", "01"));
}

TEST_P(CheckIfAParenthesesStringCanBeValidTest, LockedConflict) {
  // ")(" locked="11" — both locked, already invalid
  EXPECT_FALSE(solution_.canBeValid(")(", "11"));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, CheckIfAParenthesesStringCanBeValidTest,
    ::testing::ValuesIn(
        CheckIfAParenthesesStringCanBeValidSolution().getStrategyNames()));

}  // namespace problem_2116
}  // namespace leetcode
