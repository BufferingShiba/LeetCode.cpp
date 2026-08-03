#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-count-of-positive-integer-and-negative-integer.h"

namespace leetcode::problem_2529 {

class MaximumCountOfPositiveIntegerAndNegativeIntegerTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumCountOfPositiveIntegerAndNegativeIntegerSolution solution;
};

TEST_P(MaximumCountOfPositiveIntegerAndNegativeIntegerTest, Example1) {
  std::vector<int> nums{-2, -1, -1, 1, 2, 3};
  EXPECT_EQ(3, solution.maximumCount(nums));
}

TEST_P(MaximumCountOfPositiveIntegerAndNegativeIntegerTest, Example2) {
  std::vector<int> nums{-3, -2, -1, 0, 0, 1, 2};
  EXPECT_EQ(3, solution.maximumCount(nums));
}

TEST_P(MaximumCountOfPositiveIntegerAndNegativeIntegerTest, Example3) {
  std::vector<int> nums{5, 20, 66, 1314};
  EXPECT_EQ(4, solution.maximumCount(nums));
}

TEST_P(MaximumCountOfPositiveIntegerAndNegativeIntegerTest, SelfAuthoredAllNegative) {
  std::vector<int> nums{-5, -4, -3};
  EXPECT_EQ(3, solution.maximumCount(nums));
}

TEST_P(MaximumCountOfPositiveIntegerAndNegativeIntegerTest, SelfAuthoredSingleZero) {
  std::vector<int> nums{0};
  EXPECT_EQ(0, solution.maximumCount(nums));
}

TEST_P(MaximumCountOfPositiveIntegerAndNegativeIntegerTest, SelfAuthoredMixWithZeros) {
  std::vector<int> nums{-1, 0, 0, 0, 2, 3};
  EXPECT_EQ(2, solution.maximumCount(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumCountOfPositiveIntegerAndNegativeIntegerTestInstance,
    MaximumCountOfPositiveIntegerAndNegativeIntegerTest,
    ::testing::ValuesIn(
        MaximumCountOfPositiveIntegerAndNegativeIntegerSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_2529
