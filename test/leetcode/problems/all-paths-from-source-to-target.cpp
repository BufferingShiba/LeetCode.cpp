#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

#include "leetcode/problems/all-paths-from-source-to-target.h"

namespace leetcode::problem_797 {
namespace {

std::vector<std::vector<int>> SortPaths(
    std::vector<std::vector<int>> paths) {
  for (auto& p : paths) {
    std::sort(p.begin(), p.end());
  }
  std::sort(paths.begin(), paths.end());
  return paths;
}

}  // namespace

class AllPathsFromSourceToTargetTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  AllPathsFromSourceToTargetSolution solution_;
};

TEST_P(AllPathsFromSourceToTargetTest, Example1) {
  std::vector<std::vector<int>> graph = {{1, 2}, {3}, {3}, {}};
  std::vector<std::vector<int>> expected = {{0, 1, 3}, {0, 2, 3}};
  EXPECT_EQ(SortPaths(solution_.allPathsSourceTarget(graph)),
            SortPaths(expected));
}

TEST_P(AllPathsFromSourceToTargetTest, Example2) {
  std::vector<std::vector<int>> graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
  std::vector<std::vector<int>> expected = {
      {0, 4}, {0, 3, 4}, {0, 1, 3, 4}, {0, 1, 2, 3, 4}, {0, 1, 4}};
  EXPECT_EQ(SortPaths(solution_.allPathsSourceTarget(graph)),
            SortPaths(expected));
}

TEST_P(AllPathsFromSourceToTargetTest, DirectEdgeOnly) {
  std::vector<std::vector<int>> graph = {{1}, {}};
  std::vector<std::vector<int>> expected = {{0, 1}};
  EXPECT_EQ(SortPaths(solution_.allPathsSourceTarget(graph)),
            SortPaths(expected));
}

INSTANTIATE_TEST_SUITE_P(
    AllPathsFromSourceToTargetTestSuite, AllPathsFromSourceToTargetTest,
    ::testing::ValuesIn(AllPathsFromSourceToTargetSolution().getStrategyNames()));

}  // namespace leetcode::problem_797
