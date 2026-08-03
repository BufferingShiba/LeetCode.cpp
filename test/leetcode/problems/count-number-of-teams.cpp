#include "leetcode/problems/count-number-of-teams.h"

#include <gtest/gtest.h>
#include <vector>
#include <string>

namespace leetcode {
namespace problem_1395 {

class CountNumberOfTeamsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  CountNumberOfTeamsSolution solution;
};

TEST_P(CountNumberOfTeamsTest, Example1) {
  std::vector<int> rating = {2, 5, 3, 4, 1};
  EXPECT_EQ(solution.numTeams(rating), 3);
}

TEST_P(CountNumberOfTeamsTest, Example2) {
  std::vector<int> rating = {2, 1, 3};
  EXPECT_EQ(solution.numTeams(rating), 0);
}

TEST_P(CountNumberOfTeamsTest, Example3) {
  std::vector<int> rating = {1, 2, 3, 4};
  EXPECT_EQ(solution.numTeams(rating), 4);
}

INSTANTIATE_TEST_SUITE_P(
    CountNumberOfTeamsStrategies,
    CountNumberOfTeamsTest,
    ::testing::ValuesIn(CountNumberOfTeamsSolution().getStrategyNames()));

}  // namespace problem_1395
}  // namespace leetcode
