#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-minimum-area-to-cover-all-ones-ii.h"

namespace leetcode {
namespace problem_3197 {

class FindTheMinimumAreaToCoverAllOnesIiTest
    : public ::testing::TestWithParam<std::string> {
 public:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheMinimumAreaToCoverAllOnesIiSolution solution;
};

TEST_P(FindTheMinimumAreaToCoverAllOnesIiTest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 0, 1}, {1, 1, 1}};
  EXPECT_EQ(5, solution.minimumSum(grid));
}

TEST_P(FindTheMinimumAreaToCoverAllOnesIiTest, Example2) {
  std::vector<std::vector<int>> grid = {{1, 0, 1, 0}, {0, 1, 0, 1}};
  EXPECT_EQ(5, solution.minimumSum(grid));
}

TEST_P(FindTheMinimumAreaToCoverAllOnesIiTest, SelfAuthoredThreeOnesInLine) {
  // Ones at (0,0), (0,1), (0,2): best cover each one separately -> 3.
  std::vector<std::vector<int>> grid = {{1, 1, 1}};
  EXPECT_EQ(3, solution.minimumSum(grid));
}

TEST_P(FindTheMinimumAreaToCoverAllOnesIiTest, SelfAuthoredDiagonal) {
  // Ones at (0,0), (1,1), (2,2): each separate -> 3.
  std::vector<std::vector<int>> grid = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  EXPECT_EQ(3, solution.minimumSum(grid));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheMinimumAreaToCoverAllOnesIiTestParameters,
    FindTheMinimumAreaToCoverAllOnesIiTest,
    ::testing::ValuesIn(FindTheMinimumAreaToCoverAllOnesIiSolution()
                            .getStrategyNames()));

}  // namespace problem_3197
}  // namespace leetcode
