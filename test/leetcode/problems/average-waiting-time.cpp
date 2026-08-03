#include "leetcode/problems/average-waiting-time.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1701 {

class AverageWaitingTimeTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  AverageWaitingTimeSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  customers = [[1,2],[2,5],[4,3]]
// Output: 5.00000
TEST_P(AverageWaitingTimeTest, OfficialExample1) {
  vector<vector<int>> customers = {{1, 2}, {2, 5}, {4, 3}};
  double result = solution.averageWaitingTime(customers);
  EXPECT_NEAR(5.0, result, 1e-5);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  customers = [[5,2],[5,4],[10,3],[20,1]]
// Output: 3.25000
TEST_P(AverageWaitingTimeTest, OfficialExample2) {
  vector<vector<int>> customers = {{5, 2}, {5, 4}, {10, 3}, {20, 1}};
  double result = solution.averageWaitingTime(customers);
  EXPECT_NEAR(3.25, result, 1e-5);
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, AverageWaitingTimeTest,
    ::testing::ValuesIn(AverageWaitingTimeSolution().getStrategyNames()));

}  // namespace problem_1701
}  // namespace leetcode
