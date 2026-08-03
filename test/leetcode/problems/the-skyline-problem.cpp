#include <gtest/gtest.h>

#include "leetcode/problems/the-skyline-problem.h"

namespace leetcode {
namespace problem_218 {

class TheSkylineProblemTest : public ::testing::TestWithParam<std::string> {
 protected:
  TheSkylineProblemSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(TheSkylineProblemTest, Example1) {
  std::vector<std::vector<int>> buildings = {
      {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
  std::vector<std::vector<int>> expected = {
      {2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}};
  EXPECT_EQ(expected, solution.getSkyline(buildings));
}

TEST_P(TheSkylineProblemTest, Example2) {
  std::vector<std::vector<int>> buildings = {{0, 2, 3}, {2, 5, 3}};
  std::vector<std::vector<int>> expected = {{0, 3}, {5, 0}};
  EXPECT_EQ(expected, solution.getSkyline(buildings));
}

TEST_P(TheSkylineProblemTest, SelfAuthoredEdgeCaseAdjacentDifferentHeights) {
  std::vector<std::vector<int>> buildings = {{0, 2, 1}, {2, 4, 3}};
  std::vector<std::vector<int>> expected = {{0, 1}, {2, 3}, {4, 0}};
  EXPECT_EQ(expected, solution.getSkyline(buildings));
}

TEST_P(TheSkylineProblemTest, SelfAuthoredEdgeCaseTallerBuildingOnTopOfShorter) {
  std::vector<std::vector<int>> buildings = {{0, 3, 3}, {1, 2, 5}};
  std::vector<std::vector<int>> expected = {{0, 3}, {1, 5}, {2, 3}, {3, 0}};
  EXPECT_EQ(expected, solution.getSkyline(buildings));
}

INSTANTIATE_TEST_SUITE_P(
    TheSkylineProblemTestSuite, TheSkylineProblemTest,
    ::testing::ValuesIn(TheSkylineProblemSolution().getStrategyNames()));

}  // namespace problem_218
}  // namespace leetcode
