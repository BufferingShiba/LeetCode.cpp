#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-champion-i.h"

namespace leetcode {
namespace problem_2923 {

class FindChampionITest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindChampionISolution solution;
};

TEST_P(FindChampionITest, Example1) {
  std::vector<std::vector<int>> grid = {{0, 1}, {0, 0}};
  EXPECT_EQ(0, solution.getSolution()(grid));
}

TEST_P(FindChampionITest, Example2) {
  std::vector<std::vector<int>> grid = {{0, 0, 1}, {1, 0, 1}, {0, 0, 0}};
  EXPECT_EQ(1, solution.getSolution()(grid));
}

TEST_P(FindChampionITest, SelfAuthoredLargerTournament) {
  std::vector<std::vector<int>> grid = {{0, 1, 1, 1},
                                        {0, 0, 1, 1},
                                        {0, 0, 0, 1},
                                        {0, 0, 0, 0}};
  // Team 0 beats everyone, so it is the champion.
  EXPECT_EQ(0, solution.getSolution()(grid));
}

INSTANTIATE_TEST_SUITE_P(
    FindChampionI, FindChampionITest,
    ::testing::ValuesIn(FindChampionISolution().getStrategyNames()));

}  // namespace problem_2923
}  // namespace leetcode
