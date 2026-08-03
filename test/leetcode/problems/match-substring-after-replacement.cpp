#include <gtest/gtest.h>

#include "leetcode/problems/match-substring-after-replacement.h"

using namespace leetcode::problem_2301;

class MatchSubstringAfterReplacementTest : public testing::TestWithParam<std::string> {
 protected:
  MatchSubstringAfterReplacementSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MatchSubstringAfterReplacementTest, Example1) {
  std::string s = "fool3e7bar";
  std::string sub = "leet";
  std::vector<std::vector<char>> mappings = {{'e', '3'}, {'t', '7'}, {'t', '8'}};
  EXPECT_TRUE(solution.matchReplacement(s, sub, mappings));
}

TEST_P(MatchSubstringAfterReplacementTest, Example2) {
  std::string s = "fooleetbar";
  std::string sub = "f00l";
  std::vector<std::vector<char>> mappings = {{'o', '0'}};
  EXPECT_FALSE(solution.matchReplacement(s, sub, mappings));
}

TEST_P(MatchSubstringAfterReplacementTest, Example3) {
  std::string s = "Fool33tbaR";
  std::string sub = "leetd";
  std::vector<std::vector<char>> mappings = {
      {'e', '3'}, {'t', '7'}, {'t', '8'}, {'d', 'b'}, {'p', 'b'}};
  EXPECT_TRUE(solution.matchReplacement(s, sub, mappings));
}

TEST_P(MatchSubstringAfterReplacementTest, SelfAuthoredExactMatchNoMapping) {
  std::string s = "hello";
  std::string sub = "ell";
  std::vector<std::vector<char>> mappings = {};
  EXPECT_TRUE(solution.matchReplacement(s, sub, mappings));
}

TEST_P(MatchSubstringAfterReplacementTest, SelfAuthoredSingleCharWithMapping) {
  std::string s = "x";
  std::string sub = "a";
  std::vector<std::vector<char>> mappings = {{'a', 'x'}};
  EXPECT_TRUE(solution.matchReplacement(s, sub, mappings));
}

TEST_P(MatchSubstringAfterReplacementTest, SelfAuthoredSameLengthFullMatch) {
  std::string s = "ab";
  std::string sub = "ab";
  std::vector<std::vector<char>> mappings = {};
  EXPECT_TRUE(solution.matchReplacement(s, sub, mappings));
}

TEST_P(MatchSubstringAfterReplacementTest, SelfAuthoredCannotReverseMapping) {
  // mapping o->0 cannot be used to turn 0 into o
  std::string s = "fooleetbar";
  std::string sub = "f00l";
  std::vector<std::vector<char>> mappings = {{'o', '0'}};
  EXPECT_FALSE(solution.matchReplacement(s, sub, mappings));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MatchSubstringAfterReplacementTest,
    testing::ValuesIn(MatchSubstringAfterReplacementSolution().getStrategyNames()));
