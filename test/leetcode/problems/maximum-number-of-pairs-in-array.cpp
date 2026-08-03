#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/maximum-number-of-pairs-in-array.h"

namespace leetcode::problem_2341 {

class MaximumNumberOfPairsInArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumNumberOfPairsInArraySolution solution;
};

TEST_P(MaximumNumberOfPairsInArrayTest, Example1) {
  std::vector<int> nums{1, 3, 2, 1, 3, 2, 2};
  EXPECT_EQ(solution.numberOfPairs(nums), (std::vector<int>{3, 1}));
}

TEST_P(MaximumNumberOfPairsInArrayTest, Example2) {
  std::vector<int> nums{1, 1};
  EXPECT_EQ(solution.numberOfPairs(nums), (std::vector<int>{1, 0}));
}

TEST_P(MaximumNumberOfPairsInArrayTest, Example3) {
  std::vector<int> nums{0};
  EXPECT_EQ(solution.numberOfPairs(nums), (std::vector<int>{0, 1}));
}

TEST_P(MaximumNumberOfPairsInArrayTest, SelfAuthoredAllDistinct) {
  std::vector<int> nums{5, 7, 9};
  EXPECT_EQ(solution.numberOfPairs(nums), (std::vector<int>{0, 3}));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfPairsInArrayTestSuite,
    MaximumNumberOfPairsInArrayTest,
    ::testing::ValuesIn(
        MaximumNumberOfPairsInArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_2341
