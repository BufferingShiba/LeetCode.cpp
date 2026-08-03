#include <gtest/gtest.h>

#include "leetcode/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii.h"

using namespace leetcode::problem_3306;

class CountOfSubstringsContainingEveryVowelAndKConsonantsIiTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  CountOfSubstringsContainingEveryVowelAndKConsonantsIiSolution solution_;
};

TEST_P(CountOfSubstringsContainingEveryVowelAndKConsonantsIiTest, Example1) {
  EXPECT_EQ(solution_.countOfSubstrings("aeioqq", 1), 0);
}

TEST_P(CountOfSubstringsContainingEveryVowelAndKConsonantsIiTest, Example2) {
  EXPECT_EQ(solution_.countOfSubstrings("aeiou", 0), 1);
}

TEST_P(CountOfSubstringsContainingEveryVowelAndKConsonantsIiTest, Example3) {
  EXPECT_EQ(solution_.countOfSubstrings("ieaouqqieaouqq", 1), 3);
}

TEST_P(CountOfSubstringsContainingEveryVowelAndKConsonantsIiTest, SelfAuthoredNoConsonantsK0) {
  EXPECT_EQ(solution_.countOfSubstrings("aeiou", 0), 1);
}

TEST_P(CountOfSubstringsContainingEveryVowelAndKConsonantsIiTest, SelfAuthoredNoConsonantsK1) {
  EXPECT_EQ(solution_.countOfSubstrings("aeiou", 1), 0);
}

TEST_P(CountOfSubstringsContainingEveryVowelAndKConsonantsIiTest,
       SelfAuthoredOnlyOneVowel) {
  EXPECT_EQ(solution_.countOfSubstrings("aaaaa", 0), 0);
}

TEST_P(CountOfSubstringsContainingEveryVowelAndKConsonantsIiTest,
       SelfAuthoredAllConsonantsBeforeVowels) {
  EXPECT_EQ(solution_.countOfSubstrings("abcdeiou", 3), 1);
}

TEST_P(CountOfSubstringsContainingEveryVowelAndKConsonantsIiTest, SelfAuthoredLargeK) {
  EXPECT_EQ(solution_.countOfSubstrings("aeioubc", 2), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, CountOfSubstringsContainingEveryVowelAndKConsonantsIiTest,
    testing::ValuesIn(CountOfSubstringsContainingEveryVowelAndKConsonantsIiSolution()
                          .getStrategyNames()));
