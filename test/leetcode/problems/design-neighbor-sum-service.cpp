#include <gtest/gtest.h>

#include "leetcode/problems/design-neighbor-sum-service.h"

using namespace leetcode::problem_3242;

class DesignNeighborSumServiceTest : public ::testing::TestWithParam<int> {};

TEST_P(DesignNeighborSumServiceTest, Example1) {
  std::vector<std::vector<int>> grid = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
  NeighborSum ns(grid);
  EXPECT_EQ(ns.adjacentSum(1), 6);
  EXPECT_EQ(ns.adjacentSum(4), 16);
  EXPECT_EQ(ns.diagonalSum(4), 16);
  EXPECT_EQ(ns.diagonalSum(8), 4);
}

TEST_P(DesignNeighborSumServiceTest, Example2) {
  std::vector<std::vector<int>> grid = {
      {1, 2, 0, 3},
      {4, 7, 15, 6},
      {8, 9, 10, 11},
      {12, 13, 14, 5}};
  NeighborSum ns(grid);
  EXPECT_EQ(ns.adjacentSum(15), 23);
  EXPECT_EQ(ns.diagonalSum(9), 45);
}

INSTANTIATE_TEST_SUITE_P(DesignNeighborSumServiceTests,
                         DesignNeighborSumServiceTest,
                         ::testing::Values(0));
