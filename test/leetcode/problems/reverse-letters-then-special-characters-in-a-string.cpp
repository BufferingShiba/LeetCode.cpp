#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/reverse-letters-then-special-characters-in-a-string.h"

namespace leetcode {
namespace problem_3823 {

class ReverseLettersThenSpecialCharactersInAStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ReverseLettersThenSpecialCharactersInAStringSolution solution;
};

TEST_P(ReverseLettersThenSpecialCharactersInAStringTest, Example1) {
  EXPECT_EQ("(fad@cb#e)", solution.reverseByType(")ebc#da@f("));
}

TEST_P(ReverseLettersThenSpecialCharactersInAStringTest, Example2) {
  EXPECT_EQ("z", solution.reverseByType("z"));
}

TEST_P(ReverseLettersThenSpecialCharactersInAStringTest, Example3) {
  EXPECT_EQ(")(*&^%$#@!", solution.reverseByType("!@#$%^&*()"));
}

TEST_P(ReverseLettersThenSpecialCharactersInAStringTest, SelfAuthoredMixedBoundary) {
  // Single letter and single special character.
  EXPECT_EQ("a!", solution.reverseByType("a!"));
  EXPECT_EQ("!a", solution.reverseByType("!a"));
}

TEST_P(ReverseLettersThenSpecialCharactersInAStringTest, SelfAuthoredAllLetters) {
  EXPECT_EQ("cba", solution.reverseByType("abc"));
}

INSTANTIATE_TEST_SUITE_P(
    ReverseLettersThenSpecialCharactersInAStringTestSuite,
    ReverseLettersThenSpecialCharactersInAStringTest,
    ::testing::ValuesIn(
        ReverseLettersThenSpecialCharactersInAStringSolution()
            .getStrategyNames()));

}  // namespace problem_3823
}  // namespace leetcode
