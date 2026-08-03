#include <gtest/gtest.h>

#include "leetcode/problems/distribute-candies-to-people.h"

namespace leetcode::problem_1103 {

class DistributeCandiesToPeopleTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DistributeCandiesToPeopleSolution solution;
};

TEST_P(DistributeCandiesToPeopleTest, Example1) {
  EXPECT_EQ(solution.distributeCandies(7, 4), (std::vector<int>{1, 2, 3, 1}));
}

TEST_P(DistributeCandiesToPeopleTest, Example2) {
  EXPECT_EQ(solution.distributeCandies(10, 3), (std::vector<int>{5, 2, 3}));
}

TEST_P(DistributeCandiesToPeopleTest, SelfAuthoredSinglePerson) {
  EXPECT_EQ(solution.distributeCandies(6, 1), (std::vector<int>{6}));
}

TEST_P(DistributeCandiesToPeopleTest, SelfAuthoredLessThanNumberOfPeople) {
  EXPECT_EQ(solution.distributeCandies(3, 5), (std::vector<int>{1, 2, 0, 0, 0}));
}

INSTANTIATE_TEST_SUITE_P(
    DistributeCandiesToPeopleTestSuite, DistributeCandiesToPeopleTest,
    ::testing::ValuesIn(DistributeCandiesToPeopleSolution().getStrategyNames()));

}  // namespace leetcode::problem_1103
