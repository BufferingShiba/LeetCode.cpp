#include <string>

#include "leetcode/problems/minimum-cuts-to-divide-a-circle.h"
#include <gtest/gtest.h>

namespace leetcode::problem_2481 {
namespace {

class MinimumCutsToDivideACircleTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumCutsToDivideACircleSolution solution_;
};

TEST_P(MinimumCutsToDivideACircleTest, Example1) {
  EXPECT_EQ(solution_.numberOfCuts(4), 2);
}

TEST_P(MinimumCutsToDivideACircleTest, Example2) {
  EXPECT_EQ(solution_.numberOfCuts(3), 3);
}

TEST_P(MinimumCutsToDivideACircleTest, SelfAuthoredSingleSlice) {
  EXPECT_EQ(solution_.numberOfCuts(1), 0);
}

TEST_P(MinimumCutsToDivideACircleTest, SelfAuthoredEvenNumber) {
  EXPECT_EQ(solution_.numberOfCuts(6), 3);
}

TEST_P(MinimumCutsToDivideACircleTest, SelfAuthoredOddNumber) {
  EXPECT_EQ(solution_.numberOfCuts(7), 7);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCutsToDivideACircleTestSuite, MinimumCutsToDivideACircleTest,
    ::testing::ValuesIn(MinimumCutsToDivideACircleSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_2481
