#include "leetcode/problems/integer-break.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_343 {

class IntegerBreakTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  IntegerBreakSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 2
// Output: 1
TEST_P(IntegerBreakTest, OfficialExample1) {
  int result = solution.integerBreak(2);
  EXPECT_EQ(1, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 10
// Output: 36
TEST_P(IntegerBreakTest, OfficialExample2) {
  int result = solution.integerBreak(10);
  EXPECT_EQ(36, result);
}

// ===== Self-Authored Boundary =====
// n = 3: 1 + 2, product = 2
TEST_P(IntegerBreakTest, BoundaryN3) {
  int result = solution.integerBreak(3);
  EXPECT_EQ(2, result);
}

// n = 4: 2 + 2, product = 4
TEST_P(IntegerBreakTest, BoundaryN4) {
  int result = solution.integerBreak(4);
  EXPECT_EQ(4, result);
}

// n = 58 (upper constraint): known max product via 3s
TEST_P(IntegerBreakTest, BoundaryN58) {
  int result = solution.integerBreak(58);
  // 58 = 19*3 + 1, remainder 1 -> use 18*3 + 2*2 => 3^18 * 4
  // 3^18 = 387420489, *4 = 1549681956
  EXPECT_EQ(1549681956, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, IntegerBreakTest,
    ::testing::ValuesIn(IntegerBreakSolution().getStrategyNames()));

}  // namespace problem_343
}  // namespace leetcode
