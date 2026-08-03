#include "leetcode/problems/clumsy-factorial.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1006 {

class ClumsyFactorialTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ClumsyFactorialSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 4
// Output: 7
TEST_P(ClumsyFactorialTest, OfficialExample1) {
  int n = 4;
  EXPECT_EQ(7, solution.clumsy(n));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 10
// Output: 12
TEST_P(ClumsyFactorialTest, OfficialExample2) {
  int n = 10;
  EXPECT_EQ(12, solution.clumsy(n));
}

TEST_P(ClumsyFactorialTest, SmallAndNegativeBlockCases) {
  EXPECT_EQ(1, solution.clumsy(1));
  EXPECT_EQ(6, solution.clumsy(7));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, ClumsyFactorialTest,
    ::testing::ValuesIn(ClumsyFactorialSolution().getStrategyNames()));

}  // namespace problem_1006
}  // namespace leetcode
