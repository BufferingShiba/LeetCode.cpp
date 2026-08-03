#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/replace-all-digits-with-characters.h"

namespace leetcode {
namespace problem_1844 {
namespace {

class ReplaceAllDigitsWithCharactersTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ReplaceAllDigitsWithCharactersSolution solution_;
};

TEST_P(ReplaceAllDigitsWithCharactersTest, Example1) {
  EXPECT_EQ("abcdef", solution_.replaceDigits("a1c1e1"));
}

TEST_P(ReplaceAllDigitsWithCharactersTest, Example2) {
  EXPECT_EQ("abbdcfdhe", solution_.replaceDigits("a1b2c3d4e"));
}

TEST_P(ReplaceAllDigitsWithCharactersTest, SingleLetter) {
  EXPECT_EQ("a", solution_.replaceDigits("a"));
}

TEST_P(ReplaceAllDigitsWithCharactersTest, ZeroShift) {
  EXPECT_EQ("aa", solution_.replaceDigits("a0"));
}

INSTANTIATE_TEST_SUITE_P(
    ReplaceAllDigitsWithCharactersTestSuite,
    ReplaceAllDigitsWithCharactersTest,
    ::testing::ValuesIn(ReplaceAllDigitsWithCharactersSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1844
}  // namespace leetcode
