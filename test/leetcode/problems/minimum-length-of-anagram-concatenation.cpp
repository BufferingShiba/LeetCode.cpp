#include "leetcode/problems/minimum-length-of-anagram-concatenation.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3138 {

class MinimumLengthOfAnagramConcatenationTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumLengthOfAnagramConcatenationSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  s = "abba"
// Output: 2
TEST_P(MinimumLengthOfAnagramConcatenationTest, OfficialExample1) {
  int result = solution.minAnagramLength("abba");
  EXPECT_EQ(2, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  s = "cdef"
// Output: 4
TEST_P(MinimumLengthOfAnagramConcatenationTest, OfficialExample2) {
  int result = solution.minAnagramLength("cdef");
  EXPECT_EQ(4, result);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  s = "abcbcacabbaccba"
// Output: 3
TEST_P(MinimumLengthOfAnagramConcatenationTest, OfficialExample3) {
  int result = solution.minAnagramLength("abcbcacabbaccba");
  EXPECT_EQ(3, result);
}

// ===== Edge case: single character =====
// Input:  s = "a"
// Output: 1
TEST_P(MinimumLengthOfAnagramConcatenationTest, SingleCharacter) {
  int result = solution.minAnagramLength("a");
  EXPECT_EQ(1, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumLengthOfAnagramConcatenationTest,
    ::testing::ValuesIn(MinimumLengthOfAnagramConcatenationSolution().getStrategyNames()));

}  // namespace problem_3138
}  // namespace leetcode
