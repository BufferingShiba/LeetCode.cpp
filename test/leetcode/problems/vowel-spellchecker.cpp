#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/vowel-spellchecker.h"

namespace leetcode::problem_966 {

class VowelSpellcheckerTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  VowelSpellcheckerSolution solution;
};

TEST_P(VowelSpellcheckerTest, Example1) {
  std::vector<std::string> wordlist = {"KiTe", "kite", "hare", "Hare"};
  std::vector<std::string> queries = {"kite", "Kite", "KiTe", "Hare",
                                      "HARE", "Hear", "hear", "keti",
                                      "keet", "keto"};
  std::vector<std::string> expected = {"kite", "KiTe", "KiTe", "Hare",
                                       "hare", "", "", "KiTe", "", "KiTe"};
  EXPECT_EQ(solution.spellchecker(wordlist, queries), expected);
}

TEST_P(VowelSpellcheckerTest, Example2) {
  std::vector<std::string> wordlist = {"yellow"};
  std::vector<std::string> queries = {"YellOw"};
  std::vector<std::string> expected = {"yellow"};
  EXPECT_EQ(solution.spellchecker(wordlist, queries), expected);
}

TEST_P(VowelSpellcheckerTest, SelfAuthoredVowelOnlyMatch) {
  std::vector<std::string> wordlist = {"YellOw"};
  std::vector<std::string> queries = {"yollow"};
  std::vector<std::string> expected = {"YellOw"};
  EXPECT_EQ(solution.spellchecker(wordlist, queries), expected);
}

TEST_P(VowelSpellcheckerTest, SelfAuthoredNoMatch) {
  std::vector<std::string> wordlist = {"YellOw"};
  std::vector<std::string> queries = {"yeellow", "yllw"};
  std::vector<std::string> expected = {"", ""};
  EXPECT_EQ(solution.spellchecker(wordlist, queries), expected);
}

TEST_P(VowelSpellcheckerTest, SelfAuthoredPrecedenceExactFirst) {
  std::vector<std::string> wordlist = {"KiTe", "kite"};
  std::vector<std::string> queries = {"kite"};
  std::vector<std::string> expected = {"kite"};
  EXPECT_EQ(solution.spellchecker(wordlist, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    VowelSpellcheckerTestSuite, VowelSpellcheckerTest,
    ::testing::ValuesIn(VowelSpellcheckerSolution().getStrategyNames()));

}  // namespace leetcode::problem_966
