#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-difference.h"

namespace leetcode {
namespace problem_389 {

class FindTheDifferenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheDifferenceSolution solution;
};

TEST_P(FindTheDifferenceTest, Example1) {
  EXPECT_EQ('e', solution.findTheDifference("abcd", "abcde"));
}

TEST_P(FindTheDifferenceTest, Example2) {
  EXPECT_EQ('y', solution.findTheDifference("", "y"));
}

TEST_P(FindTheDifferenceTest, SameLetters) {
  EXPECT_EQ('b', solution.findTheDifference("aa", "aab"));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheDifferenceTestSuite, FindTheDifferenceTest,
    ::testing::ValuesIn(FindTheDifferenceSolution().getStrategyNames()));

}  // namespace problem_389
}  // namespace leetcode
