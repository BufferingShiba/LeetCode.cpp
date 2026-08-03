#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/candy.h"

using leetcode::problem_135::CandySolution;

class CandyTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CandySolution solution;
};

TEST_P(CandyTest, Example1) {
  std::vector<int> ratings = {1, 0, 2};
  EXPECT_EQ(5, solution.candy(ratings));
}

TEST_P(CandyTest, Example2) {
  std::vector<int> ratings = {1, 2, 2};
  EXPECT_EQ(4, solution.candy(ratings));
}

TEST_P(CandyTest, SelfAuthoredSingleChild) {
  std::vector<int> ratings = {7};
  EXPECT_EQ(1, solution.candy(ratings));
}

TEST_P(CandyTest, SelfAuthoredStrictlyIncreasing) {
  std::vector<int> ratings = {1, 2, 3, 4, 5};
  EXPECT_EQ(15, solution.candy(ratings));
}

TEST_P(CandyTest, SelfAuthoredStrictlyDecreasing) {
  std::vector<int> ratings = {5, 4, 3, 2, 1};
  EXPECT_EQ(15, solution.candy(ratings));
}

TEST_P(CandyTest, SelfAuthoredEqualRatings) {
  std::vector<int> ratings = {3, 3, 3, 3};
  EXPECT_EQ(4, solution.candy(ratings));
}

INSTANTIATE_TEST_SUITE_P(
    CandyStrategies, CandyTest,
    ::testing::ValuesIn(CandySolution().getStrategyNames()));
