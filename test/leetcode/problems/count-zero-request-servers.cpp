#include <gtest/gtest.h>

#include "leetcode/problems/count-zero-request-servers.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2747 {

class CountZeroRequestServersTest : public ::testing::TestWithParam<std::string> {
 protected:
  CountZeroRequestServersSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(CountZeroRequestServersTest, Example1) {
  int n = 3;
  std::vector<std::vector<int>> logs = {{1, 3}, {2, 6}, {1, 5}};
  int x = 5;
  std::vector<int> queries = {10, 11};
  std::vector<int> expected = {1, 2};
  EXPECT_EQ(solution.countServers(n, logs, x, queries), expected);
}

TEST_P(CountZeroRequestServersTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> logs = {{2, 4}, {2, 1}, {1, 2}, {3, 1}};
  int x = 2;
  std::vector<int> queries = {3, 4};
  std::vector<int> expected = {0, 1};
  EXPECT_EQ(solution.countServers(n, logs, x, queries), expected);
}

TEST_P(CountZeroRequestServersTest, SelfAuthoredMultipleQueriesSameInterval) {
  // Two queries share the same search window (strict bounds differ by constant but
  // given x < queries[i], window [lo, query] is always valid).
  int n = 2;
  std::vector<std::vector<int>> logs = {{1, 5}, {2, 7}, {1, 9}};
  int x = 2;
  std::vector<int> queries = {6, 8};
  // q=6: window [4,6] -> server1(time5), server2 none in window -> server2 zero.
  // q=8: window [6,8] -> server2(time7), server1 none -> server1 zero.
  std::vector<int> expected = {1, 1};
  EXPECT_EQ(solution.countServers(n, logs, x, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    CountZeroRequestServersTestSuite, CountZeroRequestServersTest,
    ::testing::ValuesIn(CountZeroRequestServersSolution().getStrategyNames()));

}  // namespace problem_2747
}  // namespace leetcode
