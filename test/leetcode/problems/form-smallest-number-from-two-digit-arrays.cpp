#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/form-smallest-number-from-two-digit-arrays.h"

namespace leetcode {
namespace problem_2605 {

class FormSmallestNumberFromTwoDigitArraysTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FormSmallestNumberFromTwoDigitArraysSolution solution_;
};

TEST_P(FormSmallestNumberFromTwoDigitArraysTest, Example1) {
  std::vector<int> nums1 = {4, 1, 3};
  std::vector<int> nums2 = {5, 7};
  EXPECT_EQ(15, solution_.minNumber(nums1, nums2));
}

TEST_P(FormSmallestNumberFromTwoDigitArraysTest, Example2) {
  std::vector<int> nums1 = {3, 5, 2, 6};
  std::vector<int> nums2 = {3, 1, 7};
  EXPECT_EQ(3, solution_.minNumber(nums1, nums2));
}

TEST_P(FormSmallestNumberFromTwoDigitArraysTest, SelfAuthoredNoCommon) {
  std::vector<int> nums1 = {2, 8};
  std::vector<int> nums2 = {1, 9};
  // min1=2, min2=1 -> smallest two-digit = 12
  EXPECT_EQ(12, solution_.minNumber(nums1, nums2));
}

TEST_P(FormSmallestNumberFromTwoDigitArraysTest, SelfAuthoredShared) {
  std::vector<int> nums1 = {9, 4};
  std::vector<int> nums2 = {4, 2};
  EXPECT_EQ(4, solution_.minNumber(nums1, nums2));
}

INSTANTIATE_TEST_SUITE_P(
    FormSmallestNumberFromTwoDigitArraysTests,
    FormSmallestNumberFromTwoDigitArraysTest,
    ::testing::ValuesIn(
        FormSmallestNumberFromTwoDigitArraysSolution().getStrategyNames()));

}  // namespace problem_2605
}  // namespace leetcode
