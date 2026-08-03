#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-number-of-words-found-in-sentences.h"

namespace leetcode::problem_2114 {

using testing::TestWithParam;
using testing::ValuesIn;

class MaximumNumberOfWordsFoundInSentencesTest
    : public TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumNumberOfWordsFoundInSentencesSolution solution_;
};

TEST_P(MaximumNumberOfWordsFoundInSentencesTest, Example1) {
  std::vector<std::string> sentences = {"alice and bob love leetcode",
                                        "i think so too",
                                        "this is great thanks very much"};
  EXPECT_EQ(solution_.mostWordsFound(sentences), 6);
}

TEST_P(MaximumNumberOfWordsFoundInSentencesTest, Example2) {
  std::vector<std::string> sentences = {"please wait", "continue to fight",
                                        "continue to win"};
  EXPECT_EQ(solution_.mostWordsFound(sentences), 3);
}

TEST_P(MaximumNumberOfWordsFoundInSentencesTest, SelfAuthoredSingleWordOnly) {
  std::vector<std::string> sentences = {"hello", "world", "hi"};
  EXPECT_EQ(solution_.mostWordsFound(sentences), 1);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfWordsFoundInSentencesTestSuite,
    MaximumNumberOfWordsFoundInSentencesTest,
    ValuesIn(
        MaximumNumberOfWordsFoundInSentencesSolution().getStrategyNames()));

}  // namespace leetcode::problem_2114
