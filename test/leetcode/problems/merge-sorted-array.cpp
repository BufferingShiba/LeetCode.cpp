#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/merge-sorted-array.h"

namespace leetcode::problem_88 {

using leetcode::problem_88::MergeSortedArraySolution;

class MergeSortedArrayTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MergeSortedArraySolution solution;
};

TEST_P(MergeSortedArrayTest, Example1) {
  std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  std::vector<int> nums2 = {2, 5, 6};
  solution.merge(nums1, 3, nums2, 3);
  EXPECT_EQ(nums1, std::vector<int>({1, 2, 2, 3, 5, 6}));
}

TEST_P(MergeSortedArrayTest, Example2) {
  std::vector<int> nums1 = {1};
  std::vector<int> nums2 = {};
  solution.merge(nums1, 1, nums2, 0);
  EXPECT_EQ(nums1, std::vector<int>({1}));
}

TEST_P(MergeSortedArrayTest, Example3) {
  std::vector<int> nums1 = {0};
  std::vector<int> nums2 = {1};
  solution.merge(nums1, 0, nums2, 1);
  EXPECT_EQ(nums1, std::vector<int>({1}));
}

TEST_P(MergeSortedArrayTest, SelfAuthoredEmptyBoth) {
  std::vector<int> nums1 = {0};
  std::vector<int> nums2 = {};
  solution.merge(nums1, 0, nums2, 0);
  EXPECT_EQ(nums1, std::vector<int>({0}));
}

TEST_P(MergeSortedArrayTest, SelfAuthoredInterleaved) {
  std::vector<int> nums1 = {1, 4, 7, 0, 0, 0};
  std::vector<int> nums2 = {2, 3, 9};
  solution.merge(nums1, 3, nums2, 3);
  EXPECT_EQ(nums1, std::vector<int>({1, 2, 3, 4, 7, 9}));
}

INSTANTIATE_TEST_SUITE_P(
    MergeSortedArrayTestSuite, MergeSortedArrayTest,
    ::testing::ValuesIn(MergeSortedArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_88
