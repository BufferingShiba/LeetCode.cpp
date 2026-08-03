#include "leetcode/problems/longest-increasing-path-in-a-matrix.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_329 {
namespace {

class LongestIncreasingPathInAMatrixTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestIncreasingPathInAMatrixSolution solution;
};

TEST_P(LongestIncreasingPathInAMatrixTest, Example1) {
  std::vector<std::vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
  EXPECT_EQ(4, solution.longestIncreasingPath(matrix));
}

TEST_P(LongestIncreasingPathInAMatrixTest, Example2) {
  std::vector<std::vector<int>> matrix = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
  EXPECT_EQ(4, solution.longestIncreasingPath(matrix));
}

TEST_P(LongestIncreasingPathInAMatrixTest, Example3) {
  std::vector<std::vector<int>> matrix = {{1}};
  EXPECT_EQ(1, solution.longestIncreasingPath(matrix));
}

INSTANTIATE_TEST_SUITE_P(
    LongestIncreasingPathInAMatrixTestSuite,
    LongestIncreasingPathInAMatrixTest,
    ::testing::ValuesIn(LongestIncreasingPathInAMatrixSolution()
                            .getStrategyNames()));

}  // namespace
}  // namespace problem_329
}  // namespace leetcode
