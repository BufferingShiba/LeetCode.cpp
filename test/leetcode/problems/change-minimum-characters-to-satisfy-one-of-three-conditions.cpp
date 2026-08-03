#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

#include "leetcode/problems/change-minimum-characters-to-satisfy-one-of-three-conditions.h"

namespace leetcode {
namespace problem_1737 {

class ChangeMinimumCharactersToSatisfyOneOfThreeConditionsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ChangeMinimumCharactersToSatisfyOneOfThreeConditionsSolution solution_;
};

TEST_P(ChangeMinimumCharactersToSatisfyOneOfThreeConditionsTest, Example1) {
  EXPECT_EQ(solution_.minCharacters("aba", "caa"), 2);
}

TEST_P(ChangeMinimumCharactersToSatisfyOneOfThreeConditionsTest, Example2) {
  EXPECT_EQ(solution_.minCharacters("dabadd", "cda"), 3);
}

TEST_P(ChangeMinimumCharactersToSatisfyOneOfThreeConditionsTest, SelfAuthoredAlreadySatisfied) {
  EXPECT_EQ(solution_.minCharacters("abc", "def"), 0);
}

TEST_P(ChangeMinimumCharactersToSatisfyOneOfThreeConditionsTest, SelfAuthoredSingleCharEach) {
  EXPECT_EQ(solution_.minCharacters("a", "a"), 0);
}

TEST_P(ChangeMinimumCharactersToSatisfyOneOfThreeConditionsTest, SelfAuthoredAllSameLetters) {
  EXPECT_EQ(solution_.minCharacters("aaa", "aaa"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    ChangeMinimumCharactersToSatisfyOneOfThreeConditionsTestSuite,
    ChangeMinimumCharactersToSatisfyOneOfThreeConditionsTest,
    ::testing::ValuesIn(
        ChangeMinimumCharactersToSatisfyOneOfThreeConditionsSolution()
            .getStrategyNames()));

}  // namespace problem_1737
}  // namespace leetcode
