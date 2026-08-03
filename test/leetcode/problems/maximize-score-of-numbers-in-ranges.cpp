#include "leetcode/problems/maximize-score-of-numbers-in-ranges.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3281 {

class MaximizeScoreOfNumbersInRangesTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximizeScoreOfNumbersInRangesSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  start = [6,0,3], d = 2
// Output: 4
TEST_P(MaximizeScoreOfNumbersInRangesTest, OfficialExample1) {
  vector<int> start = {6, 0, 3};
  int d = 2;
  EXPECT_EQ(4, solution.maxPossibleScore(start, d));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  start = [2,6,13,13], d = 5
// Output: 5
TEST_P(MaximizeScoreOfNumbersInRangesTest, OfficialExample2) {
  vector<int> start = {2, 6, 13, 13};
  int d = 5;
  EXPECT_EQ(5, solution.maxPossibleScore(start, d));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximizeScoreOfNumbersInRangesTest,
    ::testing::ValuesIn(MaximizeScoreOfNumbersInRangesSolution().getStrategyNames()));

}  // namespace problem_3281
}  // namespace leetcode
