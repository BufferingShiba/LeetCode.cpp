#include "leetcode/problems/total-cost-to-hire-k-workers.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2462 {

class TotalCostToHireKWorkersTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  TotalCostToHireKWorkersSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
// Output: 11
TEST_P(TotalCostToHireKWorkersTest, OfficialExample1) {
  vector<int> costs = {17, 12, 10, 2, 7, 2, 11, 20, 8};
  long long result = solution.totalCost(costs, 3, 4);
  EXPECT_EQ(11, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  costs = [1,2,4,1], k = 3, candidates = 3
// Output: 4
TEST_P(TotalCostToHireKWorkersTest, OfficialExample2) {
  vector<int> costs = {1, 2, 4, 1};
  long long result = solution.totalCost(costs, 3, 3);
  EXPECT_EQ(4, result);
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, TotalCostToHireKWorkersTest,
    ::testing::ValuesIn(TotalCostToHireKWorkersSolution().getStrategyNames()));

}  // namespace problem_2462
}  // namespace leetcode
