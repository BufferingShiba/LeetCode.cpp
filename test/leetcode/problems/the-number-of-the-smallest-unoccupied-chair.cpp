#include <gtest/gtest.h>

#include "leetcode/problems/the-number-of-the-smallest-unoccupied-chair.h"

using namespace leetcode::problem_1942;

class TheNumberOfTheSmallestUnoccupiedChairTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  TheNumberOfTheSmallestUnoccupiedChairSolution solution;
};

TEST_P(TheNumberOfTheSmallestUnoccupiedChairTest, Example1) {
  std::vector<std::vector<int>> times = {{1, 4}, {2, 3}, {4, 6}};
  EXPECT_EQ(solution.smallestChair(times, 1), 1);
}

TEST_P(TheNumberOfTheSmallestUnoccupiedChairTest, Example2) {
  std::vector<std::vector<int>> times = {{3, 10}, {1, 5}, {2, 6}};
  EXPECT_EQ(solution.smallestChair(times, 0), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, TheNumberOfTheSmallestUnoccupiedChairTest,
    testing::ValuesIn(
        TheNumberOfTheSmallestUnoccupiedChairSolution().getStrategyNames()));
