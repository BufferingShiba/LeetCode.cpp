#include <gtest/gtest.h>

#include "leetcode/problems/length-of-last-word.h"

namespace leetcode {
namespace problem_58 {

class LengthOfLastWordTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  LengthOfLastWordSolution solution;
};

TEST_P(LengthOfLastWordTest, Example1) {
  EXPECT_EQ(solution.lengthOfLastWord("Hello World"), 5);
}

TEST_P(LengthOfLastWordTest, Example2) {
  EXPECT_EQ(solution.lengthOfLastWord("   fly me   to   the moon  "), 4);
}

TEST_P(LengthOfLastWordTest, Example3) {
  EXPECT_EQ(solution.lengthOfLastWord("luffy is still joyboy"), 6);
}

TEST_P(LengthOfLastWordTest, SelfAuthoredSingleWord) {
  EXPECT_EQ(solution.lengthOfLastWord("abc"), 3);
}

TEST_P(LengthOfLastWordTest, SelfAuthoredTrailingSpaces) {
  EXPECT_EQ(solution.lengthOfLastWord("a "), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    LengthOfLastWordTest,
    ::testing::ValuesIn(LengthOfLastWordSolution().getStrategyNames()));

}  // namespace problem_58
}  // namespace leetcode
