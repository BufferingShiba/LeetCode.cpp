#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/goat-latin.h"

namespace leetcode::problem_824 {

class GoatLatinTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  GoatLatinSolution solution_;
};

TEST_P(GoatLatinTest, Example1) {
  EXPECT_EQ("Imaa peaksmaaa oatGmaaaa atinLmaaaaa",
            solution_.toGoatLatin("I speak Goat Latin"));
}

TEST_P(GoatLatinTest, Example2) {
  EXPECT_EQ("heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa "
            "overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa",
            solution_.toGoatLatin(
                "The quick brown fox jumped over the lazy dog"));
}

TEST_P(GoatLatinTest, SelfAuthoredSingleWordVowel) {
  EXPECT_EQ("applemaa", solution_.toGoatLatin("apple"));
}

TEST_P(GoatLatinTest, SelfAuthoredSingleWordConsonant) {
  EXPECT_EQ("oatgmaa", solution_.toGoatLatin("goat"));
}

INSTANTIATE_TEST_SUITE_P(GoatLatinTestCases, GoatLatinTest,
                         ::testing::ValuesIn(
                             GoatLatinSolution().getStrategyNames()));

}  // namespace leetcode::problem_824
