#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-first-and-last-position-of-element-in-sorted-array.h"

namespace leetcode::problem_34 {

class FindFirstAndLastPositionOfElementInSortedArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindFirstAndLastPositionOfElementInSortedArraySolution solution_;
};

TEST_P(FindFirstAndLastPositionOfElementInSortedArrayTest, Example1) {
  std::vector<int> nums{5, 7, 7, 8, 8, 10};
  EXPECT_EQ(solution_.searchRange(nums, 8), (std::vector<int>{3, 4}));
}

TEST_P(FindFirstAndLastPositionOfElementInSortedArrayTest, Example2) {
  std::vector<int> nums{5, 7, 7, 8, 8, 10};
  EXPECT_EQ(solution_.searchRange(nums, 6), (std::vector<int>{-1, -1}));
}

TEST_P(FindFirstAndLastPositionOfElementInSortedArrayTest, Example3Empty) {
  std::vector<int> nums{};
  EXPECT_EQ(solution_.searchRange(nums, 0), (std::vector<int>{-1, -1}));
}

TEST_P(FindFirstAndLastPositionOfElementInSortedArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{1};
  EXPECT_EQ(solution_.searchRange(nums, 1), (std::vector<int>{0, 0}));
  EXPECT_EQ(solution_.searchRange(nums, 2), (std::vector<int>{-1, -1}));
}

TEST_P(FindFirstAndLastPositionOfElementInSortedArrayTest, SelfAuthoredAllSameElement) {
  std::vector<int> nums{7, 7, 7, 7};
  EXPECT_EQ(solution_.searchRange(nums, 7), (std::vector<int>{0, 3}));
}

INSTANTIATE_TEST_SUITE_P(
    FindFirstAndLastPositionOfElementInSortedArrayTests,
    FindFirstAndLastPositionOfElementInSortedArrayTest,
    ::testing::ValuesIn(
        FindFirstAndLastPositionOfElementInSortedArraySolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_34
