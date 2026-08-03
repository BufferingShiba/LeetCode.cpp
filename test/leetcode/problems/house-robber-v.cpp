#include <gtest/gtest.h>

#include "leetcode/problems/house-robber-v.h"

using namespace leetcode::problem_3840;

class HouseRobberVTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  HouseRobberVSolution solution;
};

TEST_P(HouseRobberVTest, Example1) {
  std::vector<int> nums = {1, 4, 3, 5};
  std::vector<int> colors = {1, 1, 2, 2};
  EXPECT_EQ(solution.rob(nums, colors), 9);
}

TEST_P(HouseRobberVTest, Example2) {
  std::vector<int> nums = {3, 1, 2, 4};
  std::vector<int> colors = {2, 3, 2, 2};
  EXPECT_EQ(solution.rob(nums, colors), 8);
}

TEST_P(HouseRobberVTest, Example3) {
  std::vector<int> nums = {10, 1, 3, 9};
  std::vector<int> colors = {1, 1, 1, 2};
  EXPECT_EQ(solution.rob(nums, colors), 22);
}

TEST_P(HouseRobberVTest, SelfAuthoredSingleHouse) {
  std::vector<int> nums = {5};
  std::vector<int> colors = {1};
  EXPECT_EQ(solution.rob(nums, colors), 5);
}

TEST_P(HouseRobberVTest, SelfAuthoredTwoHousesSameColor) {
  std::vector<int> nums = {3, 4};
  std::vector<int> colors = {1, 1};
  EXPECT_EQ(solution.rob(nums, colors), 4);
}

TEST_P(HouseRobberVTest, SelfAuthoredTwoHousesDifferentColor) {
  std::vector<int> nums = {3, 4};
  std::vector<int> colors = {1, 2};
  EXPECT_EQ(solution.rob(nums, colors), 7);
}

INSTANTIATE_TEST_SUITE_P(Strategies, HouseRobberVTest,
                         testing::ValuesIn(HouseRobberVSolution().getStrategyNames()));
