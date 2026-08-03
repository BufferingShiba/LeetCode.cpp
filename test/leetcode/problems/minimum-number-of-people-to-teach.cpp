#include <gtest/gtest.h>

#include "leetcode/problems/minimum-number-of-people-to-teach.h"

using namespace leetcode::problem_1733;

class MinimumNumberOfPeopleToTeachTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MinimumNumberOfPeopleToTeachSolution solution;
};

TEST_P(MinimumNumberOfPeopleToTeachTest, Example1) {
  int n = 2;
  std::vector<std::vector<int>> languages = {{1}, {2}, {1, 2}};
  std::vector<std::vector<int>> friendships = {{1, 2}, {1, 3}, {2, 3}};
  EXPECT_EQ(solution.minimumTeachings(n, languages, friendships), 1);
}

TEST_P(MinimumNumberOfPeopleToTeachTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> languages = {{2}, {1, 3}, {1, 2}, {3}};
  std::vector<std::vector<int>> friendships = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};
  EXPECT_EQ(solution.minimumTeachings(n, languages, friendships), 2);
}

TEST_P(MinimumNumberOfPeopleToTeachTest, SelfAuthoredNoTeachingNeeded) {
  int n = 2;
  std::vector<std::vector<int>> languages = {{1, 2}, {1, 2}};
  std::vector<std::vector<int>> friendships = {{1, 2}};
  EXPECT_EQ(solution.minimumTeachings(n, languages, friendships), 0);
}

TEST_P(MinimumNumberOfPeopleToTeachTest, SelfAuthoredAllPairsProblematic) {
  int n = 3;
  std::vector<std::vector<int>> languages = {{1}, {2}, {3}};
  std::vector<std::vector<int>> friendships = {{1, 2}, {1, 3}, {2, 3}};
  // Teach language 1: user2 and user3 need it -> 2 users
  EXPECT_EQ(solution.minimumTeachings(n, languages, friendships), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumNumberOfPeopleToTeachTest,
    testing::ValuesIn(
        MinimumNumberOfPeopleToTeachSolution().getStrategyNames()));
