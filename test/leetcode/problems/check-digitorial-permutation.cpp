#include "leetcode/problems/check-digitorial-permutation.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3848 {

class CheckDigitorialPermutationTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CheckDigitorialPermutationSolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, CheckDigitorialPermutationTest,
    ::testing::ValuesIn(CheckDigitorialPermutationSolution().getStrategyNames()));

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 145
// Output: true
TEST_P(CheckDigitorialPermutationTest, OfficialExample1) {
  EXPECT_EQ(true, solution.isDigitorialPermutation(145));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 10
// Output: false
TEST_P(CheckDigitorialPermutationTest, OfficialExample2) {
  EXPECT_EQ(false, solution.isDigitorialPermutation(10));
}

// ===== Self-authored edge cases =====
// The known factorion 40585: 4!+0!+5!+8!+5! = 24+1+120+40320+120 = 40585
TEST_P(CheckDigitorialPermutationTest, SelfAuthoredFactorion) {
  EXPECT_EQ(true, solution.isDigitorialPermutation(40585));
}

// 169: 1!+6!+9! = 1+720+362880 = 363601, not a permutation of 169.
TEST_P(CheckDigitorialPermutationTest, SelfAuthoredNonFactorion) {
  EXPECT_EQ(false, solution.isDigitorialPermutation(169));
}

// Single digit 2: 2! = 2, permutation multiset {2} matches.
TEST_P(CheckDigitorialPermutationTest, SelfAuthoredSingleDigit) {
  EXPECT_EQ(true, solution.isDigitorialPermutation(2));
}

}  // namespace problem_3848
}  // namespace leetcode
