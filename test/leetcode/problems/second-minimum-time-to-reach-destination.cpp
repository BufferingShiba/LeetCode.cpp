#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/second-minimum-time-to-reach-destination.h"

namespace leetcode {
namespace problem_2045 {

namespace {
std::vector<std::vector<int>> mkEdges(
    std::initializer_list<std::vector<int>> list) {
  return std::vector<std::vector<int>>(list);
}
}  // namespace

class SecondMinimumTimeToReachDestinationTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SecondMinimumTimeToReachDestinationSolution solution;
};

TEST_P(SecondMinimumTimeToReachDestinationTest, Example1) {
  int n = 5;
  auto edges = mkEdges({{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}});
  EXPECT_EQ(solution.secondMinimum(n, edges, 3, 5), 13);
}

TEST_P(SecondMinimumTimeToReachDestinationTest, Example2) {
  int n = 2;
  auto edges = mkEdges({{1, 2}});
  EXPECT_EQ(solution.secondMinimum(n, edges, 3, 2), 11);
}

TEST_P(SecondMinimumTimeToReachDestinationTest, SelfAuthoredTriangleGraph) {
  // n=3, triangle. Shortest hops: 1-3 (1 hop) time=time.
  // Second hops: 1->2->3 (2 hops).
  int n = 3;
  auto edges = mkEdges({{1, 2}, {2, 3}, {1, 3}});
  // min time: start green, 1->3, time after = 2 (change=2 green window [0,2))
  // Actually compute: change=4.
  // min (1 hop): cur=0 green, +2 => 2
  // second: need 2 hops distinct -> 1->2->3: hop1: green cur+=2 =>2 (still green), hop2: cur=2 <4 green, +2 =>4
  EXPECT_EQ(solution.secondMinimum(n, edges, 2, 4), 4);
}

INSTANTIATE_TEST_SUITE_P(
    SecondMinimumTimeToReachDestinationTestSuite,
    SecondMinimumTimeToReachDestinationTest,
    ::testing::ValuesIn(SecondMinimumTimeToReachDestinationSolution().getStrategyNames()));

}  // namespace problem_2045
}  // namespace leetcode
