#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/as-far-from-land-as-possible.h"

namespace leetcode::problem_1162 {

class AsFarFromLandAsPossibleTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  AsFarFromLandAsPossibleSolution solution;
};

TEST_P(AsFarFromLandAsPossibleTest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  EXPECT_EQ(2, solution.maxDistance(grid));
}

TEST_P(AsFarFromLandAsPossibleTest, Example2) {
  std::vector<std::vector<int>> grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  EXPECT_EQ(4, solution.maxDistance(grid));
}

TEST_P(AsFarFromLandAsPossibleTest, SelfAuthoredNoLand) {
  std::vector<std::vector<int>> grid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  EXPECT_EQ(-1, solution.maxDistance(grid));
}

TEST_P(AsFarFromLandAsPossibleTest, SelfAuthoredNoWater) {
  std::vector<std::vector<int>> grid = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
  EXPECT_EQ(-1, solution.maxDistance(grid));
}

TEST_P(AsFarFromLandAsPossibleTest, SelfAuthoredSingleCellLand) {
  std::vector<std::vector<int>> grid = {{1}};
  EXPECT_EQ(-1, solution.maxDistance(grid));
}

TEST_P(AsFarFromLandAsPossibleTest, SelfAuthoredSingleCellWater) {
  std::vector<std::vector<int>> grid = {{0}};
  EXPECT_EQ(-1, solution.maxDistance(grid));
}

INSTANTIATE_TEST_SUITE_P(
    AsFarFromLandAsPossibleTestSuite, AsFarFromLandAsPossibleTest,
    ::testing::ValuesIn(AsFarFromLandAsPossibleSolution().getStrategyNames()));

}  // namespace leetcode::problem_1162
