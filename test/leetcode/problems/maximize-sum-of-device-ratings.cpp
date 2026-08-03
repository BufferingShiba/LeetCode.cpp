#include <gtest/gtest.h>

#include "leetcode/problems/maximize-sum-of-device-ratings.h"

using namespace leetcode::problem_3961;

class MaximizeSumOfDeviceRatingsTest
    : public testing::TestWithParam<std::string> {
 protected:
  MaximizeSumOfDeviceRatingsSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MaximizeSumOfDeviceRatingsTest, Example1) {
  std::vector<std::vector<int>> units = {{1, 3}, {2, 2}};
  EXPECT_EQ(solution.maxRatings(units), 4);
}

TEST_P(MaximizeSumOfDeviceRatingsTest, Example2) {
  std::vector<std::vector<int>> units = {{1, 2, 3}, {4, 5, 6}};
  EXPECT_EQ(solution.maxRatings(units), 6);
}

TEST_P(MaximizeSumOfDeviceRatingsTest, Example3) {
  std::vector<std::vector<int>> units = {{5, 5, 5}, {1, 1, 1}};
  EXPECT_EQ(solution.maxRatings(units), 6);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MaximizeSumOfDeviceRatingsTest,
    testing::ValuesIn(
        MaximizeSumOfDeviceRatingsSolution().getStrategyNames()));
