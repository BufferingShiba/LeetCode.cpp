#include "leetcode/problems/minimize-hamming-distance-after-swap-operations.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1722 {

class MinimizeHammingDistanceAfterSwapOperationsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimizeHammingDistanceAfterSwapOperationsSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
// Output: 1
TEST_P(MinimizeHammingDistanceAfterSwapOperationsTest, OfficialExample1) {
  vector<int> source = {1, 2, 3, 4};
  vector<int> target = {2, 1, 4, 5};
  vector<vector<int>> allowedSwaps = {{0, 1}, {2, 3}};
  int expected = 1;
  EXPECT_EQ(expected, solution.minimumHammingDistance(source, target, allowedSwaps));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
// Output: 2
TEST_P(MinimizeHammingDistanceAfterSwapOperationsTest, OfficialExample2) {
  vector<int> source = {1, 2, 3, 4};
  vector<int> target = {1, 3, 2, 4};
  vector<vector<int>> allowedSwaps = {};
  int expected = 2;
  EXPECT_EQ(expected, solution.minimumHammingDistance(source, target, allowedSwaps));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
// Output: 0
TEST_P(MinimizeHammingDistanceAfterSwapOperationsTest, OfficialExample3) {
  vector<int> source = {5, 1, 2, 4, 3};
  vector<int> target = {1, 5, 4, 2, 3};
  vector<vector<int>> allowedSwaps = {{0, 4}, {4, 2}, {1, 3}, {1, 4}};
  int expected = 0;
  EXPECT_EQ(expected, solution.minimumHammingDistance(source, target, allowedSwaps));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimizeHammingDistanceAfterSwapOperationsTest,
    ::testing::ValuesIn(MinimizeHammingDistanceAfterSwapOperationsSolution().getStrategyNames()));

}  // namespace problem_1722
}  // namespace leetcode
