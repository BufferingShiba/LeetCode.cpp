#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/extra-characters-in-a-string.h"

namespace leetcode {
namespace problem_2707 {
namespace {

using ParamType = std::string;

class ExtraCharactersInAStringTest : public testing::TestWithParam<ParamType> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ExtraCharactersInAStringSolution solution;
};

TEST_P(ExtraCharactersInAStringTest, Example1) {
  std::string s = "leetscode";
  std::vector<std::string> dictionary = {"leet", "code", "leetcode"};
  EXPECT_EQ(solution.minExtraChar(s, dictionary), 1);
}

TEST_P(ExtraCharactersInAStringTest, Example2) {
  std::string s = "sayhelloworld";
  std::vector<std::string> dictionary = {"hello", "world"};
  EXPECT_EQ(solution.minExtraChar(s, dictionary), 3);
}

TEST_P(ExtraCharactersInAStringTest, SelfAuthoredAllMatched) {
  std::string s = "abc";
  std::vector<std::string> dictionary = {"a", "b", "c", "ab", "bc", "abc"};
  EXPECT_EQ(solution.minExtraChar(s, dictionary), 0);
}

TEST_P(ExtraCharactersInAStringTest, SelfAuthoredNoMatch) {
  std::string s = "xyz";
  std::vector<std::string> dictionary = {"a", "b"};
  EXPECT_EQ(solution.minExtraChar(s, dictionary), 3);
}

TEST_P(ExtraCharactersInAStringTest, SelfAuthoredSingleChar) {
  std::string s = "a";
  std::vector<std::string> dictionary = {"a"};
  EXPECT_EQ(solution.minExtraChar(s, dictionary), 0);
}

TEST_P(ExtraCharactersInAStringTest, SelfAuthoredSingleCharNotInDict) {
  std::string s = "a";
  std::vector<std::string> dictionary = {"b"};
  EXPECT_EQ(solution.minExtraChar(s, dictionary), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ExtraCharactersInAStringTest,
    testing::ValuesIn(ExtraCharactersInAStringSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2707
}  // namespace leetcode
