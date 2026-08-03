#include <gtest/gtest.h>

#include "leetcode/problems/number-of-steps-to-reduce-a-number-to-zero.h"

namespace leetcode {
namespace problem_1342 {

class NumberOfStepsToReduceANumberToZeroTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfStepsToReduceANumberToZeroSolution solution_;
};

TEST_P(NumberOfStepsToReduceANumberToZeroTest, Example1) {
  EXPECT_EQ(solution_.numberOfSteps(14), 6);
}

TEST_P(NumberOfStepsToReduceANumberToZeroTest, Example2) {
  EXPECT_EQ(solution_.numberOfSteps(8), 4);
}

TEST_P(NumberOfStepsToReduceANumberToZeroTest, Example3) {
  EXPECT_EQ(solution_.numberOfSteps(123), 12);
}

TEST_P(NumberOfStepsToReduceANumberToZeroTest, SelfAuthoredEdgeCaseZero) {
  EXPECT_EQ(solution_.numberOfSteps(0), 0);
}

TEST_P(NumberOfStepsToReduceANumberToZeroTest, SelfAuthoredEdgeCaseOne) {
  EXPECT_EQ(solution_.numberOfSteps(1), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    NumberOfStepsToReduceANumberToZeroTest,
    ::testing::ValuesIn(
        NumberOfStepsToReduceANumberToZeroSolution().getStrategyNames()));

}  // namespace problem_1342
}  // namespace leetcode
