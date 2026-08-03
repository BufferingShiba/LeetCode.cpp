#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/path-with-minimum-effort.h"

namespace leetcode {
namespace problem_1631 {

class PathWithMinimumEffortTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PathWithMinimumEffortSolution solution;
};

TEST_P(PathWithMinimumEffortTest, Example1) {
  std::vector<std::vector<int>> heights = {
      {1, 2, 2},
      {3, 8, 2},
      {5, 3, 5},
  };
  EXPECT_EQ(solution.minimumEffortPath(heights), 2);
}

TEST_P(PathWithMinimumEffortTest, Example2) {
  std::vector<std::vector<int>> heights = {
      {1, 2, 3},
      {3, 8, 4},
      {5, 3, 5},
  };
  EXPECT_EQ(solution.minimumEffortPath(heights), 1);
}

TEST_P(PathWithMinimumEffortTest, Example3) {
  std::vector<std::vector<int>> heights = {
      {1, 2, 1, 1, 1},
      {1, 2, 1, 2, 1},
      {1, 2, 1, 2, 1},
      {1, 2, 1, 2, 1},
      {1, 1, 1, 2, 1},
  };
  EXPECT_EQ(solution.minimumEffortPath(heights), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, PathWithMinimumEffortTest,
    testing::ValuesIn(
        PathWithMinimumEffortSolution().getStrategyNames()));

}  // namespace problem_1631
}  // namespace leetcode
