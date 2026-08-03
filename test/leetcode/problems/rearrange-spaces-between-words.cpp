#include <gtest/gtest.h>

#include "leetcode/problems/rearrange-spaces-between-words.h"

using namespace leetcode::problem_1592;

class RearrangeSpacesBetweenWordsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RearrangeSpacesBetweenWordsSolution solution;
};

TEST_P(RearrangeSpacesBetweenWordsTest, Example1) {
  EXPECT_EQ(solution.reorderSpaces("  this   is  a sentence "),
            "this   is   a   sentence");
}

TEST_P(RearrangeSpacesBetweenWordsTest, Example2) {
  EXPECT_EQ(solution.reorderSpaces(" practice   makes   perfect"),
            "practice   makes   perfect ");
}

TEST_P(RearrangeSpacesBetweenWordsTest, SelfAuthoredSingleWord) {
  EXPECT_EQ(solution.reorderSpaces("hello"), "hello");
}

TEST_P(RearrangeSpacesBetweenWordsTest, SelfAuthoredSingleWordWithSpaces) {
  EXPECT_EQ(solution.reorderSpaces("  hello  "), "hello    ");
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies, RearrangeSpacesBetweenWordsTest,
    testing::ValuesIn(RearrangeSpacesBetweenWordsSolution().getStrategyNames()));
