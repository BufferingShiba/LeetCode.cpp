#include "leetcode/problems/maximum-number-of-words-you-can-type.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_1935 {

class MaximumNumberOfWordsYouCanTypeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumNumberOfWordsYouCanTypeSolution solution;
};

TEST_P(MaximumNumberOfWordsYouCanTypeTest, Example1) {
  EXPECT_EQ(solution.canBeTypedWords("hello world", "ad"), 1);
}

TEST_P(MaximumNumberOfWordsYouCanTypeTest, Example2) {
  EXPECT_EQ(solution.canBeTypedWords("leet code", "lt"), 1);
}

TEST_P(MaximumNumberOfWordsYouCanTypeTest, Example3) {
  EXPECT_EQ(solution.canBeTypedWords("leet code", "e"), 0);
}

TEST_P(MaximumNumberOfWordsYouCanTypeTest, SelfAuthoredNoBrokenKeys) {
  EXPECT_EQ(solution.canBeTypedWords("hello world test", ""), 3);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfWordsYouCanTypeTestSuite,
    MaximumNumberOfWordsYouCanTypeTest,
    ::testing::ValuesIn(MaximumNumberOfWordsYouCanTypeSolution().getStrategyNames()));

}  // namespace leetcode::problem_1935
