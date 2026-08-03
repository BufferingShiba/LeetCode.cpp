#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/kids-with-the-greatest-number-of-candies.h"

namespace leetcode::problem_1431 {

class KidsWithTheGreatestNumberOfCandiesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  KidsWithTheGreatestNumberOfCandiesSolution solution;
};

TEST_P(KidsWithTheGreatestNumberOfCandiesTest, Example1) {
  std::vector<int> candies{2, 3, 5, 1, 3};
  int extraCandies = 3;
  std::vector<bool> expected{true, true, true, false, true};
  EXPECT_EQ(solution.kidsWithCandies(candies, extraCandies), expected);
}

TEST_P(KidsWithTheGreatestNumberOfCandiesTest, Example2) {
  std::vector<int> candies{4, 2, 1, 1, 2};
  int extraCandies = 1;
  std::vector<bool> expected{true, false, false, false, false};
  EXPECT_EQ(solution.kidsWithCandies(candies, extraCandies), expected);
}

TEST_P(KidsWithTheGreatestNumberOfCandiesTest, Example3) {
  std::vector<int> candies{12, 1, 12};
  int extraCandies = 10;
  std::vector<bool> expected{true, false, true};
  EXPECT_EQ(solution.kidsWithCandies(candies, extraCandies), expected);
}

TEST_P(KidsWithTheGreatestNumberOfCandiesTest, SelfAuthoredMinN) {
  std::vector<int> candies{1, 2};
  int extraCandies = 1;
  std::vector<bool> expected{true, true};
  EXPECT_EQ(solution.kidsWithCandies(candies, extraCandies), expected);
}

INSTANTIATE_TEST_SUITE_P(
    KidsWithTheGreatestNumberOfCandiesTestSuite,
    KidsWithTheGreatestNumberOfCandiesTest,
    ::testing::ValuesIn(
        KidsWithTheGreatestNumberOfCandiesSolution().getStrategyNames()));

}  // namespace leetcode::problem_1431
