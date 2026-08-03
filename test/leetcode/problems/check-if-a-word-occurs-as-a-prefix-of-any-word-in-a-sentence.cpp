#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence.h"

namespace leetcode::problem_1455 {

class CheckIfAWordOccursAsAPrefixOfAnyWordInASentenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CheckIfAWordOccursAsAPrefixOfAnyWordInASentenceSolution solution_;
};

TEST_P(CheckIfAWordOccursAsAPrefixOfAnyWordInASentenceTest, Example1) {
  EXPECT_EQ(solution_.isPrefixOfWord("i love eating burger", "burg"), 4);
}

TEST_P(CheckIfAWordOccursAsAPrefixOfAnyWordInASentenceTest, Example2) {
  EXPECT_EQ(
      solution_.isPrefixOfWord("this problem is an easy problem", "pro"), 2);
}

TEST_P(CheckIfAWordOccursAsAPrefixOfAnyWordInASentenceTest, Example3) {
  EXPECT_EQ(solution_.isPrefixOfWord("i am tired", "you"), -1);
}

TEST_P(CheckIfAWordOccursAsAPrefixOfAnyWordInASentenceTest, SelfAuthoredSingleWordMatch) {
  EXPECT_EQ(solution_.isPrefixOfWord("hello", "he"), 1);
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfAWordOccursAsAPrefixOfAnyWordInASentenceTestSuite,
    CheckIfAWordOccursAsAPrefixOfAnyWordInASentenceTest,
    ::testing::ValuesIn(
        CheckIfAWordOccursAsAPrefixOfAnyWordInASentenceSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_1455
