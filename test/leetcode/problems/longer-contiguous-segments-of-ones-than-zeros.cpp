#include "leetcode/problems/longer-contiguous-segments-of-ones-than-zeros.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1869 {

class LongerContiguousSegmentsOfOnesThanZerosTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongerContiguousSegmentsOfOnesThanZerosSolution solution;
};

TEST_P(LongerContiguousSegmentsOfOnesThanZerosTest, Example1) {
  EXPECT_EQ(true, solution.checkZeroOnes("1101"));
}

// ===== Official Example 1 (from LeetCode) =====
// Input:  s = "1101"
// Output: true
TEST_P(LongerContiguousSegmentsOfOnesThanZerosTest, OfficialExample1) {
  EXPECT_EQ(true, solution.checkZeroOnes("1101"));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  s = "111000"
// Output: false
TEST_P(LongerContiguousSegmentsOfOnesThanZerosTest, OfficialExample2) {
  EXPECT_EQ(false, solution.checkZeroOnes("111000"));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  s = "110100010"
// Output: false
TEST_P(LongerContiguousSegmentsOfOnesThanZerosTest, OfficialExample3) {
  EXPECT_EQ(false, solution.checkZeroOnes("110100010"));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, LongerContiguousSegmentsOfOnesThanZerosTest,
    ::testing::ValuesIn(LongerContiguousSegmentsOfOnesThanZerosSolution().getStrategyNames()));

}  // namespace problem_1869
}  // namespace leetcode
