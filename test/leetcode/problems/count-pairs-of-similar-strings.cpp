#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-pairs-of-similar-strings.h"

namespace leetcode {
namespace problem_2506 {

class CountPairsOfSimilarStringsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountPairsOfSimilarStringsSolution solution_;
};

TEST_P(CountPairsOfSimilarStringsTest, Example1) {
  std::vector<std::string> words = {"aba", "aabb", "abcd", "bac", "aabc"};
  EXPECT_EQ(solution_.similarPairs(words), 2);
}

TEST_P(CountPairsOfSimilarStringsTest, Example2) {
  std::vector<std::string> words = {"aabb", "ab", "ba"};
  EXPECT_EQ(solution_.similarPairs(words), 3);
}

TEST_P(CountPairsOfSimilarStringsTest, Example3) {
  std::vector<std::string> words = {"nba", "cba", "dba"};
  EXPECT_EQ(solution_.similarPairs(words), 0);
}

TEST_P(CountPairsOfSimilarStringsTest, SelfAuthoredSingleWord) {
  std::vector<std::string> words = {"abc"};
  EXPECT_EQ(solution_.similarPairs(words), 0);
}

TEST_P(CountPairsOfSimilarStringsTest, SelfAuthoredAllSameCharacters) {
  std::vector<std::string> words = {"a", "aa", "aaa"};
  EXPECT_EQ(solution_.similarPairs(words), 3);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, CountPairsOfSimilarStringsTest,
    ::testing::ValuesIn(
        CountPairsOfSimilarStringsSolution().getStrategyNames()));

}  // namespace problem_2506
}  // namespace leetcode
