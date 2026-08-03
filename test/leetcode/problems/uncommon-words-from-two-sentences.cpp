#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/uncommon-words-from-two-sentences.h"

namespace leetcode {
namespace problem_884 {

class UncommonWordsFromTwoSentencesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  UncommonWordsFromTwoSentencesSolution solution_;
};

TEST_P(UncommonWordsFromTwoSentencesTest, Example1) {
  std::vector<std::string> expected = {"sour", "sweet"};
  auto actual = solution_.uncommonFromSentences("this apple is sweet",
                                                "this apple is sour");
  std::sort(actual.begin(), actual.end());
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, actual);
}

TEST_P(UncommonWordsFromTwoSentencesTest, Example2) {
  std::vector<std::string> expected = {"banana"};
  auto actual =
      solution_.uncommonFromSentences("apple apple", "banana");
  std::sort(actual.begin(), actual.end());
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, actual);
}

TEST_P(UncommonWordsFromTwoSentencesTest, SelfAuthoredAllWordsSame) {
  auto actual = solution_.uncommonFromSentences("a a", "a a");
  EXPECT_TRUE(actual.empty());
}

TEST_P(UncommonWordsFromTwoSentencesTest, SelfAuthoredSingleWordEach) {
  std::vector<std::string> expected = {"x", "y"};
  auto actual = solution_.uncommonFromSentences("x", "y");
  std::sort(actual.begin(), actual.end());
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(
    UncommonWordsFromTwoSentencesTestSuite,
    UncommonWordsFromTwoSentencesTest,
    ::testing::ValuesIn(UncommonWordsFromTwoSentencesSolution().getStrategyNames()));

}  // namespace problem_884
}  // namespace leetcode
