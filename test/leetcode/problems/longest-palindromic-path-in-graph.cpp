#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

#include "leetcode/problems/longest-palindromic-path-in-graph.h"

namespace leetcode::problem_3615 {

class LongestPalindromicPathInGraphTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  LongestPalindromicPathInGraphSolution solution_;
};

TEST_P(LongestPalindromicPathInGraphTest, Example1) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}};
  std::string label = "aba";
  EXPECT_EQ(3, solution_.maxLen(n, edges, label));
}

TEST_P(LongestPalindromicPathInGraphTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}};
  std::string label = "abc";
  EXPECT_EQ(1, solution_.maxLen(n, edges, label));
}

TEST_P(LongestPalindromicPathInGraphTest, Example3) {
  int n = 4;
  std::vector<std::vector<int>> edges = {{0, 2}, {0, 3}, {3, 1}};
  std::string label = "bbac";
  EXPECT_EQ(3, solution_.maxLen(n, edges, label));
}

TEST_P(LongestPalindromicPathInGraphTest, SelfAuthoredSingleNode) {
  int n = 1;
  std::vector<std::vector<int>> edges = {};
  std::string label = "a";
  EXPECT_EQ(1, solution_.maxLen(n, edges, label));
}

TEST_P(LongestPalindromicPathInGraphTest, SelfAuthoredTwoNodePath) {
  int n = 2;
  std::vector<std::vector<int>> edges = {{0, 1}};
  std::string label = "aa";
  EXPECT_EQ(2, solution_.maxLen(n, edges, label));
}

INSTANTIATE_TEST_SUITE_P(
    LongestPalindromicPathInGraphTestSuite, LongestPalindromicPathInGraphTest,
    ::testing::ValuesIn(LongestPalindromicPathInGraphSolution().getStrategyNames()));

}  // namespace leetcode::problem_3615
