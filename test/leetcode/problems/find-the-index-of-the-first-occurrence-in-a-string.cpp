#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-index-of-the-first-occurrence-in-a-string.h"

namespace leetcode {
namespace problem_28 {
namespace {

class FindTheIndexOfTheFirstOccurrenceInAStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheIndexOfTheFirstOccurrenceInAStringSolution solution;
};

TEST_P(FindTheIndexOfTheFirstOccurrenceInAStringTest, Example1) {
  EXPECT_EQ(solution.strStr("sadbutsad", "sad"), 0);
}

TEST_P(FindTheIndexOfTheFirstOccurrenceInAStringTest, Example2) {
  EXPECT_EQ(solution.strStr("leetcode", "leeto"), -1);
}

TEST_P(FindTheIndexOfTheFirstOccurrenceInAStringTest, SelfAuthoredNeedleAtEnd) {
  EXPECT_EQ(solution.strStr("hello", "ll"), 2);
}

TEST_P(FindTheIndexOfTheFirstOccurrenceInAStringTest, SelfAuthoredEmptyNeedle) {
  EXPECT_EQ(solution.strStr("abc", ""), 0);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheIndexOfTheFirstOccurrenceInAStringTestSuite,
    FindTheIndexOfTheFirstOccurrenceInAStringTest,
    ::testing::ValuesIn(
        FindTheIndexOfTheFirstOccurrenceInAStringSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace problem_28
}  // namespace leetcode
