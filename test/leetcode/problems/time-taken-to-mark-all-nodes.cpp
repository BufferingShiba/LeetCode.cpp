#include "leetcode/problems/time-taken-to-mark-all-nodes.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3241 {
namespace {

class TimeTakenToMarkAllNodesTest : public ::testing::TestWithParam<std::string> {
 protected:
  TimeTakenToMarkAllNodesSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(TimeTakenToMarkAllNodesTest, Example1) {
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}};
  std::vector<int> expected = {2, 4, 3};
  EXPECT_EQ(solution.timeTaken(edges), expected);
}

TEST_P(TimeTakenToMarkAllNodesTest, Example2) {
  std::vector<std::vector<int>> edges = {{0, 1}};
  std::vector<int> expected = {1, 2};
  EXPECT_EQ(solution.timeTaken(edges), expected);
}

TEST_P(TimeTakenToMarkAllNodesTest, Example3) {
  std::vector<std::vector<int>> edges = {{2, 4}, {0, 1}, {2, 3}, {0, 2}};
  std::vector<int> expected = {4, 6, 3, 5, 5};
  EXPECT_EQ(solution.timeTaken(edges), expected);
}

}  // namespace

INSTANTIATE_TEST_SUITE_P(TimeTakenToMarkAllNodesTests, TimeTakenToMarkAllNodesTest,
                         ::testing::ValuesIn(TimeTakenToMarkAllNodesSolution().getStrategyNames()));

}  // namespace problem_3241
}  // namespace leetcode
