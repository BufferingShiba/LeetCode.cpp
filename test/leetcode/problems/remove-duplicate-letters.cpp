#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/remove-duplicate-letters.h"

namespace leetcode::problem_316 {

class RemoveDuplicateLettersTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  RemoveDuplicateLettersSolution solution;
};

TEST_P(RemoveDuplicateLettersTest, Example1) {
  EXPECT_EQ(solution.removeDuplicateLetters("bcabc"), "abc");
}

TEST_P(RemoveDuplicateLettersTest, Example2) {
  EXPECT_EQ(solution.removeDuplicateLetters("cbacdcbc"), "acdb");
}

TEST_P(RemoveDuplicateLettersTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution.removeDuplicateLetters("a"), "a");
}

TEST_P(RemoveDuplicateLettersTest, SelfAuthoredAllSame) {
  EXPECT_EQ(solution.removeDuplicateLetters("aaaa"), "a");
}

TEST_P(RemoveDuplicateLettersTest, SelfAuthoredAlreadySorted) {
  EXPECT_EQ(solution.removeDuplicateLetters("abc"), "abc");
}

TEST_P(RemoveDuplicateLettersTest, SelfAuthoredReversed) {
  EXPECT_EQ(solution.removeDuplicateLetters("cba"), "cba");
}

TEST_P(RemoveDuplicateLettersTest, SelfAuthoredEdgeWithDuplicates) {
  EXPECT_EQ(solution.removeDuplicateLetters("abacb"), "abc");
}

INSTANTIATE_TEST_SUITE_P(RemoveDuplicateLetters,
                         RemoveDuplicateLettersTest,
                         testing::ValuesIn(RemoveDuplicateLettersSolution().getStrategyNames()));

}  // namespace leetcode::problem_316
