#include "leetcode/problems/maximum-score-after-splitting-a-string.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1422 {

class MaximumScoreAfterSplittingAStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  MaximumScoreAfterSplittingAStringSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }

  std::string GetInput() const { return ""; }
};

TEST_P(MaximumScoreAfterSplittingAStringTest, Example1) {
  EXPECT_EQ(solution.maxScore("011101"), 5);
}

TEST_P(MaximumScoreAfterSplittingAStringTest, Example2) {
  EXPECT_EQ(solution.maxScore("00111"), 5);
}

TEST_P(MaximumScoreAfterSplittingAStringTest, Example3) {
  EXPECT_EQ(solution.maxScore("1111"), 3);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumScoreAfterSplittingAStringTestSuite,
    MaximumScoreAfterSplittingAStringTest,
    ::testing::ValuesIn(
        MaximumScoreAfterSplittingAStringSolution().getStrategyNames()));

}  // namespace problem_1422
}  // namespace leetcode
