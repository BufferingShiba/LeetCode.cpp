#include "leetcode/problems/decode-string.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_394 {

class DecodeStringTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DecodeStringSolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, DecodeStringTest,
    ::testing::ValuesIn(DecodeStringSolution().getStrategyNames()));

// ===== Official Example 1 (from LeetCode) =====
// Input:  s = "3[a]2[bc]"
// Output: "aaabcbc"
TEST_P(DecodeStringTest, OfficialExample1) {
  EXPECT_EQ("aaabcbc", solution.decodeString("3[a]2[bc]"));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  s = "3[a2[c]]"
// Output: "accaccacc"
TEST_P(DecodeStringTest, OfficialExample2) {
  EXPECT_EQ("accaccacc", solution.decodeString("3[a2[c]]"));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"
TEST_P(DecodeStringTest, OfficialExample3) {
  EXPECT_EQ("abcabccdcdcdef", solution.decodeString("2[abc]3[cd]ef"));
}

}  // namespace problem_394
}  // namespace leetcode
