#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/two-furthest-houses-with-different-colors.h"

namespace leetcode::problem_2078 {

class TwoFurthestHousesWithDifferentColorsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  TwoFurthestHousesWithDifferentColorsSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(TwoFurthestHousesWithDifferentColorsTest, Example1) {
  std::vector<int> colors = {1, 1, 1, 6, 1, 1, 1};
  EXPECT_EQ(3, solution.maxDistance(colors));
}

TEST_P(TwoFurthestHousesWithDifferentColorsTest, Example2) {
  std::vector<int> colors = {1, 8, 3, 8, 3};
  EXPECT_EQ(4, solution.maxDistance(colors));
}

TEST_P(TwoFurthestHousesWithDifferentColorsTest, Example3) {
  std::vector<int> colors = {0, 1};
  EXPECT_EQ(1, solution.maxDistance(colors));
}

INSTANTIATE_TEST_SUITE_P(
    TwoFurthestHousesWithDifferentColorsTestCases,
    TwoFurthestHousesWithDifferentColorsTest,
    ::testing::ValuesIn(TwoFurthestHousesWithDifferentColorsSolution()
                            .getStrategyNames()));

}  // namespace leetcode::problem_2078
