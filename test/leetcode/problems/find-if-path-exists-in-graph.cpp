#include <gtest/gtest.h>
#include "leetcode/problems/find-if-path-exists-in-graph.h"
#include <string>

namespace leetcode {
namespace problem_1971 {
namespace {

class FindIfPathExistsInGraphTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindIfPathExistsInGraphSolution solution_;
};

TEST_P(FindIfPathExistsInGraphTest, Example1) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
  EXPECT_TRUE(solution_.validPath(n, edges, 0, 2));
}

TEST_P(FindIfPathExistsInGraphTest, Example2) {
  int n = 6;
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
  EXPECT_FALSE(solution_.validPath(n, edges, 0, 5));
}

TEST_P(FindIfPathExistsInGraphTest, SelfAuthoredSameVertex) {
  int n = 1;
  std::vector<std::vector<int>> edges = {};
  EXPECT_TRUE(solution_.validPath(n, edges, 0, 0));
}

TEST_P(FindIfPathExistsInGraphTest, SelfAuthoredNoEdgesDifferentVertices) {
  int n = 3;
  std::vector<std::vector<int>> edges = {};
  EXPECT_FALSE(solution_.validPath(n, edges, 0, 2));
}

INSTANTIATE_TEST_SUITE_P(
    FindIfPathExistsInGraphTestSuite, FindIfPathExistsInGraphTest,
    ::testing::ValuesIn(FindIfPathExistsInGraphSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1971
}  // namespace leetcode
