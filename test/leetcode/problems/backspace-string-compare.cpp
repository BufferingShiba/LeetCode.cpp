#include <gtest/gtest.h>

#include "leetcode/problems/backspace-string-compare.h"

namespace leetcode::problem_844 {
namespace {

class BackspaceStringCompareTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  BackspaceStringCompareSolution solution_;
};

TEST_P(BackspaceStringCompareTest, Example1) {
  EXPECT_TRUE(solution_.backspaceCompare("ab#c", "ad#c"));
}

TEST_P(BackspaceStringCompareTest, Example2) {
  EXPECT_TRUE(solution_.backspaceCompare("ab##", "c#d#"));
}

TEST_P(BackspaceStringCompareTest, Example3) {
  EXPECT_FALSE(solution_.backspaceCompare("a#c", "b"));
}

TEST_P(BackspaceStringCompareTest, SelfAuthored) {
  // both become empty
  EXPECT_TRUE(solution_.backspaceCompare("#", "#"));
  // one backspace to empty, one non-empty
  EXPECT_FALSE(solution_.backspaceCompare("a#", "a"));
  // no backspaces, identical
  EXPECT_TRUE(solution_.backspaceCompare("abc", "abc"));
}

INSTANTIATE_TEST_SUITE_P(
    , BackspaceStringCompareTest,
    ::testing::ValuesIn(BackspaceStringCompareSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_844
