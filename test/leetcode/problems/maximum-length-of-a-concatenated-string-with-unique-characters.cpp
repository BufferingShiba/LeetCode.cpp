#include "leetcode/problems/maximum-length-of-a-concatenated-string-with-unique-characters.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1239 {

class MaximumLengthOfAConcatenatedStringWithUniqueCharactersTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumLengthOfAConcatenatedStringWithUniqueCharactersSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  arr = ["un","iq","ue"]
// Output: 4
TEST_P(MaximumLengthOfAConcatenatedStringWithUniqueCharactersTest, OfficialExample1) {
  vector<string> arr = {"un", "iq", "ue"};
  int r = solution.maxLength(arr);
  EXPECT_EQ(4, r);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  arr = ["cha","r","act","ers"]
// Output: 6
TEST_P(MaximumLengthOfAConcatenatedStringWithUniqueCharactersTest, OfficialExample2) {
  vector<string> arr = {"cha", "r", "act", "ers"};
  int r = solution.maxLength(arr);
  EXPECT_EQ(6, r);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  arr = ["abcdefghijklmnopqrstuvwxyz"]
// Output: 26
TEST_P(MaximumLengthOfAConcatenatedStringWithUniqueCharactersTest, OfficialExample3) {
  vector<string> arr = {"abcdefghijklmnopqrstuvwxyz"};
  int r = solution.maxLength(arr);
  EXPECT_EQ(26, r);
}

// ===== Self-authored edge case: string with duplicate characters (whole string
//       unusable, but subsets may still combine) =====
TEST_P(MaximumLengthOfAConcatenatedStringWithUniqueCharactersTest, EdgeCaseDuplicateInternal) {
  vector<string> arr = {"aabc", "def"};
  int r = solution.maxLength(arr);
  // "aabc" has duplicate 'a', cannot be used by itself; "def" alone gives 3.
  EXPECT_EQ(3, r);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximumLengthOfAConcatenatedStringWithUniqueCharactersTest,
    ::testing::ValuesIn(MaximumLengthOfAConcatenatedStringWithUniqueCharactersSolution().getStrategyNames()));

}  // namespace problem_1239
}  // namespace leetcode
