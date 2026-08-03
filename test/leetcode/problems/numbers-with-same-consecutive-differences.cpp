#include "leetcode/problems/numbers-with-same-consecutive-differences.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_967 {

class NumbersWithSameConsecutiveDifferencesTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumbersWithSameConsecutiveDifferencesSolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, NumbersWithSameConsecutiveDifferencesTest,
    ::testing::ValuesIn(NumbersWithSameConsecutiveDifferencesSolution().getStrategyNames()));

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 3, k = 7
// Output: [181,292,707,818,929]
TEST_P(NumbersWithSameConsecutiveDifferencesTest, OfficialExample1) {
  std::vector<int> expected = {181, 292, 707, 818, 929};
  std::vector<int> result = solution.numsSameConsecDiff(3, 7);
  EXPECT_EQ(expected, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 2, k = 1
// Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
TEST_P(NumbersWithSameConsecutiveDifferencesTest, OfficialExample2) {
  std::vector<int> expected = {10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65, 67, 76, 78, 87, 89, 98};
  std::vector<int> result = solution.numsSameConsecDiff(2, 1);
  EXPECT_EQ(expected, result);
}

}  // namespace problem_967
}  // namespace leetcode
