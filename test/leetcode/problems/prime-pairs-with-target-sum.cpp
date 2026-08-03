#include "leetcode/problems/prime-pairs-with-target-sum.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2761 {

class PrimePairsWithTargetSumTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PrimePairsWithTargetSumSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 10
// Output: [[3,7],[5,5]]
TEST_P(PrimePairsWithTargetSumTest, OfficialExample1) {
  std::vector<std::vector<int>> expected = {{3, 7}, {5, 5}};
  EXPECT_EQ(expected, solution.findPrimePairs(10));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 2
// Output: []
TEST_P(PrimePairsWithTargetSumTest, OfficialExample2) {
  std::vector<std::vector<int>> expected = {};
  EXPECT_EQ(expected, solution.findPrimePairs(2));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, PrimePairsWithTargetSumTest,
    ::testing::ValuesIn(PrimePairsWithTargetSumSolution().getStrategyNames()));

}  // namespace problem_2761
}  // namespace leetcode
