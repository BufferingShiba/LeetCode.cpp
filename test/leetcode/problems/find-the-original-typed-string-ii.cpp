#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/find-the-original-typed-string-ii.h"

namespace leetcode {
namespace problem_3333 {
namespace {

class FindTheOriginalTypedStringIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindTheOriginalTypedStringIiSolution solution_;
};

TEST_P(FindTheOriginalTypedStringIiTest, Example1) {
  EXPECT_EQ(solution_.possibleStringCount("aabbccdd", 7), 5);
}

TEST_P(FindTheOriginalTypedStringIiTest, Example2) {
  EXPECT_EQ(solution_.possibleStringCount("aabbccdd", 8), 1);
}

TEST_P(FindTheOriginalTypedStringIiTest, Example3) {
  EXPECT_EQ(solution_.possibleStringCount("aaabbb", 3), 8);
}

TEST_P(FindTheOriginalTypedStringIiTest, SelfAuthoredSingleCharBlock) {
  // "abc", k=1: only original = "abc" (len 3 >= 1); also each char can repeat? No,
  // runs are length 1 so no repeats. Answer = 1.
  EXPECT_EQ(solution_.possibleStringCount("abc", 1), 1);
}

TEST_P(FindTheOriginalTypedStringIiTest, SelfAuthoredMinLengthIsK) {
  // "aa", k=2: runs len 2, m=1. total=2. min length=1<2. invalid: length<2 means chosen=1,
  // i.e. "a" -> 1 way. invalid=1. answer=2-1=1. Original must be "aa" (len 2).
  EXPECT_EQ(solution_.possibleStringCount("aa", 2), 1);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheOriginalTypedStringIiTestSuite, FindTheOriginalTypedStringIiTest,
    ::testing::ValuesIn(FindTheOriginalTypedStringIiSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3333
}  // namespace leetcode
