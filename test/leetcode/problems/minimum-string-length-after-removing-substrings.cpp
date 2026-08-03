#include "leetcode/problems/minimum-string-length-after-removing-substrings.h"

#include <gtest/gtest.h>

namespace leetcode::problem_2696 {

class MinimumStringLengthAfterRemovingSubstringsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumStringLengthAfterRemovingSubstringsSolution solution_;
};

TEST_P(MinimumStringLengthAfterRemovingSubstringsTest, Example1) {
  EXPECT_EQ(solution_.minLength("ABFCACDB"), 2);
}

TEST_P(MinimumStringLengthAfterRemovingSubstringsTest, Example2) {
  EXPECT_EQ(solution_.minLength("ACBBD"), 5);
}

TEST_P(MinimumStringLengthAfterRemovingSubstringsTest, SingleChar) {
  EXPECT_EQ(solution_.minLength("A"), 1);
}

TEST_P(MinimumStringLengthAfterRemovingSubstringsTest, CascadingRemoval) {
  EXPECT_EQ(solution_.minLength("ABCD"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumStringLengthAfterRemovingSubstringsTestCases,
    MinimumStringLengthAfterRemovingSubstringsTest,
    ::testing::ValuesIn(
        MinimumStringLengthAfterRemovingSubstringsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2696
