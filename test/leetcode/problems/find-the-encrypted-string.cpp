#include <gtest/gtest.h>

#include "leetcode/problems/find-the-encrypted-string.h"

using namespace leetcode::problem_3210;

class FindTheEncryptedStringTest : public testing::TestWithParam<std::string> {
 protected:
  FindTheEncryptedStringSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(FindTheEncryptedStringTest, Example1) {
  EXPECT_EQ(solution.getEncryptedString("dart", 3), "tdar");
}

TEST_P(FindTheEncryptedStringTest, Example2) {
  EXPECT_EQ(solution.getEncryptedString("aaa", 1), "aaa");
}

TEST_P(FindTheEncryptedStringTest, SelfAuthored1) {
  EXPECT_EQ(solution.getEncryptedString("abc", 1), "bca");
}

TEST_P(FindTheEncryptedStringTest, SelfAuthored2) {
  EXPECT_EQ(solution.getEncryptedString("abcd", 2), "cdab");
}

INSTANTIATE_TEST_SUITE_P(Strategies, FindTheEncryptedStringTest,
                         testing::ValuesIn(FindTheEncryptedStringSolution().getStrategyNames()));
