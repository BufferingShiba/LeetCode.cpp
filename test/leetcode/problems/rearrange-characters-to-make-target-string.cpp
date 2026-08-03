#include "leetcode/problems/rearrange-characters-to-make-target-string.h"

#include <gtest/gtest.h>

#include <string>

namespace leetcode {
namespace problem_2287 {

class RearrangeCharactersToMakeTargetStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  RearrangeCharactersToMakeTargetStringSolution solution_;
};

TEST_P(RearrangeCharactersToMakeTargetStringTest, Example1) {
  EXPECT_EQ(solution_.rearrangeCharacters("ilovecodingonleetcode", "code"), 2);
}

TEST_P(RearrangeCharactersToMakeTargetStringTest, Example2) {
  EXPECT_EQ(solution_.rearrangeCharacters("abcba", "abc"), 1);
}

TEST_P(RearrangeCharactersToMakeTargetStringTest, Example3) {
  EXPECT_EQ(solution_.rearrangeCharacters("abbaccaddaeea", "aaaaa"), 1);
}

TEST_P(RearrangeCharactersToMakeTargetStringTest, SelfAuthoredInsufficientChar) {
  EXPECT_EQ(solution_.rearrangeCharacters("ab", "abc"), 0);
}

TEST_P(RearrangeCharactersToMakeTargetStringTest, SelfAuthoredSingleCharMultipleCopies) {
  EXPECT_EQ(solution_.rearrangeCharacters("aaaa", "a"), 4);
}

INSTANTIATE_TEST_SUITE_P(
    RearrangeCharactersToMakeTargetStringTestSuite,
    RearrangeCharactersToMakeTargetStringTest,
    ::testing::ValuesIn(
        RearrangeCharactersToMakeTargetStringSolution().getStrategyNames()));

}  // namespace problem_2287
}  // namespace leetcode
