#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/find-minimum-in-rotated-sorted-array.h"

namespace leetcode::problem_153 {

class FindMinimumInRotatedSortedArrayTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindMinimumInRotatedSortedArraySolution solution_;
};

TEST_P(FindMinimumInRotatedSortedArrayTest, Example1) {
  std::vector<int> nums = {3, 4, 5, 1, 2};
  EXPECT_EQ(solution_.findMin(nums), 1);
}

TEST_P(FindMinimumInRotatedSortedArrayTest, Example2) {
  std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  EXPECT_EQ(solution_.findMin(nums), 0);
}

TEST_P(FindMinimumInRotatedSortedArrayTest, Example3) {
  std::vector<int> nums = {11, 13, 15, 17};
  EXPECT_EQ(solution_.findMin(nums), 11);
}

TEST_P(FindMinimumInRotatedSortedArrayTest, SelfAuthored) {
  // Single element
  {
    std::vector<int> nums = {5};
    EXPECT_EQ(solution_.findMin(nums), 5);
  }

  // Two elements, rotated
  {
    std::vector<int> nums = {2, 1};
    EXPECT_EQ(solution_.findMin(nums), 1);
  }

  // Two elements, not rotated
  {
    std::vector<int> nums = {1, 2};
    EXPECT_EQ(solution_.findMin(nums), 1);
  }

  // Min at beginning (no effective rotation)
  {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(solution_.findMin(nums), 1);
  }

  // Min at end (rotated n-1 times)
  {
    std::vector<int> nums = {2, 3, 4, 5, 1};
    EXPECT_EQ(solution_.findMin(nums), 1);
  }

  // Negative numbers
  {
    std::vector<int> nums = {-3, -2, -1, -5, -4};
    EXPECT_EQ(solution_.findMin(nums), -5);
  }
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindMinimumInRotatedSortedArrayTest,
    testing::ValuesIn(
        FindMinimumInRotatedSortedArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_153
