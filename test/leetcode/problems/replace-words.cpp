#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/replace-words.h"

namespace leetcode::problem_648 {
namespace {

class ReplaceWordsTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ReplaceWordsSolution solution_;
};

TEST_P(ReplaceWordsTest, Example1) {
  std::vector<std::string> dictionary = {"cat", "bat", "rat"};
  std::string sentence = "the cattle was rattled by the battery";
  EXPECT_EQ(solution_.replaceWords(dictionary, sentence),
            "the cat was rat by the bat");
}

TEST_P(ReplaceWordsTest, Example2) {
  std::vector<std::string> dictionary = {"a", "b", "c"};
  std::string sentence = "aadsfasf absbs bbab cadsfafs";
  EXPECT_EQ(solution_.replaceWords(dictionary, sentence), "a a b c");
}

TEST_P(ReplaceWordsTest, NoMatch) {
  std::vector<std::string> dictionary = {"xyz"};
  std::string sentence = "hello world";
  EXPECT_EQ(solution_.replaceWords(dictionary, sentence), "hello world");
}

TEST_P(ReplaceWordsTest, ShortestRootWins) {
  // "ca" is shorter than "cat"; both are prefixes of "cattle" and "cat",
  // so the shortest root "ca" wins for both words.
  std::vector<std::string> dictionary = {"cat", "ca", "bat"};
  std::string sentence = "cattle cat";
  EXPECT_EQ(solution_.replaceWords(dictionary, sentence), "ca ca");
}

TEST_P(ReplaceWordsTest, SingleWord) {
  std::vector<std::string> dictionary = {"pre"};
  std::string sentence = "prefix";
  EXPECT_EQ(solution_.replaceWords(dictionary, sentence), "pre");
}

INSTANTIATE_TEST_SUITE_P(Strategies, ReplaceWordsTest,
                         testing::ValuesIn(ReplaceWordsSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_648
