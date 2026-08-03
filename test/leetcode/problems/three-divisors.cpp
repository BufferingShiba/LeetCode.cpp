#include "leetcode/problems/three-divisors.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1952 {

class ThreeDivisorsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ThreeDivisorsSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 2
// Output: false Explantion: 2 has only two divisors: 1 and 2.
TEST_P(ThreeDivisorsTest, OfficialExample1) {
  EXPECT_EQ(false, solution.isThree(2));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 4
// Output: true Explantion: 4 has three divisors: 1, 2, and 4.
TEST_P(ThreeDivisorsTest, OfficialExample2) {
  EXPECT_EQ(true, solution.isThree(4));
}

// n = 1 has only one divisor
TEST_P(ThreeDivisorsTest, OneDivisor) {
  EXPECT_EQ(false, solution.isThree(1));
}

// n = 9 = 3*3, divisors 1, 3, 9
TEST_P(ThreeDivisorsTest, SquareOfPrime) {
  EXPECT_EQ(true, solution.isThree(9));
}

// n = 6 has divisors 1, 2, 3, 6
TEST_P(ThreeDivisorsTest, CompositeNonSquare) {
  EXPECT_EQ(false, solution.isThree(6));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, ThreeDivisorsTest,
    ::testing::ValuesIn(ThreeDivisorsSolution().getStrategyNames()));

}  // namespace problem_1952
}  // namespace leetcode
