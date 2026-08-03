#include <gtest/gtest.h>

#include "leetcode/problems/airplane-seat-assignment-probability.h"

namespace leetcode {
namespace problem_1227 {

class AirplaneSeatAssignmentProbabilityTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  AirplaneSeatAssignmentProbabilitySolution solution;
};

TEST_P(AirplaneSeatAssignmentProbabilityTest, Example1) {
  EXPECT_DOUBLE_EQ(1.0, solution.nthPersonGetsNthSeat(1));
}

TEST_P(AirplaneSeatAssignmentProbabilityTest, Example2) {
  EXPECT_DOUBLE_EQ(0.5, solution.nthPersonGetsNthSeat(2));
}

TEST_P(AirplaneSeatAssignmentProbabilityTest, SelfAuthoredLargeN) {
  // 经典结论：n >= 2 时概率恒为 1/2。
  EXPECT_DOUBLE_EQ(0.5, solution.nthPersonGetsNthSeat(100000));
}

TEST_P(AirplaneSeatAssignmentProbabilityTest, SelfAuthoredSmallN) {
  EXPECT_DOUBLE_EQ(0.5, solution.nthPersonGetsNthSeat(3));
  EXPECT_DOUBLE_EQ(0.5, solution.nthPersonGetsNthSeat(10));
}

INSTANTIATE_TEST_SUITE_P(
    AirplaneSeatAssignmentProbabilityTestSuite,
    AirplaneSeatAssignmentProbabilityTest,
    ::testing::ValuesIn(
        AirplaneSeatAssignmentProbabilitySolution().getStrategyNames()));

}  // namespace problem_1227
}  // namespace leetcode
