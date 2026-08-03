#include "leetcode/problems/shortest-distance-after-road-addition-queries-ii.h"
#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3244 {

class ShortestDistanceAfterRoadAdditionQueriesIiTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ShortestDistanceAfterRoadAdditionQueriesIiSolution solution;
};

TEST_P(ShortestDistanceAfterRoadAdditionQueriesIiTest, Example1) {
  int n = 5;
  std::vector<std::vector<int>> queries = {{2, 4}, {0, 2}, {0, 4}};
  std::vector<int> expected = {3, 2, 1};
  EXPECT_EQ(solution.getSolution()(n, queries), expected);
}

TEST_P(ShortestDistanceAfterRoadAdditionQueriesIiTest, Example2) {
  int n = 4;
  std::vector<std::vector<int>> queries = {{0, 3}, {0, 2}};
  std::vector<int> expected = {1, 1};
  EXPECT_EQ(solution.getSolution()(n, queries), expected);
}

TEST_P(ShortestDistanceAfterRoadAdditionQueriesIiTest, SelfAuthoredNoQueries) {
  int n = 3;
  // If queries list is empty, answer is empty; but signature requires at least 1.
  // Minimal: directly jump from 0 to n-1.
  std::vector<std::vector<int>> queries = {{0, 2}};
  std::vector<int> expected = {1};
  EXPECT_EQ(solution.getSolution()(n, queries), expected);
}

TEST_P(ShortestDistanceAfterRoadAdditionQueriesIiTest, SelfAuthoredNestedQueries) {
  int n = 5;
  std::vector<std::vector<int>> queries = {{1, 3}, {0, 4}};
  // After [1,3]: path {1,2,3,4} -> remove 2, keep {1,3,4}, length 3.
  // After [0,4]: remove 1,3 inside (0,4), keep {4}, length 1.
  std::vector<int> expected = {3, 1};
  EXPECT_EQ(solution.getSolution()(n, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    ShortestDistanceAfterRoadAdditionQueriesIiTests,
    ShortestDistanceAfterRoadAdditionQueriesIiTest,
    testing::ValuesIn(
        ShortestDistanceAfterRoadAdditionQueriesIiSolution().getStrategyNames()));

}  // namespace problem_3244
}  // namespace leetcode
