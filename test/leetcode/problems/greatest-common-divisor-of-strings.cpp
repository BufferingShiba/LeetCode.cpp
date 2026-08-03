#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/greatest-common-divisor-of-strings.h"

namespace leetcode {
namespace problem_1071 {

class GreatestCommonDivisorOfStringsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  GreatestCommonDivisorOfStringsSolution solution_;
};

TEST_P(GreatestCommonDivisorOfStringsTest, Example1) {
  EXPECT_EQ(solution_.gcdOfStrings("ABCABC", "ABC"), "ABC");
}

TEST_P(GreatestCommonDivisorOfStringsTest, Example2) {
  EXPECT_EQ(solution_.gcdOfStrings("ABABAB", "ABAB"), "AB");
}

TEST_P(GreatestCommonDivisorOfStringsTest, Example3) {
  EXPECT_EQ(solution_.gcdOfStrings("LEET", "CODE"), "");
}

TEST_P(GreatestCommonDivisorOfStringsTest, Example4) {
  EXPECT_EQ(solution_.gcdOfStrings("AAAAAB", "AAA"), "");
}

TEST_P(GreatestCommonDivisorOfStringsTest, SelfAuthored) {
  EXPECT_EQ(solution_.gcdOfStrings("A", "B"), "");
  EXPECT_EQ(solution_.gcdOfStrings("AAA", "AAAAA"), "A");
  EXPECT_EQ(solution_.gcdOfStrings("ABAB", "ABAB"), "ABAB");
}

INSTANTIATE_TEST_SUITE_P(, GreatestCommonDivisorOfStringsTest,
                         ::testing::ValuesIn(
                             GreatestCommonDivisorOfStringsSolution().getStrategyNames()));

}  // namespace problem_1071
}  // namespace leetcode
