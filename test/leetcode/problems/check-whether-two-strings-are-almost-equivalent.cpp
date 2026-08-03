#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-whether-two-strings-are-almost-equivalent.h"

namespace leetcode {
namespace problem_2068 {

class CheckWhetherTwoStringsAreAlmostEquivalentTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CheckWhetherTwoStringsAreAlmostEquivalentSolution solution_;
};

TEST_P(CheckWhetherTwoStringsAreAlmostEquivalentTest, Example1) {
  EXPECT_FALSE(solution_.checkAlmostEquivalent("aaaa", "bccb"));
}

TEST_P(CheckWhetherTwoStringsAreAlmostEquivalentTest, Example2) {
  EXPECT_TRUE(solution_.checkAlmostEquivalent("abcdeef", "abaaacc"));
}

TEST_P(CheckWhetherTwoStringsAreAlmostEquivalentTest, Example3) {
  EXPECT_TRUE(solution_.checkAlmostEquivalent("cccddabba", "babababab"));
}

TEST_P(CheckWhetherTwoStringsAreAlmostEquivalentTest, SelfAuthoredIdenticalStrings) {
  EXPECT_TRUE(solution_.checkAlmostEquivalent("hello", "eholl"));
}

TEST_P(CheckWhetherTwoStringsAreAlmostEquivalentTest, SelfAuthoredSingleCharDifference) {
  EXPECT_TRUE(solution_.checkAlmostEquivalent("aab", "abc"));
}

INSTANTIATE_TEST_SUITE_P(
    CheckWhetherTwoStringsAreAlmostEquivalentTestSuite,
    CheckWhetherTwoStringsAreAlmostEquivalentTest,
    ::testing::ValuesIn(
        CheckWhetherTwoStringsAreAlmostEquivalentSolution().getStrategyNames()));

}  // namespace problem_2068
}  // namespace leetcode
