#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-words-that-can-be-formed-by-characters.h"

namespace leetcode::problem_1160 {

class FindWordsThatCanBeFormedByCharactersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  FindWordsThatCanBeFormedByCharactersSolution solution_;
};

TEST_P(FindWordsThatCanBeFormedByCharactersTest, Example1) {
  std::vector<std::string> words = {"cat", "bt", "hat", "tree"};
  std::string chars = "atach";
  EXPECT_EQ(6, solution_.countCharacters(words, chars));
}

TEST_P(FindWordsThatCanBeFormedByCharactersTest, Example2) {
  std::vector<std::string> words = {"hello", "world", "leetcode"};
  std::string chars = "welldonehoneyr";
  EXPECT_EQ(10, solution_.countCharacters(words, chars));
}

TEST_P(FindWordsThatCanBeFormedByCharactersTest, SingleWordExactMatch) {
  std::vector<std::string> words = {"a", "aa", "ab"};
  std::string chars = "aab";
  EXPECT_EQ(5, solution_.countCharacters(words, chars));
}

INSTANTIATE_TEST_SUITE_P(
    FindWordsThatCanBeFormedByCharactersTestSuite,
    FindWordsThatCanBeFormedByCharactersTest,
    ::testing::ValuesIn(
        FindWordsThatCanBeFormedByCharactersSolution().getStrategyNames()));

}  // namespace leetcode::problem_1160
