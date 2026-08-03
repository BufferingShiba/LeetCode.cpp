#include "leetcode/problems/longest-common-prefix.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_14 {

class LongestCommonPrefixTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestCommonPrefixSolution solution;
};

TEST_P(LongestCommonPrefixTest, Example1) {
  std::vector<std::string> strs = {"flower", "flow", "flight"};
  EXPECT_EQ(std::string("fl"), solution.longestCommonPrefix(strs));
}

// ===== Official Example 1 (from LeetCode) =====
// Input:  strs = ["flower","flow","flight"]
// Output: "fl"
TEST_P(LongestCommonPrefixTest, OfficialExample1) {
  std::vector<std::string> strs = {"flower", "flow", "flight"};
  EXPECT_EQ(std::string("fl"), solution.longestCommonPrefix(strs));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  strs = ["dog","racecar","car"]
// Output: ""
TEST_P(LongestCommonPrefixTest, OfficialExample2) {
  std::vector<std::string> strs = {"dog", "racecar", "car"};
  EXPECT_EQ(std::string(""), solution.longestCommonPrefix(strs));
}

// SelfAuthored: single string returns itself
TEST_P(LongestCommonPrefixTest, SingleString) {
  std::vector<std::string> strs = {"leetcode"};
  EXPECT_EQ(std::string("leetcode"), solution.longestCommonPrefix(strs));
}

// SelfAuthored: empty first string yields empty prefix
TEST_P(LongestCommonPrefixTest, EmptyFirstString) {
  std::vector<std::string> strs = {"", "abc", "abd"};
  EXPECT_EQ(std::string(""), solution.longestCommonPrefix(strs));
}

// SelfAuthored: identical strings return the whole string
TEST_P(LongestCommonPrefixTest, IdenticalStrings) {
  std::vector<std::string> strs = {"abc", "abc", "abc"};
  EXPECT_EQ(std::string("abc"), solution.longestCommonPrefix(strs));
}

// SelfAuthored: prefix ends when a string is shorter
TEST_P(LongestCommonPrefixTest, ShorterStringEndsPrefix) {
  std::vector<std::string> strs = {"abc", "ab", "abcd"};
  EXPECT_EQ(std::string("ab"), solution.longestCommonPrefix(strs));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, LongestCommonPrefixTest,
    ::testing::ValuesIn(LongestCommonPrefixSolution().getStrategyNames()));

}  // namespace problem_14
}  // namespace leetcode
