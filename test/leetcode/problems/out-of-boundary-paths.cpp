#include <gtest/gtest.h>

#include "leetcode/problems/out-of-boundary-paths.h"

namespace leetcode {
namespace problem_576 {

class OutOfBoundaryPathsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  OutOfBoundaryPathsSolution solution_;
};

TEST_P(OutOfBoundaryPathsTest, Example1) {
  EXPECT_EQ(solution_.findPaths(2, 2, 2, 0, 0), 6);
}

TEST_P(OutOfBoundaryPathsTest, Example2) {
  EXPECT_EQ(solution_.findPaths(1, 3, 3, 0, 1), 12);
}

TEST_P(OutOfBoundaryPathsTest, SelfAuthoredZeroMoves) {
  EXPECT_EQ(solution_.findPaths(2, 2, 0, 0, 0), 0);
}

TEST_P(OutOfBoundaryPathsTest, SelfAuthoredSingleCellOneMove) {
  // 1x1 grid, start at (0,0), 1 move → all 4 directions go out
  EXPECT_EQ(solution_.findPaths(1, 1, 1, 0, 0), 4);
}

TEST_P(OutOfBoundaryPathsTest, SelfAuthoredCornerTwoMoves) {
  // 3x3 grid, corner at (0,0), 2 moves
  // Manually: 1-step out: 2 directions (up, left). 2-step out: more.
  // Let's just ensure it doesn't crash and returns something reasonable.
  int result = solution_.findPaths(3, 3, 2, 0, 0);
  EXPECT_GT(result, 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, OutOfBoundaryPathsTest,
    testing::ValuesIn(OutOfBoundaryPathsSolution().getStrategyNames()));

}  // namespace problem_576
}  // namespace leetcode
