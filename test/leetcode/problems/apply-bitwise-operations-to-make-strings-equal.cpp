#include "leetcode/problems/apply-bitwise-operations-to-make-strings-equal.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2546 {

class ApplyBitwiseOperationsToMakeStringsEqualTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ApplyBitwiseOperationsToMakeStringsEqualSolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, ApplyBitwiseOperationsToMakeStringsEqualTest,
    ::testing::ValuesIn(ApplyBitwiseOperationsToMakeStringsEqualSolution().getStrategyNames()));

// ===== Official Example 1 (from LeetCode) =====
// Input:  s = "1010", target = "0110"
// Output: true
TEST_P(ApplyBitwiseOperationsToMakeStringsEqualTest, OfficialExample1) {
  bool result = solution.makeStringsEqual("1010", "0110");
  EXPECT_EQ(true, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  s = "11", target = "00"
// Output: false
TEST_P(ApplyBitwiseOperationsToMakeStringsEqualTest, OfficialExample2) {
  bool result = solution.makeStringsEqual("11", "00");
  EXPECT_EQ(false, result);
}

// ===== SelfAuthored: both all-zero =====
TEST_P(ApplyBitwiseOperationsToMakeStringsEqualTest, BothAllZero) {
  EXPECT_EQ(true, solution.makeStringsEqual("0000", "0000"));
}

// ===== SelfAuthored: one has one, one all-zero =====
TEST_P(ApplyBitwiseOperationsToMakeStringsEqualTest, OneHasOneOtherZero) {
  EXPECT_EQ(false, solution.makeStringsEqual("0010", "0000"));
  EXPECT_EQ(false, solution.makeStringsEqual("0000", "0100"));
}

// ===== SelfAuthored: both have ones but different counts =====
TEST_P(ApplyBitwiseOperationsToMakeStringsEqualTest, BothHaveOnes) {
  EXPECT_EQ(true, solution.makeStringsEqual("1000", "0001"));
  EXPECT_EQ(true, solution.makeStringsEqual("101010", "010101"));
}

}  // namespace problem_2546
}  // namespace leetcode
