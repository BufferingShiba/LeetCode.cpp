#include <gtest/gtest.h>

#include "leetcode/problems/number-of-valid-words-in-a-sentence.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2047 {

class NumberOfValidWordsInASentenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfValidWordsInASentenceSolution solution_;
};

TEST_P(NumberOfValidWordsInASentenceTest, Example1) {
  EXPECT_EQ(3, solution_.countValidWords("cat and  dog"));
}

TEST_P(NumberOfValidWordsInASentenceTest, Example2) {
  EXPECT_EQ(0, solution_.countValidWords("!this  1-s b8d!"));
}

TEST_P(NumberOfValidWordsInASentenceTest, Example3) {
  EXPECT_EQ(5,
            solution_.countValidWords("alice and  bob are playing stone-game10"));
}

TEST_P(NumberOfValidWordsInASentenceTest, SinglePunctuation) {
  EXPECT_EQ(1, solution_.countValidWords("."));
}

TEST_P(NumberOfValidWordsInASentenceTest, HyphenRules) {
  EXPECT_EQ(1, solution_.countValidWords("a-b ab- -ab"));
}

TEST_P(NumberOfValidWordsInASentenceTest, PunctuationAtEndOnly) {
  EXPECT_EQ(2, solution_.countValidWords("a!b c., d! e."));
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfValidWordsInASentenceTestParameters, NumberOfValidWordsInASentenceTest,
    ::testing::ValuesIn(NumberOfValidWordsInASentenceSolution().getStrategyNames()));

}  // namespace problem_2047
}  // namespace leetcode
