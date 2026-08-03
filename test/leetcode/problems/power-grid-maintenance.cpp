#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/power-grid-maintenance.h"

namespace leetcode::problem_3607 {

class PowerGridMaintenanceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PowerGridMaintenanceSolution solution;
};

TEST_P(PowerGridMaintenanceTest, Example1) {
  int c = 5;
  std::vector<std::vector<int>> connections = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  std::vector<std::vector<int>> queries = {{1, 3}, {2, 1}, {1, 1}, {2, 2}, {1, 2}};
  std::vector<int> expected = {3, 2, 3};
  EXPECT_EQ(solution.processQueries(c, connections, queries), expected);
}

TEST_P(PowerGridMaintenanceTest, Example2) {
  int c = 3;
  std::vector<std::vector<int>> connections = {};
  std::vector<std::vector<int>> queries = {{1, 1}, {2, 1}, {1, 1}};
  std::vector<int> expected = {1, -1};
  EXPECT_EQ(solution.processQueries(c, connections, queries), expected);
}

TEST_P(PowerGridMaintenanceTest, SelfAuthoredOfflineOnlineCheckReturnsSelf) {
  int c = 2;
  std::vector<std::vector<int>> connections = {{1, 2}};
  std::vector<std::vector<int>> queries = {{1, 1}, {2, 1}, {1, 1}, {1, 2}};
  // [1,1]: online -> 1; [2,1]: offline; [1,1]: offline, min online in comp
  // {1,2} is 2; [1,2]: online -> 2.
  std::vector<int> expected = {1, 2, 2};
  EXPECT_EQ(solution.processQueries(c, connections, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    PowerGridMaintenanceTestSuite, PowerGridMaintenanceTest,
    ::testing::ValuesIn(PowerGridMaintenanceSolution().getStrategyNames()));

}  // namespace leetcode::problem_3607
