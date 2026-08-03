#include "leetcode/problems/split-with-minimum-sum.h"

#include <gtest/gtest.h>
#include <string>

namespace leetcode {
namespace problem_2578 {
namespace {

const std::string kTag = "greedy_sort";

}  // namespace

class SplitWithMinimumSumTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SplitWithMinimumSumSolution solution_;
};

TEST_P(SplitWithMinimumSumTest, Example1) {
  EXPECT_EQ(solution_.splitNum(4325), 59);
}

TEST_P(SplitWithMinimumSumTest, Example2) {
  EXPECT_EQ(solution_.splitNum(687), 75);
}

TEST_P(SplitWithMinimumSumTest, SelfAuthoredEdgeCase) {
  EXPECT_EQ(solution_.splitNum(10), 0 + 1);
}

INSTANTIATE_TEST_SUITE_P(
    SplitWithMinimumSumParameterized, SplitWithMinimumSumTest,
    ::testing::ValuesIn(SplitWithMinimumSumSolution().getStrategyNames()));

}  // namespace problem_2578
}  // namespace leetcode
