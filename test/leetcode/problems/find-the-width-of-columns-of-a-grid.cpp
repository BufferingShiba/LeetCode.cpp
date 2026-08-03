#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-width-of-columns-of-a-grid.h"

namespace leetcode {
namespace problem_2639 {

class FindTheWidthOfColumnsOfAGridTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheWidthOfColumnsOfAGridSolution solution;
};

TEST_P(FindTheWidthOfColumnsOfAGridTest, Example1) {
  std::vector<std::vector<int>> grid = {{1}, {22}, {333}};
  EXPECT_EQ(std::vector<int>({3}), solution.findColumnWidth(grid));
}

TEST_P(FindTheWidthOfColumnsOfAGridTest, Example2) {
  std::vector<std::vector<int>> grid = {{-15, 1, 3}, {15, 7, 12}, {5, 6, -2}};
  EXPECT_EQ(std::vector<int>({3, 1, 2}), solution.findColumnWidth(grid));
}

TEST_P(FindTheWidthOfColumnsOfAGridTest, SelfAuthoredSingleCell) {
  std::vector<std::vector<int>> grid = {{0}};
  EXPECT_EQ(std::vector<int>({1}), solution.findColumnWidth(grid));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheWidthOfColumnsOfAGridTestSuite, FindTheWidthOfColumnsOfAGridTest,
    ::testing::ValuesIn(FindTheWidthOfColumnsOfAGridSolution().getStrategyNames()));

}  // namespace problem_2639
}  // namespace leetcode
