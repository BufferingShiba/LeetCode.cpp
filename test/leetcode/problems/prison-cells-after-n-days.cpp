#include "leetcode/problems/prison-cells-after-n-days.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_957 {

class PrisonCellsAfterNDaysTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PrisonCellsAfterNDaysSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  cells = [0,1,0,1,1,0,0,1], n = 7
// Output: [0,0,1,1,0,0,0,0]
TEST_P(PrisonCellsAfterNDaysTest, OfficialExample1) {
  vector<int> cells = {0, 1, 0, 1, 1, 0, 0, 1};
  int n = 7;
  vector<int> expected = {0, 0, 1, 1, 0, 0, 0, 0};
  EXPECT_EQ(expected, solution.prisonAfterNDays(cells, n));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  cells = [1,0,0,1,0,0,1,0], n = 1000000000
// Output: [0,0,1,1,1,1,1,0]
TEST_P(PrisonCellsAfterNDaysTest, OfficialExample2) {
  vector<int> cells = {1, 0, 0, 1, 0, 0, 1, 0};
  int n = 1000000000;
  vector<int> expected = {0, 0, 1, 1, 1, 1, 1, 0};
  EXPECT_EQ(expected, solution.prisonAfterNDays(cells, n));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, PrisonCellsAfterNDaysTest,
    ::testing::ValuesIn(PrisonCellsAfterNDaysSolution().getStrategyNames()));

}  // namespace problem_957
}  // namespace leetcode
