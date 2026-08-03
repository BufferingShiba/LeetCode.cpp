#include "leetcode/problems/minimum-cost-to-connect-two-groups-of-points.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1595 {

class MinimumCostToConnectTwoGroupsOfPointsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumCostToConnectTwoGroupsOfPointsSolution solution;
};

TEST_P(MinimumCostToConnectTwoGroupsOfPointsTest, Example1) {
  std::vector<std::vector<int>> cost = {{15, 96}, {36, 2}};
  EXPECT_EQ(17, solution.connectTwoGroups(cost));
}

TEST_P(MinimumCostToConnectTwoGroupsOfPointsTest, Example2) {
  std::vector<std::vector<int>> cost = {{1, 3, 5}, {4, 1, 1}, {1, 5, 3}};
  EXPECT_EQ(4, solution.connectTwoGroups(cost));
}

TEST_P(MinimumCostToConnectTwoGroupsOfPointsTest, Example3) {
  std::vector<std::vector<int>> cost = {
      {2, 5, 1}, {3, 4, 7}, {8, 1, 2}, {6, 2, 4}, {3, 8, 8}};
  EXPECT_EQ(10, solution.connectTwoGroups(cost));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCostToConnectTwoGroupsOfPointsTestSuite,
    MinimumCostToConnectTwoGroupsOfPointsTest,
    ::testing::ValuesIn(
        MinimumCostToConnectTwoGroupsOfPointsSolution().getStrategyNames()));

}  // namespace problem_1595
}  // namespace leetcode
