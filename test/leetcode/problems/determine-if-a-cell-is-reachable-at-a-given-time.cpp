#include "leetcode/problems/determine-if-a-cell-is-reachable-at-a-given-time.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2849 {

class DetermineIfACellIsReachableAtAGivenTimeTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DetermineIfACellIsReachableAtAGivenTimeSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  sx = 2, sy = 4, fx = 7, fy = 7, t = 6
// Output: true
TEST_P(DetermineIfACellIsReachableAtAGivenTimeTest, OfficialExample1) {
  EXPECT_EQ(true, solution.isReachableAtTime(2, 4, 7, 7, 6));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  sx = 3, sy = 1, fx = 7, fy = 3, t = 3
// Output: false
TEST_P(DetermineIfACellIsReachableAtAGivenTimeTest, OfficialExample2) {
  EXPECT_EQ(false, solution.isReachableAtTime(3, 1, 7, 3, 3));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, DetermineIfACellIsReachableAtAGivenTimeTest,
    ::testing::ValuesIn(DetermineIfACellIsReachableAtAGivenTimeSolution().getStrategyNames()));

}  // namespace problem_2849
}  // namespace leetcode
