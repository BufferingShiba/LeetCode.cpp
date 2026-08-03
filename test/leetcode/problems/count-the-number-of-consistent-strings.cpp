#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/count-the-number-of-consistent-strings.h"

namespace leetcode::problem_1684 {

class CountTheNumberOfConsistentStringsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountTheNumberOfConsistentStringsSolution solution;
};

TEST_P(CountTheNumberOfConsistentStringsTest, Example1) {
  std::string allowed = "ab";
  std::vector<std::string> words = {"ad", "bd", "aaab", "baa", "badab"};
  EXPECT_EQ(2, solution.countConsistentStrings(allowed, words));
}

TEST_P(CountTheNumberOfConsistentStringsTest, Example2) {
  std::string allowed = "abc";
  std::vector<std::string> words = {"a", "b", "c", "ab", "ac", "bc", "abc"};
  EXPECT_EQ(7, solution.countConsistentStrings(allowed, words));
}

TEST_P(CountTheNumberOfConsistentStringsTest, Example3) {
  std::string allowed = "cad";
  std::vector<std::string> words = {"cc", "acd", "b", "ba", "bac", "bad", "ac", "d"};
  EXPECT_EQ(4, solution.countConsistentStrings(allowed, words));
}

TEST_P(CountTheNumberOfConsistentStringsTest, SelfAuthoredSingleWordConsistent) {
  std::string allowed = "a";
  std::vector<std::string> words = {"a", "b", "aa", "ab"};
  EXPECT_EQ(2, solution.countConsistentStrings(allowed, words));
}

INSTANTIATE_TEST_SUITE_P(
    CountTheNumberOfConsistentStringsTest, CountTheNumberOfConsistentStringsTest,
    ::testing::ValuesIn(CountTheNumberOfConsistentStringsSolution().getStrategyNames()));

}  // namespace leetcode::problem_1684
