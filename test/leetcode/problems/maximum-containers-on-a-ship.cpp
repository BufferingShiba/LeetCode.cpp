#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-containers-on-a-ship.h"

namespace leetcode {
namespace problem_3492 {

using leetcode::problem_3492::MaximumContainersOnAShipSolution;

class MaximumContainersOnAShipTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumContainersOnAShipSolution solution;
};

TEST_P(MaximumContainersOnAShipTest, Example1) {
  EXPECT_EQ(solution.maxContainers(2, 3, 15), 4);
}

TEST_P(MaximumContainersOnAShipTest, Example2) {
  EXPECT_EQ(solution.maxContainers(3, 5, 20), 4);
}

TEST_P(MaximumContainersOnAShipTest, SelfAuthoredWeightLimitBinds) {
  EXPECT_EQ(solution.maxContainers(5, 3, 50), 16);
}

TEST_P(MaximumContainersOnAShipTest, SelfAuthoredCapacityBindsl) {
  EXPECT_EQ(solution.maxContainers(10, 1, 1000000000), 100);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumContainersOnAShipTestSuite, MaximumContainersOnAShipTest,
    ::testing::ValuesIn(MaximumContainersOnAShipSolution().getStrategyNames()));

}  // namespace problem_3492
}  // namespace leetcode
