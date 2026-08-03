#include "leetcode/problems/closest-room.h"

#include <gtest/gtest.h>

namespace leetcode::problem_1847 {

class ClosestRoomTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ClosestRoomSolution solution;
};

TEST_P(ClosestRoomTest, Example1) {
  std::vector<std::vector<int>> rooms = {{2, 2}, {1, 2}, {3, 2}};
  std::vector<std::vector<int>> queries = {{3, 1}, {3, 3}, {5, 2}};
  std::vector<int> expected = {3, -1, 3};
  EXPECT_EQ(solution.getSolution()(rooms, queries), expected);
}

TEST_P(ClosestRoomTest, Example2) {
  std::vector<std::vector<int>> rooms = {{1, 4}, {2, 3}, {3, 5}, {4, 1}, {5, 2}};
  std::vector<std::vector<int>> queries = {{2, 3}, {2, 4}, {2, 5}};
  std::vector<int> expected = {2, 1, 3};
  EXPECT_EQ(solution.getSolution()(rooms, queries), expected);
}

TEST_P(ClosestRoomTest, SelfAuthoredTieTakesSmallestId) {
  std::vector<std::vector<int>> rooms = {{1, 2}, {5, 2}};
  std::vector<std::vector<int>> queries = {{3, 2}};
  // |1-3|=2, |5-3|=2 -> tie, smallest id wins -> 1
  std::vector<int> expected = {1};
  EXPECT_EQ(solution.getSolution()(rooms, queries), expected);
}

TEST_P(ClosestRoomTest, SelfAuthoredNoRoomMeetsMinSize) {
  std::vector<std::vector<int>> rooms = {{2, 2}, {1, 2}, {3, 2}};
  std::vector<std::vector<int>> queries = {{1, 5}};
  std::vector<int> expected = {-1};
  EXPECT_EQ(solution.getSolution()(rooms, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    ClosestRoomTestCases, ClosestRoomTest,
    ::testing::ValuesIn(ClosestRoomSolution().getStrategyNames()));

}  // namespace leetcode::problem_1847
