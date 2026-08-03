#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-prefixes-of-a-given-string.h"

namespace leetcode {
namespace problem_2255 {
namespace {

class CountPrefixesOfAGivenStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountPrefixesOfAGivenString solution;
};

TEST_P(CountPrefixesOfAGivenStringTest, Example1) {
  std::vector<std::string> words = {"a", "b", "c", "ab", "bc", "abc"};
  std::string s = "abc";
  EXPECT_EQ(3, solution.countPrefixes(words, s));
}

TEST_P(CountPrefixesOfAGivenStringTest, Example2) {
  std::vector<std::string> words = {"a", "a"};
  std::string s = "aa";
  EXPECT_EQ(2, solution.countPrefixes(words, s));
}

TEST_P(CountPrefixesOfAGivenStringTest, SelfAuthored_NoneMatch) {
  std::vector<std::string> words = {"abc", "abcd"};
  std::string s = "ab";
  EXPECT_EQ(0, solution.countPrefixes(words, s));
}

TEST_P(CountPrefixesOfAGivenStringTest, SelfAuthored_WordLongerThanS) {
  std::vector<std::string> words = {"hello", "he"};
  std::string s = "hell";
  EXPECT_EQ(1, solution.countPrefixes(words, s));
}

INSTANTIATE_TEST_SUITE_P(
    CountPrefixesOfAGivenStringTestCases, CountPrefixesOfAGivenStringTest,
    ::testing::ValuesIn(CountPrefixesOfAGivenString().getStrategyNames()));

}  // namespace
}  // namespace problem_2255
}  // namespace leetcode
