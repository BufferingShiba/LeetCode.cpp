#include "leetcode/problems/count-substrings-that-differ-by-one-character.h"

#include <gtest/gtest.h>

#include <string>

namespace leetcode {
namespace problem_1638 {
namespace {

using CountSubstringsThatDifferByOneCharacterTest =
    ::testing::TestWithParam<std::string>;

class CountSubstringsTestFixture
    : public CountSubstringsThatDifferByOneCharacterTest {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountSubstringsThatDifferByOneCharacterSolution solution;
};

TEST_P(CountSubstringsTestFixture, Example1) {
  EXPECT_EQ(solution.countSubstrings("aba", "baba"), 6);
}

TEST_P(CountSubstringsTestFixture, Example2) {
  EXPECT_EQ(solution.countSubstrings("ab", "bb"), 3);
}

TEST_P(CountSubstringsTestFixture, SingleCharacter) {
  EXPECT_EQ(solution.countSubstrings("a", "a"), 0);
}

TEST_P(CountSubstringsTestFixture, SingleDifferentCharacter) {
  EXPECT_EQ(solution.countSubstrings("a", "b"), 1);
}

TEST_P(CountSubstringsTestFixture, AllSameLongStrings) {
  EXPECT_EQ(solution.countSubstrings("aa", "aa"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    CountSubstringsStrategies, CountSubstringsTestFixture,
    ::testing::ValuesIn(
        CountSubstringsThatDifferByOneCharacterSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1638
}  // namespace leetcode
