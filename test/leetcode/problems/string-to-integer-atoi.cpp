#include "leetcode/problems/string-to-integer-atoi.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_8 {

class StringToIntegerAtoiTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  StringToIntegerAtoiSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  s = "42"
// Output: 42
TEST_P(StringToIntegerAtoiTest, OfficialExample1) {
  EXPECT_EQ(42, solution.myAtoi("42"));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  s = " -042"
// Output: -42
TEST_P(StringToIntegerAtoiTest, OfficialExample2) {
  EXPECT_EQ(-42, solution.myAtoi(" -042"));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  s = "1337c0d3"
// Output: 1337
TEST_P(StringToIntegerAtoiTest, OfficialExample3) {
  EXPECT_EQ(1337, solution.myAtoi("1337c0d3"));
}

// ===== Official Example 4 (from LeetCode) =====
// Input:  s = "0-1"
// Output: 0
TEST_P(StringToIntegerAtoiTest, OfficialExample4) {
  EXPECT_EQ(0, solution.myAtoi("0-1"));
}

// ===== Official Example 5 (from LeetCode) =====
// Input:  s = "words and 987"
// Output: 0
TEST_P(StringToIntegerAtoiTest, OfficialExample5) {
  EXPECT_EQ(0, solution.myAtoi("words and 987"));
}

// ===== SelfAuthored: overflow above upper bound =====
TEST_P(StringToIntegerAtoiTest, OverflowPositive) {
  EXPECT_EQ(2147483647, solution.myAtoi("2147483648"));
  EXPECT_EQ(2147483647, solution.myAtoi("91283472332"));
}

// ===== SelfAuthored: overflow below lower bound =====
TEST_P(StringToIntegerAtoiTest, OverflowNegative) {
  EXPECT_EQ(-2147483648, solution.myAtoi("-91283472332"));
  EXPECT_EQ(-2147483648, solution.myAtoi("-2147483649"));
}

// ===== SelfAuthored: boundary values stay exact =====
TEST_P(StringToIntegerAtoiTest, BoundaryValues) {
  EXPECT_EQ(2147483647, solution.myAtoi("2147483647"));
  EXPECT_EQ(-2147483648, solution.myAtoi("-2147483648"));
}

// ===== SelfAuthored: explicit plus sign and trailing junk =====
TEST_P(StringToIntegerAtoiTest, PlusSignAndTrailingJunk) {
  EXPECT_EQ(123, solution.myAtoi("  +123xy"));
  EXPECT_EQ(0, solution.myAtoi("++123"));
}

// ===== SelfAuthored: empty and only-whitespace =====
TEST_P(StringToIntegerAtoiTest, EmptyAndWhitespace) {
  EXPECT_EQ(0, solution.myAtoi(""));
  EXPECT_EQ(0, solution.myAtoi("   "));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, StringToIntegerAtoiTest,
    ::testing::ValuesIn(StringToIntegerAtoiSolution().getStrategyNames()));

}  // namespace problem_8
}  // namespace leetcode
