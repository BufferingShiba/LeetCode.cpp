#include "leetcode/problems/minimum-score-of-a-path-between-two-cities.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2492 {

class MinimumScoreOfAPathBetweenTwoCitiesTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumScoreOfAPathBetweenTwoCitiesSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
// Output: 5
TEST_P(MinimumScoreOfAPathBetweenTwoCitiesTest, OfficialExample1) {
  int n = 4;
  std::vector<std::vector<int>> roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
  EXPECT_EQ(5, solution.minScore(n, roads));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
// Output: 2
TEST_P(MinimumScoreOfAPathBetweenTwoCitiesTest, OfficialExample2) {
  int n = 4;
  std::vector<std::vector<int>> roads = {{1, 2, 2}, {1, 3, 4}, {3, 4, 7}};
  EXPECT_EQ(2, solution.minScore(n, roads));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumScoreOfAPathBetweenTwoCitiesTest,
    ::testing::ValuesIn(MinimumScoreOfAPathBetweenTwoCitiesSolution().getStrategyNames()));

}  // namespace problem_2492
}  // namespace leetcode
