#include <gtest/gtest.h>
#include "leetcode/problems/calculate-delayed-arrival-time.h"
#include <string>
#include <vector>

namespace leetcode::problem_2651 {

class CalculateDelayedArrivalTimeTest
    : public ::testing::TestWithParam<std::string> {
protected:
    CalculateDelayedArrivalTimeSolution& solution =
        CalculateDelayedArrivalTimeSolution::shared();

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(CalculateDelayedArrivalTimeTest, Example1) {
    EXPECT_EQ(solution.findDelayedArrivalTime(15, 5), 20);
}

TEST_P(CalculateDelayedArrivalTimeTest, Example2) {
    EXPECT_EQ(solution.findDelayedArrivalTime(13, 11), 0);
}

TEST_P(CalculateDelayedArrivalTimeTest, WrapAroundToMidnight) {
    EXPECT_EQ(solution.findDelayedArrivalTime(1, 23), 0);
}

TEST_P(CalculateDelayedArrivalTimeTest, Exactly24HoursDelay) {
    EXPECT_EQ(solution.findDelayedArrivalTime(5, 24), 5);
}

TEST_P(CalculateDelayedArrivalTimeTest, NoWrapSmallDelay) {
    EXPECT_EQ(solution.findDelayedArrivalTime(8, 3), 11);
}

INSTANTIATE_TEST_SUITE_P(
    CalculateDelayedArrivalTimeTestSuite,
    CalculateDelayedArrivalTimeTest,
    ::testing::ValuesIn(
        CalculateDelayedArrivalTimeSolution::shared().getStrategyNames()));

}  // namespace leetcode::problem_2651
