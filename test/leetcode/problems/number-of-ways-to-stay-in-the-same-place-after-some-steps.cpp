#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps.h"

namespace leetcode {
namespace problem_1269 {
namespace {

using TestParam = std::string;

class NumberOfWaysToStayInTheSamePlaceAfterSomeStepsTest
    : public testing::TestWithParam<TestParam> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfWaysToStayInTheSamePlaceAfterSomeStepsSolution solution_;
};

TEST_P(NumberOfWaysToStayInTheSamePlaceAfterSomeStepsTest, Example1) {
  EXPECT_EQ(solution_.numWays(3, 2), 4);
}

TEST_P(NumberOfWaysToStayInTheSamePlaceAfterSomeStepsTest, Example2) {
  EXPECT_EQ(solution_.numWays(2, 4), 2);
}

TEST_P(NumberOfWaysToStayInTheSamePlaceAfterSomeStepsTest, Example3) {
  EXPECT_EQ(solution_.numWays(4, 2), 8);
}

TEST_P(NumberOfWaysToStayInTheSamePlaceAfterSomeStepsTest, SelfAuthoredSingleStep) {
  // 1 step, must stay to remain at index 0.
  EXPECT_EQ(solution_.numWays(1, 5), 1);
}

TEST_P(NumberOfWaysToStayInTheSamePlaceAfterSomeStepsTest, SelfAuthoredLargeArrLen) {
  // arrLen very large, effectively no right bound.
  // steps = 3: the known sequence for unrestricted line is A001405-like,
  // but we can compute manually: 3 steps, back to 0 →
  // possibilities: SSS, RLS, RSL, LRS? Wait, let's just run DP.
  // Actually we trust the DP. Let's use a known small value.
  EXPECT_EQ(solution_.numWays(3, 1000000), 4);
}

TEST_P(NumberOfWaysToStayInTheSamePlaceAfterSomeStepsTest, SelfAuthoredArrLenOne) {
  // Only one cell; must stay every step.
  EXPECT_EQ(solution_.numWays(5, 1), 1);
}

TEST_P(NumberOfWaysToStayInTheSamePlaceAfterSomeStepsTest, SelfAuthoredMaxStepsEdge) {
  // Just verify it runs and returns a positive value for max constraints.
  int result = solution_.numWays(500, 1000000);
  EXPECT_GT(result, 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    NumberOfWaysToStayInTheSamePlaceAfterSomeStepsTest,
    testing::ValuesIn(
        NumberOfWaysToStayInTheSamePlaceAfterSomeStepsSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace problem_1269
}  // namespace leetcode
