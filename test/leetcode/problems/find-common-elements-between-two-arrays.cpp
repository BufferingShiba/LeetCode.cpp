#include <gtest/gtest.h>

#include "leetcode/problems/find-common-elements-between-two-arrays.h"

namespace leetcode {
namespace problem_2956 {
namespace {

class FindCommonElementsBetweenTwoArraysTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindCommonElementsBetweenTwoArraysSolution solution_;
};

TEST_P(FindCommonElementsBetweenTwoArraysTest, Example1) {
  std::vector<int> nums1 = {2, 3, 2};
  std::vector<int> nums2 = {1, 2};
  EXPECT_EQ(solution_.findIntersectionValues(nums1, nums2),
            (std::vector<int>{2, 1}));
}

TEST_P(FindCommonElementsBetweenTwoArraysTest, Example2) {
  std::vector<int> nums1 = {4, 3, 2, 3, 1};
  std::vector<int> nums2 = {2, 2, 5, 2, 3, 6};
  EXPECT_EQ(solution_.findIntersectionValues(nums1, nums2),
            (std::vector<int>{3, 4}));
}

TEST_P(FindCommonElementsBetweenTwoArraysTest, Example3) {
  std::vector<int> nums1 = {3, 4, 2, 3};
  std::vector<int> nums2 = {1, 5};
  EXPECT_EQ(solution_.findIntersectionValues(nums1, nums2),
            (std::vector<int>{0, 0}));
}

TEST_P(FindCommonElementsBetweenTwoArraysTest, SelfAuthored) {
  // Single element, common
  {
    std::vector<int> nums1 = {5};
    std::vector<int> nums2 = {5};
    EXPECT_EQ(solution_.findIntersectionValues(nums1, nums2),
              (std::vector<int>{1, 1}));
  }

  // All elements identical
  {
    std::vector<int> nums1 = {7, 7, 7};
    std::vector<int> nums2 = {7, 7};
    EXPECT_EQ(solution_.findIntersectionValues(nums1, nums2),
              (std::vector<int>{3, 2}));
  }

  // Value at boundary (1 and 100)
  {
    std::vector<int> nums1 = {1, 100};
    std::vector<int> nums2 = {100, 1};
    EXPECT_EQ(solution_.findIntersectionValues(nums1, nums2),
              (std::vector<int>{2, 2}));
  }
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindCommonElementsBetweenTwoArraysTest,
    ::testing::ValuesIn(
        FindCommonElementsBetweenTwoArraysSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2956
}  // namespace leetcode
