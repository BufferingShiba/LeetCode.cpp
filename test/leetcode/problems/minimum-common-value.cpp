#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-common-value.h"

namespace leetcode {
namespace problem_2540 {
namespace {

using leetcode::problem_2540::MinimumCommonValueSolution;

}  // namespace

class MinimumCommonValueTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumCommonValueSolution solution;
};

TEST_P(MinimumCommonValueTest, Example1) {
  std::vector<int> nums1{1, 2, 3};
  std::vector<int> nums2{2, 4};
  EXPECT_EQ(solution.getCommon(nums1, nums2), 2);
}

TEST_P(MinimumCommonValueTest, Example2) {
  std::vector<int> nums1{1, 2, 3, 6};
  std::vector<int> nums2{2, 3, 4, 5};
  EXPECT_EQ(solution.getCommon(nums1, nums2), 2);
}

TEST_P(MinimumCommonValueTest, SelfAuthoredNoCommon) {
  std::vector<int> nums1{1, 2, 3};
  std::vector<int> nums2{4, 5, 6};
  EXPECT_EQ(solution.getCommon(nums1, nums2), -1);
}

TEST_P(MinimumCommonValueTest, SelfAuthoredSingleElementArrays) {
  std::vector<int> nums1{5};
  std::vector<int> nums2{5};
  EXPECT_EQ(solution.getCommon(nums1, nums2), 5);
}

TEST_P(MinimumCommonValueTest, SelfAuthoredAllElementsInSecond) {
  std::vector<int> nums1{7};
  std::vector<int> nums2{1, 3, 7};
  EXPECT_EQ(solution.getCommon(nums1, nums2), 7);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCommonValueTestCases, MinimumCommonValueTest,
    ::testing::ValuesIn(MinimumCommonValueSolution().getStrategyNames()));

}  // namespace problem_2540
}  // namespace leetcode
