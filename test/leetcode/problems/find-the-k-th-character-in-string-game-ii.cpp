#include "leetcode/problems/find-the-k-th-character-in-string-game-ii.h"

#include <gtest/gtest.h>

using leetcode::problem_3307::FindTheKThCharacterInStringGameIiSolution;

class FindTheKThCharacterInStringGameIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheKThCharacterInStringGameIiSolution solution;
};

TEST_P(FindTheKThCharacterInStringGameIiTest, Example1) {
  long long k = 5;
  std::vector<int> operations = {0, 0, 0};
  EXPECT_EQ(solution.kthCharacter(k, operations), 'a');
}

TEST_P(FindTheKThCharacterInStringGameIiTest, Example2) {
  long long k = 10;
  std::vector<int> operations = {0, 1, 0, 1};
  EXPECT_EQ(solution.kthCharacter(k, operations), 'b');
}

TEST_P(FindTheKThCharacterInStringGameIiTest, SelfAuthoredSingleOp0) {
  long long k = 2;
  std::vector<int> operations = {0};
  EXPECT_EQ(solution.kthCharacter(k, operations), 'a');
}

TEST_P(FindTheKThCharacterInStringGameIiTest, SelfAuthoredSingleOp1) {
  long long k = 2;
  std::vector<int> operations = {1};
  EXPECT_EQ(solution.kthCharacter(k, operations), 'b');
}

TEST_P(FindTheKThCharacterInStringGameIiTest, SelfAuthoredFirstCharAlwaysA) {
  long long k = 1;
  std::vector<int> operations = {1, 1, 1, 1, 1};
  EXPECT_EQ(solution.kthCharacter(k, operations), 'a');
}

INSTANTIATE_TEST_SUITE_P(
    FindTheKThCharacterInStringGameIiTestCases,
    FindTheKThCharacterInStringGameIiTest,
    ::testing::ValuesIn(FindTheKThCharacterInStringGameIiSolution().getStrategyNames()));
