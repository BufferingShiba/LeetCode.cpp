#include <gtest/gtest.h>

#include "leetcode/problems/minimum-operations-to-make-array-equal-ii.h"

#include <string>
#include <vector>

namespace leetcode::problem_2541 {

class MinimumOperationsToMakeArrayEqualIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MinimumOperationsToMakeArrayEqualIiSolution solution_;
};

TEST_P(MinimumOperationsToMakeArrayEqualIiTest, Example1) {
  std::vector<int> nums1{4, 3, 1, 4};
  std::vector<int> nums2{1, 3, 7, 1};
  EXPECT_EQ(2, solution_.minOperations(nums1, nums2, 3));
}

TEST_P(MinimumOperationsToMakeArrayEqualIiTest, Example2) {
  std::vector<int> nums1{3, 8, 5, 2};
  std::vector<int> nums2{2, 4, 1, 6};
  EXPECT_EQ(-1, solution_.minOperations(nums1, nums2, 1));
}

TEST_P(MinimumOperationsToMakeArrayEqualIiTest, SelfAuthoredZeroKAlreadyEqual) {
  std::vector<int> nums1{1, 2, 3};
  std::vector<int> nums2{1, 2, 3};
  EXPECT_EQ(0, solution_.minOperations(nums1, nums2, 0));
}

TEST_P(MinimumOperationsToMakeArrayEqualIiTest, SelfAuthoredZeroKNotEqual) {
  std::vector<int> nums1{1, 2, 3};
  std::vector<int> nums2{1, 2, 4};
  EXPECT_EQ(-1, solution_.minOperations(nums1, nums2, 0));
}

TEST_P(MinimumOperationsToMakeArrayEqualIiTest, SelfAuthoredSinglePair) {
  std::vector<int> nums1{10, 0};
  std::vector<int> nums2{0, 10};
  EXPECT_EQ(5, solution_.minOperations(nums1, nums2, 2));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumOperationsToMakeArrayEqualIiTestSuite,
    MinimumOperationsToMakeArrayEqualIiTest,
    ::testing::ValuesIn(
        MinimumOperationsToMakeArrayEqualIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_2541
