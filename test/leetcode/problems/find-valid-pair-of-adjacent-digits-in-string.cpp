#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-valid-pair-of-adjacent-digits-in-string.h"

namespace leetcode::problem_3438 {

class FindValidPairOfAdjacentDigitsInStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  FindValidPairOfAdjacentDigitsInStringSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(FindValidPairOfAdjacentDigitsInStringTest, Example1) {
  EXPECT_EQ(solution.findValidPair("2523533"), "23");
}

TEST_P(FindValidPairOfAdjacentDigitsInStringTest, Example2) {
  EXPECT_EQ(solution.findValidPair("221"), "21");
}

TEST_P(FindValidPairOfAdjacentDigitsInStringTest, Example3) {
  EXPECT_EQ(solution.findValidPair("22"), "");
}

TEST_P(FindValidPairOfAdjacentDigitsInStringTest, SelfAuthoredNoValidPair) {
  EXPECT_EQ(solution.findValidPair("11"), "");
}

TEST_P(FindValidPairOfAdjacentDigitsInStringTest, SelfAuthoredEarlyValidPair) {
  // '2' appears 2, '1' appears 1 -> "21" is the first valid adjacent pair.
  EXPECT_EQ(solution.findValidPair("2123"), "21");
}

INSTANTIATE_TEST_SUITE_P(
    FindValidPairOfAdjacentDigitsInStringTestSuite,
    FindValidPairOfAdjacentDigitsInStringTest,
    ::testing::ValuesIn(
        FindValidPairOfAdjacentDigitsInStringSolution().getStrategyNames()));

}  // namespace leetcode::problem_3438
