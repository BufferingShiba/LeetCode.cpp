#include "leetcode/problems/find-eventual-safe-states.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_802 {

class FindEventualSafeStatesTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindEventualSafeStatesSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
TEST_P(FindEventualSafeStatesTest, OfficialExample1) {
  std::vector<std::vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
  std::vector<int> expected = {2, 4, 5, 6};
  EXPECT_EQ(expected, solution.eventualSafeNodes(graph));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
// Output: [4]
TEST_P(FindEventualSafeStatesTest, OfficialExample2) {
  std::vector<std::vector<int>> graph = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};
  std::vector<int> expected = {4};
  EXPECT_EQ(expected, solution.eventualSafeNodes(graph));
}

TEST_P(FindEventualSafeStatesTest, PureCycleHasNoSafeNodes) {
  std::vector<std::vector<int>> graph = {{1}, {2}, {0}};
  EXPECT_TRUE(solution.eventualSafeNodes(graph).empty());
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, FindEventualSafeStatesTest,
    ::testing::ValuesIn(FindEventualSafeStatesSolution().getStrategyNames()));

}  // namespace problem_802
}  // namespace leetcode
