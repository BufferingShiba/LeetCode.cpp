#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/intersection-of-two-arrays.h"

namespace leetcode {
namespace problem_349 {

class IntersectionOfTwoArraysTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  IntersectionOfTwoArraysSolution solution;
};

TEST_P(IntersectionOfTwoArraysTest, Example1) {
  std::vector<int> nums1{1, 2, 2, 1};
  std::vector<int> nums2{2, 2};
  std::vector<int> expect{2};
  std::vector<int> result = solution.intersection(nums1, nums2);
  std::sort(result.begin(), result.end());
  std::sort(expect.begin(), expect.end());
  EXPECT_EQ(result, expect);
}

TEST_P(IntersectionOfTwoArraysTest, Example2) {
  std::vector<int> nums1{4, 9, 5};
  std::vector<int> nums2{9, 4, 9, 8, 4};
  std::vector<int> expect{4, 9};
  std::vector<int> result = solution.intersection(nums1, nums2);
  std::sort(result.begin(), result.end());
  std::sort(expect.begin(), expect.end());
  EXPECT_EQ(result, expect);
}

TEST_P(IntersectionOfTwoArraysTest, SelfAuthoredNoCommonElements) {
  std::vector<int> nums1{1, 2, 3};
  std::vector<int> nums2{4, 5, 6};
  std::vector<int> expect{};
  std::vector<int> result = solution.intersection(nums1, nums2);
  std::sort(result.begin(), result.end());
  EXPECT_EQ(result, expect);
}

TEST_P(IntersectionOfTwoArraysTest, SelfAuthoredSingleElementCommon) {
  std::vector<int> nums1{1, 1, 1};
  std::vector<int> nums2{1, 1, 1, 1};
  std::vector<int> expect{1};
  std::vector<int> result = solution.intersection(nums1, nums2);
  std::sort(result.begin(), result.end());
  EXPECT_EQ(result, expect);
}

INSTANTIATE_TEST_SUITE_P(
    IntersectionOfTwoArraysTestSuite, IntersectionOfTwoArraysTest,
    ::testing::ValuesIn(IntersectionOfTwoArraysSolution().getStrategyNames()));

}  // namespace problem_349
}  // namespace leetcode
