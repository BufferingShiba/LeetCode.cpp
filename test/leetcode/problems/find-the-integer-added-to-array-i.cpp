#include <gtest/gtest.h>

#include "leetcode/problems/find-the-integer-added-to-array-i.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3131 {

class FindTheIntegerAddedToArrayITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheIntegerAddedToArrayISolution solution;
};

TEST_P(FindTheIntegerAddedToArrayITest, Example1) {
  std::vector<int> nums1{2, 6, 4};
  std::vector<int> nums2{9, 7, 5};
  EXPECT_EQ(3, solution.addedInteger(nums1, nums2));
}

TEST_P(FindTheIntegerAddedToArrayITest, Example2) {
  std::vector<int> nums1{10};
  std::vector<int> nums2{5};
  EXPECT_EQ(-5, solution.addedInteger(nums1, nums2));
}

TEST_P(FindTheIntegerAddedToArrayITest, Example3) {
  std::vector<int> nums1{1, 1, 1, 1};
  std::vector<int> nums2{1, 1, 1, 1};
  EXPECT_EQ(0, solution.addedInteger(nums1, nums2));
}

TEST_P(FindTheIntegerAddedToArrayITest, SelfAuthoredAllEqual) {
  std::vector<int> nums1{7, 7, 7};
  std::vector<int> nums2{7, 7, 7};
  EXPECT_EQ(0, solution.addedInteger(nums1, nums2));
}

TEST_P(FindTheIntegerAddedToArrayITest, SelfAuthoredShift) {
  std::vector<int> nums1{3, 5, 1};
  std::vector<int> nums2{8, 10, 6};
  EXPECT_EQ(5, solution.addedInteger(nums1, nums2));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheIntegerAddedToArrayITestSuite, FindTheIntegerAddedToArrayITest,
    ::testing::ValuesIn(FindTheIntegerAddedToArrayISolution().getStrategyNames()));

}  // namespace problem_3131
}  // namespace leetcode
