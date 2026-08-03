#include "leetcode/problems/sum-of-square-numbers.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_633 {

class SumOfSquareNumbersTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SumOfSquareNumbersSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  c = 5
// Output: true
TEST_P(SumOfSquareNumbersTest, OfficialExample1) {
  bool result = solution.judgeSquareSum(5);
  EXPECT_EQ(true, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  c = 3
// Output: false
TEST_P(SumOfSquareNumbersTest, OfficialExample2) {
  bool result = solution.judgeSquareSum(3);
  EXPECT_EQ(false, result);
}

// ===== SelfAuthored: c = 0 (0^2 + 0^2) =====
TEST_P(SumOfSquareNumbersTest, SelfAuthoredZero) {
  bool result = solution.judgeSquareSum(0);
  EXPECT_EQ(true, result);
}

// ===== SelfAuthored: c = 2 (1^2 + 1^2) =====
TEST_P(SumOfSquareNumbersTest, SelfAuthoredTwo) {
  bool result = solution.judgeSquareSum(2);
  EXPECT_EQ(true, result);
}

// ===== SelfAuthored: c = 4 (0^2 + 2^2) =====
TEST_P(SumOfSquareNumbersTest, SelfAuthoredFour) {
  bool result = solution.judgeSquareSum(4);
  EXPECT_EQ(true, result);
}

// ===== SelfAuthored: c = 1 (0^2 + 1^2) =====
TEST_P(SumOfSquareNumbersTest, SelfAuthoredOne) {
  bool result = solution.judgeSquareSum(1);
  EXPECT_EQ(true, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, SumOfSquareNumbersTest,
    ::testing::ValuesIn(SumOfSquareNumbersSolution().getStrategyNames()));

}  // namespace problem_633
}  // namespace leetcode
