#include "leetcode/problems/traffic-signal-color.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3894 {
namespace {

class TrafficSignalColorTest : public ::testing::TestWithParam<std::string> {
protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  TrafficSignalColorSolution solution;
};

TEST_P(TrafficSignalColorTest, Example1) {
  EXPECT_EQ(solution.trafficSignal(60), "Red");
}

TEST_P(TrafficSignalColorTest, Example2) {
  EXPECT_EQ(solution.trafficSignal(5), "Invalid");
}

TEST_P(TrafficSignalColorTest, SelfAuthoredBoundaryZero) {
  EXPECT_EQ(solution.trafficSignal(0), "Green");
}

TEST_P(TrafficSignalColorTest, SelfAuthoredBoundaryOrange) {
  EXPECT_EQ(solution.trafficSignal(30), "Orange");
}

TEST_P(TrafficSignalColorTest, SelfAuthoredInvalidLarge) {
  EXPECT_EQ(solution.trafficSignal(1000), "Invalid");
}

INSTANTIATE_TEST_SUITE_P(
    TrafficSignalColorStrategies, TrafficSignalColorTest,
    ::testing::ValuesIn(TrafficSignalColorSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3894
}  // namespace leetcode
