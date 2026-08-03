#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/palindromic-path-queries-in-a-tree.h"

namespace leetcode::problem_3841 {

class PalindromicPathQueriesInATreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  PalindromicPathQueriesInATreeSolution solution_;
};

TEST_P(PalindromicPathQueriesInATreeTest, Example1) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}};
  std::string s = "aac";
  std::vector<std::string> queries = {"query 0 2", "update 1 b",
                                      "query 0 2"};
  std::vector<bool> expected = {true, false};
  EXPECT_EQ(solution_.palindromePath(n, edges, s, queries), expected);
}

TEST_P(PalindromicPathQueriesInATreeTest, Example2) {
  int n = 4;
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}};
  std::string s = "abca";
  std::vector<std::string> queries = {
      "query 1 2", "update 0 b", "query 2 3", "update 3 a", "query 1 3"};
  std::vector<bool> expected = {false, false, true};
  EXPECT_EQ(solution_.palindromePath(n, edges, s, queries), expected);
}

TEST_P(PalindromicPathQueriesInATreeTest, SelfAuthoredChainAfterDeepUpdate) {
  int n = 5;
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
  std::string s = "abcde";
  // Path 0->4 is "abcde": all five odd -> not palindrome.
  // Update node 3 to 'a' changes subtree {3,4}; now path 0->4 =
  // "abcae" which still has b,c,e odd (3) -> not palindrome.
  std::vector<std::string> queries = {"query 0 4", "update 3 a",
                                      "query 0 4", "update 4 d",
                                      "query 0 4"};
  // After update 4 d: s="abcdd"; path 0->4="abcdd": a,b,c odd (3).
  std::vector<bool> expected = {false, false, false};
  EXPECT_EQ(solution_.palindromePath(n, edges, s, queries), expected);
}

TEST_P(PalindromicPathQueriesInATreeTest, SelfAuthoredSingleNodeQuery) {
  int n = 1;
  std::vector<std::vector<int>> edges = {};
  std::string s = "a";
  std::vector<std::string> queries = {"query 0 0", "update 0 b",
                                      "query 0 0"};
  std::vector<bool> expected = {true, true};
  EXPECT_EQ(solution_.palindromePath(n, edges, s, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    PalindromicPathQueriesInATreeTestSuite, PalindromicPathQueriesInATreeTest,
    ::testing::ValuesIn(
        PalindromicPathQueriesInATreeSolution().getStrategyNames()));

}  // namespace leetcode::problem_3841
