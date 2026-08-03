#include "leetcode/problems/count-paths-with-the-given-xor-value.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3393 {

class CountPathsWithTheGivenXorValueTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountPathsWithTheGivenXorValueSolution solution;
};

TEST_P(CountPathsWithTheGivenXorValueTest, Example1) {
  vector<vector<int>> grid = {{2, 1, 5}, {7, 10, 0}, {12, 6, 4}};
  int k = 11;
  EXPECT_EQ(solution.countPathsWithXorValue(grid, k), 3);
}

TEST_P(CountPathsWithTheGivenXorValueTest, Example2) {
  vector<vector<int>> grid = {{1, 3, 3, 3}, {0, 3, 3, 2}, {3, 0, 1, 1}};
  int k = 2;
  EXPECT_EQ(solution.countPathsWithXorValue(grid, k), 5);
}

TEST_P(CountPathsWithTheGivenXorValueTest, Example3) {
  vector<vector<int>> grid = {{1, 1, 1, 2}, {3, 0, 3, 2}, {3, 0, 2, 2}};
  int k = 10;
  EXPECT_EQ(solution.countPathsWithXorValue(grid, k), 0);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, CountPathsWithTheGivenXorValueTest,
    ::testing::ValuesIn(CountPathsWithTheGivenXorValueSolution().getStrategyNames()));

}  // namespace problem_3393
}  // namespace leetcode
