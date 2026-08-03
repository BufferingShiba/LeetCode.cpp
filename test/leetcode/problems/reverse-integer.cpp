#include "leetcode/problems/reverse-integer.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_7 {

class ReverseIntegerTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ReverseIntegerSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  x = 123
// Output: 321
TEST_P(ReverseIntegerTest, OfficialExample1) {
  int r = solution.reverse(123);
  EXPECT_EQ(321, r);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  x = -123
// Output: -321
TEST_P(ReverseIntegerTest, OfficialExample2) {
  int r = solution.reverse(-123);
  EXPECT_EQ(-321, r);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  x = 120
// Output: 21
TEST_P(ReverseIntegerTest, OfficialExample3) {
  int r = solution.reverse(120);
  EXPECT_EQ(21, r);
}

// ===== Overflow Case =====
// Input:  x = 1534236469
// Output: 0 (reversed 9646324351 > INT_MAX)
TEST_P(ReverseIntegerTest, OverflowCase) {
  int r = solution.reverse(1534236469);
  EXPECT_EQ(0, r);
}

// ===== INT_MIN Negative Overflow =====
// Input:  x = -2147483648
// Output: 0 (reversed -8463847412 < INT_MIN)
TEST_P(ReverseIntegerTest, NegativeOverflowCase) {
  int r = solution.reverse(-2147483648);
  EXPECT_EQ(0, r);
}

// ===== Single Digit =====
// Input:  x = 0
// Output: 0
TEST_P(ReverseIntegerTest, SingleDigitZero) {
  int r = solution.reverse(0);
  EXPECT_EQ(0, r);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, ReverseIntegerTest,
    ::testing::ValuesIn(ReverseIntegerSolution().getStrategyNames()));

}  // namespace problem_7
}  // namespace leetcode
