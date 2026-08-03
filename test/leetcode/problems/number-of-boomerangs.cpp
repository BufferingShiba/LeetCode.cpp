#include <gtest/gtest.h>

#include "leetcode/problems/number-of-boomerangs.h"

namespace leetcode::problem_447 {

class NumberOfBoomerangsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  NumberOfBoomerangsSolution solution;
};

TEST_P(NumberOfBoomerangsTest, Example1) {
  std::vector<std::vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};
  EXPECT_EQ(solution.numberOfBoomerangs(points), 2);
}

TEST_P(NumberOfBoomerangsTest, Example2) {
  std::vector<std::vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
  EXPECT_EQ(solution.numberOfBoomerangs(points), 2);
}

TEST_P(NumberOfBoomerangsTest, Example3) {
  std::vector<std::vector<int>> points = {{1, 1}};
  EXPECT_EQ(solution.numberOfBoomerangs(points), 0);
}

TEST_P(NumberOfBoomerangsTest, SelfAuthoredTwoPoints) {
  std::vector<std::vector<int>> points = {{0, 0}, {1, 1}};
  EXPECT_EQ(solution.numberOfBoomerangs(points), 0);
}

TEST_P(NumberOfBoomerangsTest, SelfAuthoredSquareCorners) {
  // 4 corners of a unit square: each point has 2 others at distance 1,
  // giving 2*1=2 boomerangs per center → total 8.
  std::vector<std::vector<int>> points = {
      {0, 0}, {0, 1}, {1, 0}, {1, 1}};
  EXPECT_EQ(solution.numberOfBoomerangs(points), 8);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, NumberOfBoomerangsTest,
    testing::ValuesIn(NumberOfBoomerangsSolution().getStrategyNames()));

}  // namespace leetcode::problem_447
