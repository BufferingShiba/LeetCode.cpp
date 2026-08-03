#include "leetcode/problems/remove-adjacent-almost-equal-characters.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

using leetcode::problem_2957::RemoveAdjacentAlmostEqualCharactersSolution;

class RemoveAdjacentAlmostEqualCharactersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RemoveAdjacentAlmostEqualCharactersSolution solution;
};

TEST_P(RemoveAdjacentAlmostEqualCharactersTest, Example1) {
  EXPECT_EQ(solution.removeAlmostEqualCharacters("aaaaa"), 2);
}

TEST_P(RemoveAdjacentAlmostEqualCharactersTest, Example2) {
  EXPECT_EQ(solution.removeAlmostEqualCharacters("abddez"), 2);
}

TEST_P(RemoveAdjacentAlmostEqualCharactersTest, Example3) {
  EXPECT_EQ(solution.removeAlmostEqualCharacters("zyxyxyz"), 3);
}

TEST_P(RemoveAdjacentAlmostEqualCharactersTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution.removeAlmostEqualCharacters("a"), 0);
}

TEST_P(RemoveAdjacentAlmostEqualCharactersTest, SelfAuthoredNoConflict) {
  EXPECT_EQ(solution.removeAlmostEqualCharacters("ac"), 0);
}

TEST_P(RemoveAdjacentAlmostEqualCharactersTest, SelfAuthoredAdjacentConflict) {
  EXPECT_EQ(solution.removeAlmostEqualCharacters("ab"), 1);
}

INSTANTIATE_TEST_SUITE_P(
    RemoveAdjacentAlmostEqualCharactersTestSuite,
    RemoveAdjacentAlmostEqualCharactersTest,
    ::testing::ValuesIn(RemoveAdjacentAlmostEqualCharactersSolution().getStrategyNames()));
