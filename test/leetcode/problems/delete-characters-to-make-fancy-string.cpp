#include <gtest/gtest.h>

#include "leetcode/problems/delete-characters-to-make-fancy-string.h"

using namespace leetcode::problem_1957;

class DeleteCharactersToMakeFancyStringTest : public ::testing::TestWithParam<std::string> {
 protected:
  DeleteCharactersToMakeFancyStringSolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(DeleteCharactersToMakeFancyStringTest, Example1) {
  EXPECT_EQ(solution.makeFancyString("leeetcode"), "leetcode");
}

TEST_P(DeleteCharactersToMakeFancyStringTest, Example2) {
  EXPECT_EQ(solution.makeFancyString("aaabaaaa"), "aabaa");
}

TEST_P(DeleteCharactersToMakeFancyStringTest, Example3) {
  EXPECT_EQ(solution.makeFancyString("aab"), "aab");
}

TEST_P(DeleteCharactersToMakeFancyStringTest, SelfAuthored) {
  EXPECT_EQ(solution.makeFancyString("a"), "a");
  EXPECT_EQ(solution.makeFancyString("aa"), "aa");
  EXPECT_EQ(solution.makeFancyString("aaa"), "aa");
  EXPECT_EQ(solution.makeFancyString("aaaa"), "aa");
  EXPECT_EQ(solution.makeFancyString("ab"), "ab");
  EXPECT_EQ(solution.makeFancyString("aabbcc"), "aabbcc");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    DeleteCharactersToMakeFancyStringTest,
    ::testing::ValuesIn(DeleteCharactersToMakeFancyStringSolution().getStrategyNames()));
