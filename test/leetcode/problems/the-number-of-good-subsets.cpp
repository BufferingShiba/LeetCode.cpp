#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/the-number-of-good-subsets.h"

using leetcode::problem_1994::TheNumberOfGoodSubsetsSolution;

class TheNumberOfGoodSubsetsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  TheNumberOfGoodSubsetsSolution solution;
};

TEST_P(TheNumberOfGoodSubsetsTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(solution.numberOfGoodSubsets(nums), 6);
}

TEST_P(TheNumberOfGoodSubsetsTest, Example2) {
  std::vector<int> nums = {4, 2, 3, 15};
  EXPECT_EQ(solution.numberOfGoodSubsets(nums), 5);
}

TEST_P(TheNumberOfGoodSubsetsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {4};
  EXPECT_EQ(solution.numberOfGoodSubsets(nums), 0);
}

TEST_P(TheNumberOfGoodSubsetsTest, SelfAuthoredAllOnes) {
  std::vector<int> nums = {1, 1, 1};
  EXPECT_EQ(solution.numberOfGoodSubsets(nums), 0);
}

TEST_P(TheNumberOfGoodSubsetsTest, SelfAuthoredOnlyPrime) {
  std::vector<int> nums = {2};
  EXPECT_EQ(solution.numberOfGoodSubsets(nums), 1);
}

TEST_P(TheNumberOfGoodSubsetsTest, SelfAuthoredTwoDistinctPrimes) {
  std::vector<int> nums = {6, 2};
  // 6 = 2*3 (distinct), 2 = 2. Subsets: [6], [2].
  EXPECT_EQ(solution.numberOfGoodSubsets(nums), 2);
}

TEST_P(TheNumberOfGoodSubsetsTest, DuplicateSquareFreeValuesAreIndexChoices) {
  std::vector<int> nums = {6, 8, 1, 8, 6, 5, 6, 11, 17};
  EXPECT_EQ(solution.numberOfGoodSubsets(nums), 62);
}

INSTANTIATE_TEST_SUITE_P(
    TheNumberOfGoodSubsetsTestCases, TheNumberOfGoodSubsetsTest,
    ::testing::ValuesIn(TheNumberOfGoodSubsetsSolution().getStrategyNames()));
