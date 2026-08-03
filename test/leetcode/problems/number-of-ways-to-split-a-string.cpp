#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-ways-to-split-a-string.h"

namespace leetcode {
namespace problem_1573 {
namespace {

class NumberOfWaysToSplitAStringTest : public ::testing::TestWithParam<std::string> {
 protected:
  NumberOfWaysToSplitAStringSolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(NumberOfWaysToSplitAStringTest, Example1) {
  EXPECT_EQ(solution.numWays("10101"), 4);
}

TEST_P(NumberOfWaysToSplitAStringTest, Example2) {
  EXPECT_EQ(solution.numWays("1001"), 0);
}

TEST_P(NumberOfWaysToSplitAStringTest, Example3) {
  EXPECT_EQ(solution.numWays("0000"), 3);
}

TEST_P(NumberOfWaysToSplitAStringTest, SelfAuthoredAllZeroLong) {
  // n=5, C(4,2)=6
  EXPECT_EQ(solution.numWays("00000"), 6);
}

TEST_P(NumberOfWaysToSplitAStringTest, SelfAuthoredSingleOneEach) {
  // "10101" covered; try "111": each part exactly one 1, only one split.
  EXPECT_EQ(solution.numWays("111"), 1);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfWaysToSplitAStringTestCases,
    NumberOfWaysToSplitAStringTest,
    ::testing::ValuesIn(NumberOfWaysToSplitAStringSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1573
}  // namespace leetcode
