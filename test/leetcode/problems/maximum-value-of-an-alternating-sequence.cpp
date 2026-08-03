#include "leetcode/problems/maximum-value-of-an-alternating-sequence.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3993 {

class MaximumValueOfAnAlternatingSequenceTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumValueOfAnAlternatingSequenceSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 4, s = 3, m = 5
// Output: 12
TEST_P(MaximumValueOfAnAlternatingSequenceTest, OfficialExample1) {
  long result = solution.maximumValue(4, 3, 5);
  EXPECT_EQ(12, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 2, s = 4, m = 3
// Output: 7
TEST_P(MaximumValueOfAnAlternatingSequenceTest, OfficialExample2) {
  long result = solution.maximumValue(2, 4, 3);
  EXPECT_EQ(7, result);
}

// ===== SelfAuthored edge case: length 1 =====
// Input:  n = 1, s = 100, m = 5
// Output: 100 (a sequence of length 1 is trivially alternating)
TEST_P(MaximumValueOfAnAlternatingSequenceTest, EdgeCaseSingleElement) {
  long result = solution.maximumValue(1, 100, 5);
  EXPECT_EQ(100, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximumValueOfAnAlternatingSequenceTest,
    ::testing::ValuesIn(MaximumValueOfAnAlternatingSequenceSolution().getStrategyNames()));

}  // namespace problem_3993
}  // namespace leetcode
