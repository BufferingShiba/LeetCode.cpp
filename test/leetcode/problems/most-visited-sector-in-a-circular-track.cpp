#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/most-visited-sector-in-a-circular-track.h"

namespace leetcode::problem_1560 {

class MostVisitedSectorInACircularTrackTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MostVisitedSectorInACircularTrackSolution solution_;
};

TEST_P(MostVisitedSectorInACircularTrackTest, Example1) {
  int n = 4;
  std::vector<int> rounds = {1, 3, 1, 2};
  std::vector<int> expected = {1, 2};
  EXPECT_EQ(solution_.mostVisited(n, rounds), expected);
}

TEST_P(MostVisitedSectorInACircularTrackTest, Example2) {
  int n = 2;
  std::vector<int> rounds = {2, 1, 2, 1, 2, 1, 2, 1, 2};
  std::vector<int> expected = {2};
  EXPECT_EQ(solution_.mostVisited(n, rounds), expected);
}

TEST_P(MostVisitedSectorInACircularTrackTest, Example3) {
  int n = 7;
  std::vector<int> rounds = {1, 3, 5, 7};
  std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7};
  EXPECT_EQ(solution_.mostVisited(n, rounds), expected);
}

TEST_P(MostVisitedSectorInACircularTrackTest, SelfAuthoredSingleRound) {
  // n=5, one round from 2 to 4: visited sectors {2(start),3,4(end)}.
  int n = 5;
  std::vector<int> rounds = {2, 4};
  std::vector<int> expected = {2, 3, 4};
  EXPECT_EQ(solution_.mostVisited(n, rounds), expected);
}

TEST_P(MostVisitedSectorInACircularTrackTest, SelfAuthoredWrapAround) {
  // n=3, one round from 3 to 2 (wraps): {3(start),1,2(end)} each visited once.
  int n = 3;
  std::vector<int> rounds = {3, 2};
  std::vector<int> expected = {1, 2, 3};
  EXPECT_EQ(solution_.mostVisited(n, rounds), expected);
}

INSTANTIATE_TEST_SUITE_P(
    MostVisitedSectorInACircularTrackTestParameterized,
    MostVisitedSectorInACircularTrackTest,
    ::testing::ValuesIn(
        MostVisitedSectorInACircularTrackSolution().getStrategyNames()));

}  // namespace leetcode::problem_1560
