#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-units-on-a-truck.h"

namespace leetcode::problem_1710 {

class MaximumUnitsOnATruckTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumUnitsOnATruck solution;
};

TEST_P(MaximumUnitsOnATruckTest, Example1) {
  std::vector<std::vector<int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
  EXPECT_EQ(8, solution.maximumUnits(boxTypes, 4));
}

TEST_P(MaximumUnitsOnATruckTest, Example2) {
  std::vector<std::vector<int>> boxTypes = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
  EXPECT_EQ(91, solution.maximumUnits(boxTypes, 10));
}

TEST_P(MaximumUnitsOnATruckTest, SelfAuthoredExactFit) {
  std::vector<std::vector<int>> boxTypes = {{2, 5}, {3, 2}};
  EXPECT_EQ(10, solution.maximumUnits(boxTypes, 2));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumUnitsOnATruckTestSuite, MaximumUnitsOnATruckTest,
    ::testing::ValuesIn(MaximumUnitsOnATruck().getStrategyNames()));

}  // namespace leetcode::problem_1710
