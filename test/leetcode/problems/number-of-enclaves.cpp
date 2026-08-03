#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/number-of-enclaves.h"

using namespace leetcode::problem_1020;

class NumberOfEnclavesTest : public ::testing::TestWithParam<std::string> {
 protected:
  NumberOfEnclavesSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(NumberOfEnclavesTest, Example1) {
  std::vector<std::vector<int>> grid = {
      {0, 0, 0, 0},
      {1, 0, 1, 0},
      {0, 1, 1, 0},
      {0, 0, 0, 0}};
  EXPECT_EQ(solution.numEnclaves(grid), 3);
}

TEST_P(NumberOfEnclavesTest, Example2) {
  std::vector<std::vector<int>> grid = {
      {0, 1, 1, 0},
      {0, 0, 1, 0},
      {0, 0, 1, 0},
      {0, 0, 0, 0}};
  EXPECT_EQ(solution.numEnclaves(grid), 0);
}

TEST_P(NumberOfEnclavesTest, SelfAuthoredSingleCellLand) {
  std::vector<std::vector<int>> grid = {{1}};
  EXPECT_EQ(solution.numEnclaves(grid), 0);
}

TEST_P(NumberOfEnclavesTest, SelfAuthoredSingleCellSea) {
  std::vector<std::vector<int>> grid = {{0}};
  EXPECT_EQ(solution.numEnclaves(grid), 0);
}

TEST_P(NumberOfEnclavesTest, SelfAuthoredAllEnclosed) {
  std::vector<std::vector<int>> grid = {
      {0, 0, 0, 0},
      {0, 1, 1, 0},
      {0, 1, 1, 0},
      {0, 0, 0, 0}};
  EXPECT_EQ(solution.numEnclaves(grid), 4);
}

TEST_P(NumberOfEnclavesTest, SelfAuthoredNoEnclavesAllBoundary) {
  std::vector<std::vector<int>> grid = {
      {1, 1, 1},
      {1, 0, 1},
      {1, 1, 1}};
  EXPECT_EQ(solution.numEnclaves(grid), 0);
}

INSTANTIATE_TEST_SUITE_P(Strategies,
                         NumberOfEnclavesTest,
                         ::testing::ValuesIn(
                             NumberOfEnclavesSolution().getStrategyNames()));
