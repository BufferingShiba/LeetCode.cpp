#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/max-sum-of-rectangle-no-larger-than-k.h"

namespace leetcode {
namespace problem_363 {
namespace {

class MaxSumOfRectangleNoLargerThanKTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaxSumOfRectangleNoLargerThanKSolution solution_;
};

TEST_P(MaxSumOfRectangleNoLargerThanKTest, Example1) {
  std::vector<std::vector<int>> matrix = {{1, 0, 1}, {0, -2, 3}};
  int k = 2;
  EXPECT_EQ(solution_.maxSumSubmatrix(matrix, k), 2);
}

TEST_P(MaxSumOfRectangleNoLargerThanKTest, Example2) {
  std::vector<std::vector<int>> matrix = {{2, 2, -1}};
  int k = 3;
  EXPECT_EQ(solution_.maxSumSubmatrix(matrix, k), 3);
}

TEST_P(MaxSumOfRectangleNoLargerThanKTest, SelfAuthoredSingleElementFeasible) {
  std::vector<std::vector<int>> matrix = {{5}};
  int k = 5;
  EXPECT_EQ(solution_.maxSumSubmatrix(matrix, k), 5);
}

TEST_P(MaxSumOfRectangleNoLargerThanKTest, SelfAuthoredAllNegative) {
  std::vector<std::vector<int>> matrix = {{-1, -2}, {-3, -4}};
  int k = -1;
  EXPECT_EQ(solution_.maxSumSubmatrix(matrix, k), -1);
}

TEST_P(MaxSumOfRectangleNoLargerThanKTest, SelfAuthoredKSmallerThanAll) {
  std::vector<std::vector<int>> matrix = {{-1, -2}, {-3, -4}};
  int k = -10;
  // Largest single element is -1, but must be <= -10; the most feasible
  // single-element rectangle sums are -2,-3,-4(-3?), -4? all <= -10? No.
  // Only -10 is too restrictive; all single elements exceed -10, and any
  // rectangle sum is >= -10 means... take -1+(-2)+(-3)+(-4) = -10.
  EXPECT_EQ(solution_.maxSumSubmatrix(matrix, k), -10);
}

INSTANTIATE_TEST_SUITE_P(
    MaxSumOfRectangleNoLargerThanKTestInstance,
    MaxSumOfRectangleNoLargerThanKTest,
    ::testing::ValuesIn(
        MaxSumOfRectangleNoLargerThanKSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_363
}  // namespace leetcode
