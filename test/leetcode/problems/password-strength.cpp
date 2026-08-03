#include "leetcode/problems/password-strength.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3941 {

class PasswordStrengthTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PasswordStrengthSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  password = "aA1!"
// Output: 11
TEST_P(PasswordStrengthTest, OfficialExample1) {
  int result = solution.passwordStrength("aA1!");
  EXPECT_EQ(11, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  password = "bbB11#"
// Output: 11
TEST_P(PasswordStrengthTest, OfficialExample2) {
  int result = solution.passwordStrength("bbB11#");
  EXPECT_EQ(11, result);
}

// ===== SelfAuthored: duplicates count only once =====
// password = "aA1!aA1!" -> same 4 distinct as example 1
TEST_P(PasswordStrengthTest, DuplicatesCountOnce) {
  int result = solution.passwordStrength("aA1!aA1!");
  EXPECT_EQ(11, result);
}

// ===== SelfAuthored: multiple distinct digits sum =====
// digits '1' and '2' -> 3*2 = 6; lowercase 'a' -> 1; total = 7
TEST_P(PasswordStrengthTest, MultipleDigitsAndSpecial) {
  int result = solution.passwordStrength("a12!#");
  EXPECT_EQ(1 + 3 * 2 + 5 * 2, result);  // 17
}

// ===== SelfAuthored: single character =====
// one lowercase letter -> 1
TEST_P(PasswordStrengthTest, SingleCharacter) {
  int result = solution.passwordStrength("z");
  EXPECT_EQ(1, result);
}

// ===== SelfAuthored: all four special chars =====
// "@$!" -> 5*3 = 15
TEST_P(PasswordStrengthTest, OnlySpecial) {
  int result = solution.passwordStrength("@$!");
  EXPECT_EQ(15, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, PasswordStrengthTest,
    ::testing::ValuesIn(PasswordStrengthSolution().getStrategyNames()));

}  // namespace problem_3941
}  // namespace leetcode
