#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/first-letter-to-appear-twice.h"

namespace leetcode {
namespace problem_2351 {
namespace {

class FirstLetterToAppearTwiceTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FirstLetterToAppearTwiceSolution solution_;
};

TEST_P(FirstLetterToAppearTwiceTest, Example1) {
  EXPECT_EQ('c', solution_.repeatedCharacter("abccbaacz"));
}

TEST_P(FirstLetterToAppearTwiceTest, Example2) {
  EXPECT_EQ('d', solution_.repeatedCharacter("abcdd"));
}

TEST_P(FirstLetterToAppearTwiceTest, SelfAuthoredAdjacentDuplicates) {
  EXPECT_EQ('z', solution_.repeatedCharacter("zz"));
}

TEST_P(FirstLetterToAppearTwiceTest, SelfAuthoredRepeatAtEarlyIndex) {
  EXPECT_EQ('a', solution_.repeatedCharacter("abcda"));
}

INSTANTIATE_TEST_SUITE_P(
    FirstLetterToAppearTwiceTestSuite, FirstLetterToAppearTwiceTest,
    ::testing::ValuesIn(FirstLetterToAppearTwiceSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2351
}  // namespace leetcode
