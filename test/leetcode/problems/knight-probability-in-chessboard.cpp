#include "leetcode/problems/knight-probability-in-chessboard.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_688 {

class KnightProbabilityInChessboardTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  KnightProbabilityInChessboardSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 3, k = 2, row = 0, column = 0
// Output: 0.06250
TEST_P(KnightProbabilityInChessboardTest, OfficialExample1) {
  double result = solution.knightProbability(3, 2, 0, 0);
  EXPECT_NEAR(0.0625, result, 1e-5);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 1, k = 0, row = 0, column = 0
// Output: 1.00000
TEST_P(KnightProbabilityInChessboardTest, OfficialExample2) {
  double result = solution.knightProbability(1, 0, 0, 0);
  EXPECT_NEAR(1.0, result, 1e-5);
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, KnightProbabilityInChessboardTest,
    ::testing::ValuesIn(KnightProbabilityInChessboardSolution().getStrategyNames()));

}  // namespace problem_688
}  // namespace leetcode
