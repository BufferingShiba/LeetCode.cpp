#include "leetcode/problems/count-pairs-of-points-with-distance-k.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2857 {

class CountPairsOfPointsWithDistanceKTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountPairsOfPointsWithDistanceKSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  coordinates = [[1,2],[4,2],[1,3],[5,2]], k = 5
// Output: 2
TEST_P(CountPairsOfPointsWithDistanceKTest, OfficialExample1) {
  vector<vector<int>> coordinates = {{1, 2}, {4, 2}, {1, 3}, {5, 2}};
  int k = 5;
  EXPECT_EQ(2, solution.countPairs(coordinates, k));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  coordinates = [[1,3],[1,3],[1,3],[1,3],[1,3]], k = 0
// Output: 10
TEST_P(CountPairsOfPointsWithDistanceKTest, OfficialExample2) {
  vector<vector<int>> coordinates = {{1, 3}, {1, 3}, {1, 3}, {1, 3}, {1, 3}};
  int k = 0;
  EXPECT_EQ(10, solution.countPairs(coordinates, k));
}

TEST_P(CountPairsOfPointsWithDistanceKTest, ExampleZeroDistanceNoMatch) {
  // Different points always have non-zero XOR distance, count only identical.
  vector<vector<int>> coordinates = {{1, 3}, {2, 4}};
  EXPECT_EQ(0, solution.countPairs(coordinates, 0));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, CountPairsOfPointsWithDistanceKTest,
    ::testing::ValuesIn(CountPairsOfPointsWithDistanceKSolution().getStrategyNames()));

}  // namespace problem_2857
}  // namespace leetcode
