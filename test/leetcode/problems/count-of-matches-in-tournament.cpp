#include "leetcode/problems/count-of-matches-in-tournament.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_1688 {

class CountOfMatchesInTournamentTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountOfMatchesInTournamentSolution solution;
};

TEST_P(CountOfMatchesInTournamentTest, Example1) {
  EXPECT_EQ(6, solution.getSolution()(7));
}

TEST_P(CountOfMatchesInTournamentTest, Example2) {
  EXPECT_EQ(13, solution.getSolution()(14));
}

TEST_P(CountOfMatchesInTournamentTest, SelfAuthoredSingleTeam) {
  // One team needs 0 matches to be crowned champion.
  EXPECT_EQ(0, solution.getSolution()(1));
}

TEST_P(CountOfMatchesInTournamentTest, SelfAuthoredPowerOfTwo) {
  EXPECT_EQ(7, solution.getSolution()(8));
}

INSTANTIATE_TEST_SUITE_P(
    CountOfMatchesInTournamentTestCases, CountOfMatchesInTournamentTest,
    ::testing::ValuesIn(CountOfMatchesInTournamentSolution().getStrategyNames()));

}  // namespace problem_1688
}  // namespace leetcode
