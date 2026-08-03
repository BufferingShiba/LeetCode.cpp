#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-champion-ii.h"

namespace leetcode {
namespace problem_2924 {
namespace {

class FindChampionIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  FindChampionIiSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(FindChampionIiTest, Example1) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}};
  EXPECT_EQ(0, solution.findChampion(n, edges));
}

TEST_P(FindChampionIiTest, Example2) {
  int n = 4;
  std::vector<std::vector<int>> edges = {{0, 2}, {1, 3}, {1, 2}};
  EXPECT_EQ(-1, solution.findChampion(n, edges));
}

TEST_P(FindChampionIiTest, SelfAuthoredNoEdgesUnique) {
  int n = 1;
  std::vector<std::vector<int>> edges;
  EXPECT_EQ(0, solution.findChampion(n, edges));
}

TEST_P(FindChampionIiTest, SelfAuthoredNoEdgeAllCandidates) {
  int n = 3;
  std::vector<std::vector<int>> edges;
  EXPECT_EQ(-1, solution.findChampion(n, edges));
}

TEST_P(FindChampionIiTest, SelfAuthoredOneCandidateBeatsAll) {
  int n = 4;
  std::vector<std::vector<int>> edges = {{2, 0}, {2, 1}, {2, 3}};
  EXPECT_EQ(2, solution.findChampion(n, edges));
}

INSTANTIATE_TEST_SUITE_P(
    FindChampionIiStrategies, FindChampionIiTest,
    ::testing::ValuesIn(FindChampionIiSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2924
}  // namespace leetcode
