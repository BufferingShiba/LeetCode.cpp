#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/sum-of-variable-length-subarrays.h"

namespace leetcode {
namespace problem_3427 {

class SumOfVariableLengthSubarraysTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SumOfVariableLengthSubarraysSolution solution;
};

TEST_P(SumOfVariableLengthSubarraysTest, Example1) {
  std::vector<int> nums = {2, 3, 1};
  EXPECT_EQ(solution.subarraySum(nums), 11);
}

TEST_P(SumOfVariableLengthSubarraysTest, Example2) {
  std::vector<int> nums = {3, 1, 1, 2};
  EXPECT_EQ(solution.subarraySum(nums), 13);
}

TEST_P(SumOfVariableLengthSubarraysTest, SelfAuthored) {
  // Single element: subarray is just [nums[0]]
  std::vector<int> nums1 = {5};
  EXPECT_EQ(solution.subarraySum(nums1), 5);

  // All nums[i] large enough to force start=0
  // i=0: [10], i=1: [10,10] => 10 + 20 = 30
  std::vector<int> nums2 = {10, 10};
  EXPECT_EQ(solution.subarraySum(nums2), 30);

  // Mixed case
  // nums = [1,2,3]:
  // i=0: start=max(0,0-1)=0, [1] => 1
  // i=1: start=max(0,1-2)=0, [1,2] => 3
  // i=2: start=max(0,2-3)=0, [1,2,3] => 6
  // total = 10
  std::vector<int> nums3 = {1, 2, 3};
  EXPECT_EQ(solution.subarraySum(nums3), 10);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    SumOfVariableLengthSubarraysTest,
    testing::ValuesIn(
        SumOfVariableLengthSubarraysSolution().getStrategyNames()));

}  // namespace problem_3427
}  // namespace leetcode
