#include "leetcode/problems/minimum-number-of-arrows-to-burst-balloons.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_452 {

class MinimumNumberOfArrowsToBurstBalloonsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumNumberOfArrowsToBurstBalloonsSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  points = [[10,16],[2,8],[1,6],[7,12]]
// Output: 2
TEST_P(MinimumNumberOfArrowsToBurstBalloonsTest, OfficialExample1) {
  vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  int result = solution.findMinArrowShots(points);
  EXPECT_EQ(2, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  points = [[1,2],[3,4],[5,6],[7,8]]
// Output: 4
TEST_P(MinimumNumberOfArrowsToBurstBalloonsTest, OfficialExample2) {
  vector<vector<int>> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  int result = solution.findMinArrowShots(points);
  EXPECT_EQ(4, result);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  points = [[1,2],[2,3],[3,4],[4,5]]
// Output: 2
TEST_P(MinimumNumberOfArrowsToBurstBalloonsTest, OfficialExample3) {
  vector<vector<int>> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  int result = solution.findMinArrowShots(points);
  EXPECT_EQ(2, result);
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumNumberOfArrowsToBurstBalloonsTest,
    ::testing::ValuesIn(MinimumNumberOfArrowsToBurstBalloonsSolution().getStrategyNames()));

}  // namespace problem_452
}  // namespace leetcode
