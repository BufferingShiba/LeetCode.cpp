#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-prefix-and-suffix-pairs-i.h"

namespace leetcode {
namespace problem_3042 {

class CountPrefixAndSuffixPairsITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountPrefixAndSuffixPairsISolution solution;
};

TEST_P(CountPrefixAndSuffixPairsITest, Example1) {
  std::vector<std::string> words = {"a", "aba", "ababa", "aa"};
  EXPECT_EQ(4, solution.countPrefixSuffixPairs(words));
}

TEST_P(CountPrefixAndSuffixPairsITest, Example2) {
  std::vector<std::string> words = {"pa", "papa", "ma", "mama"};
  EXPECT_EQ(2, solution.countPrefixSuffixPairs(words));
}

TEST_P(CountPrefixAndSuffixPairsITest, Example3) {
  std::vector<std::string> words = {"abab", "ab"};
  EXPECT_EQ(0, solution.countPrefixSuffixPairs(words));
}

TEST_P(CountPrefixAndSuffixPairsITest, SelfAuthoredSingleWord) {
  std::vector<std::string> words = {"abc"};
  EXPECT_EQ(0, solution.countPrefixSuffixPairs(words));
}

TEST_P(CountPrefixAndSuffixPairsITest, SelfAuthoredAllSame) {
  std::vector<std::string> words = {"a", "a", "a"};
  EXPECT_EQ(3, solution.countPrefixSuffixPairs(words));
}

INSTANTIATE_TEST_SUITE_P(
    CountPrefixAndSuffixPairsITests, CountPrefixAndSuffixPairsITest,
    ::testing::ValuesIn(CountPrefixAndSuffixPairsISolution().getStrategyNames()));

}  // namespace problem_3042
}  // namespace leetcode
