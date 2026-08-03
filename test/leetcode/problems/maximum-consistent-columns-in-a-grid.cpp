#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-consistent-columns-in-a-grid.h"

namespace leetcode {
namespace problem_3989 {
namespace {

using MaximumConsistentColumnsInAGridTest =
    ::testing::TestWithParam<std::string>;

class TestFixture : public MaximumConsistentColumnsInAGridTest {
 protected:
  MaximumConsistentColumnsInAGridSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(TestFixture, Example1) {
  std::vector<std::vector<int>> grid = {{-2, 0, 3}};
  int limit = 2;
  EXPECT_EQ(solution.maxConsistentColumns(grid, limit), 2);
}

TEST_P(TestFixture, Example2) {
  std::vector<std::vector<int>> grid = {{1, -1, 1}, {2, 2, 2}};
  int limit = 1;
  EXPECT_EQ(solution.maxConsistentColumns(grid, limit), 2);
}

TEST_P(TestFixture, Example3) {
  std::vector<std::vector<int>> grid = {{-5, 5}};
  int limit = 9;
  EXPECT_EQ(solution.maxConsistentColumns(grid, limit), 1);
}

TEST_P(TestFixture, SelfAuthoredSingleColumn) {
  std::vector<std::vector<int>> grid = {{7}, {3}, {9}};
  int limit = 0;
  EXPECT_EQ(solution.maxConsistentColumns(grid, limit), 1);
}

TEST_P(TestFixture, SelfAuthoredAllConsistentWithZeroLimit) {
  std::vector<std::vector<int>> grid = {{5, 5, 5, 5}, {5, 5, 5, 5}};
  int limit = 0;
  EXPECT_EQ(solution.maxConsistentColumns(grid, limit), 4);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumConsistentColumnsInAGridTestSuite, TestFixture,
    ::testing::ValuesIn(
        MaximumConsistentColumnsInAGridSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3989
}  // namespace leetcode
