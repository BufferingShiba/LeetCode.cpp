#include <gtest/gtest.h>

#include "leetcode/problems/count-prefix-and-suffix-pairs-ii.h"

#include <string>
#include <vector>

namespace leetcode::problem_3045 {

class CountPrefixAndSuffixPairsIiTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountPrefixAndSuffixPairsIiSolution solution;
};

TEST_P(CountPrefixAndSuffixPairsIiTest, Example1) {
  std::vector<std::string> words = {"a", "aba", "ababa", "aa"};
  EXPECT_EQ(solution.countPrefixSuffixPairs(words), 4);
}

TEST_P(CountPrefixAndSuffixPairsIiTest, Example2) {
  std::vector<std::string> words = {"pa", "papa", "ma", "mama"};
  EXPECT_EQ(solution.countPrefixSuffixPairs(words), 2);
}

TEST_P(CountPrefixAndSuffixPairsIiTest, Example3) {
  std::vector<std::string> words = {"abab", "ab"};
  EXPECT_EQ(solution.countPrefixSuffixPairs(words), 0);
}

TEST_P(CountPrefixAndSuffixPairsIiTest, SelfAuthored_DuplicateWords) {
  std::vector<std::string> words = {"a", "a"};
  EXPECT_EQ(solution.countPrefixSuffixPairs(words), 1);
}

TEST_P(CountPrefixAndSuffixPairsIiTest, SelfAuthored_SingleWord) {
  std::vector<std::string> words = {"abc"};
  EXPECT_EQ(solution.countPrefixSuffixPairs(words), 0);
}

TEST_P(CountPrefixAndSuffixPairsIiTest, SelfAuthored_AllSameChar) {
  std::vector<std::string> words = {"a", "aa", "aaa"};
  // Pairs: (0,1) "a" prefix&suffix of "aa", (0,2) "a" of "aaa", (1,2) "aa" of "aaa"
  EXPECT_EQ(solution.countPrefixSuffixPairs(words), 3);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CountPrefixAndSuffixPairsIiTest,
    testing::ValuesIn(CountPrefixAndSuffixPairsIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_3045
