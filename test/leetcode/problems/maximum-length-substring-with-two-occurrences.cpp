#include <gtest/gtest.h>
#include <string>

#include "leetcode/problems/maximum-length-substring-with-two-occurrences.h"

namespace leetcode {
namespace problem_3090 {
namespace {

class MaximumLengthSubstringWithTwoOccurrencesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumLengthSubstringWithTwoOccurrencesSolution solution_;
};

TEST_P(MaximumLengthSubstringWithTwoOccurrencesTest, Example1) {
  EXPECT_EQ(solution_.maximumLengthSubstring("bcbbbcba"), 4);
}

TEST_P(MaximumLengthSubstringWithTwoOccurrencesTest, Example2) {
  EXPECT_EQ(solution_.maximumLengthSubstring("aaaa"), 2);
}

TEST_P(MaximumLengthSubstringWithTwoOccurrencesTest, SelfAuthored1) {
  // "abc" - every char appears once, full length allowed.
  EXPECT_EQ(solution_.maximumLengthSubstring("abc"), 3);
}

TEST_P(MaximumLengthSubstringWithTwoOccurrencesTest, SelfAuthored2) {
  // "abccba" - each char appears twice, full length allowed.
  EXPECT_EQ(solution_.maximumLengthSubstring("abccba"), 6);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumLengthSubstringWithTwoOccurrencesTests,
    MaximumLengthSubstringWithTwoOccurrencesTest,
    ::testing::ValuesIn(
        MaximumLengthSubstringWithTwoOccurrencesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3090
}  // namespace leetcode
