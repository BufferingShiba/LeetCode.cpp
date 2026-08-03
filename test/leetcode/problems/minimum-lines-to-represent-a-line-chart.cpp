#include "leetcode/problems/minimum-lines-to-represent-a-line-chart.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2280 {

class MinimumLinesToRepresentALineChartTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumLinesToRepresentALineChartSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  stockPrices = [[1,7],[2,6],[3,5],[4,4],[5,4],[6,3],[7,2],[8,1]]
// Output: 3
TEST_P(MinimumLinesToRepresentALineChartTest, OfficialExample1) {
  vector<vector<int>> stockPrices = {{1, 7}, {2, 6}, {3, 5}, {4, 4}, {5, 4}, {6, 3}, {7, 2}, {8, 1}};
  int result = solution.minimumLines(stockPrices);
  EXPECT_EQ(3, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  stockPrices = [[3,4],[1,2],[7,8],[2,3]]
// Output: 1
TEST_P(MinimumLinesToRepresentALineChartTest, OfficialExample2) {
  vector<vector<int>> stockPrices = {{3, 4}, {1, 2}, {7, 8}, {2, 3}};
  int result = solution.minimumLines(stockPrices);
  EXPECT_EQ(1, result);
}

// ===== SelfAuthored: Single point =====
TEST_P(MinimumLinesToRepresentALineChartTest, SinglePoint) {
  vector<vector<int>> stockPrices = {{1, 2}};
  int result = solution.minimumLines(stockPrices);
  EXPECT_EQ(0, result);
}

// ===== SelfAuthored: Multiple points not collinear =====
TEST_P(MinimumLinesToRepresentALineChartTest, NonCollinear) {
  vector<vector<int>> stockPrices = {{1, 7}, {2, 6}, {3, 5}, {4, 4}, {5, 4}};
  int result = solution.minimumLines(stockPrices);
  EXPECT_EQ(2, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumLinesToRepresentALineChartTest,
    ::testing::ValuesIn(MinimumLinesToRepresentALineChartSolution().getStrategyNames()));

}  // namespace problem_2280
}  // namespace leetcode
