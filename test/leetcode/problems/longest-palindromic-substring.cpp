#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/longest-palindromic-substring.h"

using namespace leetcode::problem_5;

class LongestPalindromicSubstringTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestPalindromicSubstringSolution solution;
};

// 辅助函数：判断是否为回文
bool isPalindrome(const std::string& s) {
  int left = 0;
  int right = static_cast<int>(s.size()) - 1;
  while (left < right) {
    if (s[left] != s[right]) {
      return false;
    }
    ++left;
    --right;
  }
  return true;
}

TEST_P(LongestPalindromicSubstringTest, OfficialExamples) {
  // Example 1
  {
    std::string result = solution.longestPalindrome("babad");
    EXPECT_TRUE(isPalindrome(result));
    EXPECT_EQ(result.size(), 3);
    // "bab" 或 "aba" 都合法
    EXPECT_TRUE(result == "bab" || result == "aba");
  }

  // Example 2
  {
    std::string result = solution.longestPalindrome("cbbd");
    EXPECT_EQ(result, "bb");
  }
}

TEST_P(LongestPalindromicSubstringTest, SelfAuthored) {
  // 单字符
  {
    std::string result = solution.longestPalindrome("a");
    EXPECT_EQ(result, "a");
    EXPECT_TRUE(isPalindrome(result));
  }

  // 所有字符相同
  {
    std::string result = solution.longestPalindrome("aaaa");
    EXPECT_EQ(result, "aaaa");
    EXPECT_TRUE(isPalindrome(result));
  }

  // 无长回文（两字符不同）
  {
    std::string result = solution.longestPalindrome("ab");
    EXPECT_TRUE(result == "a" || result == "b");
    EXPECT_EQ(result.size(), 1);
    EXPECT_TRUE(isPalindrome(result));
  }

  // 回文在末尾
  {
    std::string result = solution.longestPalindrome("abcba");
    EXPECT_EQ(result, "abcba");
    EXPECT_TRUE(isPalindrome(result));
  }
}

INSTANTIATE_TEST_SUITE_P(
    , LongestPalindromicSubstringTest,
    testing::ValuesIn(
        LongestPalindromicSubstringSolution().getStrategyNames()));
