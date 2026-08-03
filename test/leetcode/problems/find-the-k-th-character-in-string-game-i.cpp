#include <gtest/gtest.h>

#include "leetcode/problems/find-the-k-th-character-in-string-game-i.h"
#include <string>

namespace leetcode::problem_3304 {
namespace {

class FindTheKThCharacterInStringGameITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheKThCharacterInStringGameISolution solution;
};

TEST_P(FindTheKThCharacterInStringGameITest, Example1) {
  EXPECT_EQ('b', solution.kthCharacter(5));
}

TEST_P(FindTheKThCharacterInStringGameITest, Example2) {
  EXPECT_EQ('c', solution.kthCharacter(10));
}

TEST_P(FindTheKThCharacterInStringGameITest, SelfAuthoredEdgeCaseK1) {
  EXPECT_EQ('a', solution.kthCharacter(1));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheKThCharacterInStringGameITestSuite,
    FindTheKThCharacterInStringGameITest,
    ::testing::ValuesIn(FindTheKThCharacterInStringGameISolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_3304
