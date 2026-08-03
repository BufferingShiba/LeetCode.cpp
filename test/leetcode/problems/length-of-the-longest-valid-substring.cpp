#include "leetcode/problems/length-of-the-longest-valid-substring.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2781 {

class LengthOfTheLongestValidSubstringTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  LengthOfTheLongestValidSubstringSolution solution;
};

TEST_P(LengthOfTheLongestValidSubstringTest, Example1) {
  std::string word = "cbaaaabc";
  std::vector<std::string> forbidden = {"aaa", "cb"};
  EXPECT_EQ(4, solution.longestValidSubstring(word, forbidden));
}

TEST_P(LengthOfTheLongestValidSubstringTest, Example2) {
  std::string word = "leetcode";
  std::vector<std::string> forbidden = {"de", "le", "e"};
  EXPECT_EQ(4, solution.longestValidSubstring(word, forbidden));
}

TEST_P(LengthOfTheLongestValidSubstringTest, SelfAuthoredNoForbidden) {
  std::string word = "abc";
  std::vector<std::string> forbidden = {"zz"};
  EXPECT_EQ(3, solution.longestValidSubstring(word, forbidden));
}

TEST_P(LengthOfTheLongestValidSubstringTest, SelfAuthoredSingleForbiddenCoverWhole) {
  std::string word = "aaaa";
  std::vector<std::string> forbidden = {"aa"};
  // longest valid substring avoiding "aa"
  EXPECT_EQ(1, solution.longestValidSubstring(word, forbidden));
}

TEST_P(LengthOfTheLongestValidSubstringTest, SelfAuthoredEmptyForbiddenList) {
  std::string word = "hello";
  std::vector<std::string> forbidden = {};
  EXPECT_EQ(5, solution.longestValidSubstring(word, forbidden));
}

INSTANTIATE_TEST_SUITE_P(
    LengthOfTheLongestValidSubstringTestSuite,
    LengthOfTheLongestValidSubstringTest,
    ::testing::ValuesIn(LengthOfTheLongestValidSubstringSolution().getStrategyNames()));

}  // namespace problem_2781
}  // namespace leetcode
