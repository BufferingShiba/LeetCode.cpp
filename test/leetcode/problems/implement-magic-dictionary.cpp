#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/implement-magic-dictionary.h"

namespace leetcode::problem_676 {

class ImplementMagicDictionaryTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override { static_cast<void>(GetParam()); }
};

TEST_P(ImplementMagicDictionaryTest, Example1) {
  ImplementMagicDictionarySolution sol;
  sol.buildDict(std::vector<std::string>{"hello", "leetcode"});
  EXPECT_FALSE(sol.search("hello"));
  EXPECT_TRUE(sol.search("hhllo"));
  EXPECT_FALSE(sol.search("hell"));
  EXPECT_FALSE(sol.search("leetcoded"));
}

TEST_P(ImplementMagicDictionaryTest, SingleWord) {
  ImplementMagicDictionarySolution sol;
  sol.buildDict(std::vector<std::string>{"ab"});
  // "ab" only matches itself -> need exactly one diff, so false.
  EXPECT_FALSE(sol.search("ab"));
  EXPECT_TRUE(sol.search("ac"));
  EXPECT_TRUE(sol.search("zb"));
  EXPECT_FALSE(sol.search("abc"));
}

TEST_P(ImplementMagicDictionaryTest, TwoWordsShareLastVariant) {
  ImplementMagicDictionarySolution sol;
  sol.buildDict(std::vector<std::string>{"abc", "abd"});
  // "abc" and "abd" differ at exactly one position.
  EXPECT_TRUE(sol.search("abc"));
  EXPECT_TRUE(sol.search("abd"));
  // "abe" differs from "abc" by last char -> matches "abc".
  EXPECT_TRUE(sol.search("abe"));
  // "axy" differs from "abc" by two chars -> no single-char diff word.
  EXPECT_FALSE(sol.search("axy"));
}

INSTANTIATE_TEST_SUITE_P(
    ImplementMagicDictionaryTestSuite, ImplementMagicDictionaryTest,
    ::testing::Values(0));

}  // namespace leetcode::problem_676
