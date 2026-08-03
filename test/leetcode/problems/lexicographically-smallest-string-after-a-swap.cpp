#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/lexicographically-smallest-string-after-a-swap.h"

namespace leetcode::problem_3216 {

class LexicographicallySmallestStringAfterASwapTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LexicographicallySmallestStringAfterASwapSolution solution;
};

TEST_P(LexicographicallySmallestStringAfterASwapTest, Example1) {
  EXPECT_EQ("43520", solution.getSmallestString("45320"));
}

TEST_P(LexicographicallySmallestStringAfterASwapTest, Example2) {
  EXPECT_EQ("001", solution.getSmallestString("001"));
}

TEST_P(LexicographicallySmallestStringAfterASwapTest, SelfAuthoredSwapAtFront) {
  EXPECT_EQ("132", solution.getSmallestString("312"));
}

TEST_P(LexicographicallySmallestStringAfterASwapTest, SelfAuthoredNoSwapAllDifferentParity) {
  EXPECT_EQ("4321", solution.getSmallestString("4321"));
}

TEST_P(LexicographicallySmallestStringAfterASwapTest, SelfAuthoredSwapEvenPair) {
  EXPECT_EQ("2244", solution.getSmallestString("2424"));
}

INSTANTIATE_TEST_SUITE_P(
    LexicographicallySmallestStringAfterASwapTestSuite,
    LexicographicallySmallestStringAfterASwapTest,
    ::testing::ValuesIn(
        LexicographicallySmallestStringAfterASwapSolution().getStrategyNames()));

}  // namespace leetcode::problem_3216
