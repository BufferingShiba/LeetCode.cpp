#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-height-by-stacking-cuboids.h"

namespace leetcode {
namespace problem_1691 {

class MaximumHeightByStackingCuboidsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumHeightByStackingCuboids solution_;
};

TEST_P(MaximumHeightByStackingCuboidsTest, Example1) {
  std::vector<std::vector<int>> cuboids = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
  EXPECT_EQ(190, solution_.maxHeight(cuboids));
}

TEST_P(MaximumHeightByStackingCuboidsTest, Example2) {
  std::vector<std::vector<int>> cuboids = {{38, 25, 45}, {76, 35, 3}};
  EXPECT_EQ(76, solution_.maxHeight(cuboids));
}

TEST_P(MaximumHeightByStackingCuboidsTest, Example3) {
  std::vector<std::vector<int>> cuboids = {
      {7, 11, 17}, {7, 17, 11}, {11, 7, 17},
      {11, 17, 7}, {17, 7, 11}, {17, 11, 7}};
  EXPECT_EQ(102, solution_.maxHeight(cuboids));
}

TEST_P(MaximumHeightByStackingCuboidsTest, SelfAuthoredSingleCuboid) {
  std::vector<std::vector<int>> cuboids = {{12, 7, 3}};
  EXPECT_EQ(12, solution_.maxHeight(cuboids));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumHeightByStackingCuboidsTestCases, MaximumHeightByStackingCuboidsTest,
    ::testing::ValuesIn(MaximumHeightByStackingCuboids().getStrategyNames()));

}  // namespace problem_1691
}  // namespace leetcode
