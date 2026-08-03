#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/reverse-prefix-of-word.h"

namespace leetcode::problem_2000 {

class ReversePrefixOfWordTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ReversePrefixOfWordSolution solution_;
};

TEST_P(ReversePrefixOfWordTest, Example1) {
  EXPECT_EQ(solution_.reversePrefix("abcdefd", 'd'), "dcbaefd");
}

TEST_P(ReversePrefixOfWordTest, Example2) {
  EXPECT_EQ(solution_.reversePrefix("xyxzxe", 'z'), "zxyxxe");
}

TEST_P(ReversePrefixOfWordTest, Example3) {
  EXPECT_EQ(solution_.reversePrefix("abcd", 'z'), "abcd");
}

TEST_P(ReversePrefixOfWordTest, SelfAuthoredSingleCharTarget) {
  EXPECT_EQ(solution_.reversePrefix("a", 'a'), "a");
}

TEST_P(ReversePrefixOfWordTest, SelfAuthoredTargetAtEnd) {
  EXPECT_EQ(solution_.reversePrefix("abc", 'c'), "cba");
}

INSTANTIATE_TEST_SUITE_P(
    ReversePrefixOfWordTestSuite, ReversePrefixOfWordTest,
    ::testing::ValuesIn(ReversePrefixOfWordSolution().getStrategyNames()));

}  // namespace leetcode::problem_2000
