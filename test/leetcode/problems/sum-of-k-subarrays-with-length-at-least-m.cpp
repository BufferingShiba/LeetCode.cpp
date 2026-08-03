#include <gtest/gtest.h>

#include "leetcode/problems/sum-of-k-subarrays-with-length-at-least-m.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3473 {

class SumOfKSubarraysWithLengthAtLeastMTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SumOfKSubarraysWithLengthAtLeastMSolution solution_;
};

TEST_P(SumOfKSubarraysWithLengthAtLeastMTest, Example1) {
  std::vector<int> nums = {1, 2, -1, 3, 3, 4};
  EXPECT_EQ(13, solution_.maxSum(nums, 2, 2));
}

TEST_P(SumOfKSubarraysWithLengthAtLeastMTest, Example2) {
  std::vector<int> nums = {-10, 3, -1, -2};
  EXPECT_EQ(-10, solution_.maxSum(nums, 4, 1));
}

TEST_P(SumOfKSubarraysWithLengthAtLeastMTest, SelfAuthoredSingleElementK1M1) {
  std::vector<int> nums = {5};
  EXPECT_EQ(5, solution_.maxSum(nums, 1, 1));
}

TEST_P(SumOfKSubarraysWithLengthAtLeastMTest, SelfAuthoredForceLargerThanM) {
  std::vector<int> nums = {1, 2, 3};
  // k=1, m=2: best subarray of length >= 2 is [1,2,3] = 6.
  EXPECT_EQ(6, solution_.maxSum(nums, 1, 2));
}

TEST_P(SumOfKSubarraysWithLengthAtLeastMTest, SelfAuthoredNegativeAllM3) {
  std::vector<int> nums = {-5, -2, -1, -4};
  // k=1, m=3: best length-3 subarray is (-2)+(-1)+(-4) = -7.
  EXPECT_EQ(-7, solution_.maxSum(nums, 1, 3));
}

// Multiple subarrays where an adjacent-couple is required.
TEST_P(SumOfKSubarraysWithLengthAtLeastMTest, SelfAuthoredAdjacentPair) {
  std::vector<int> nums = {8, -1, 6, 7, -100};
  // k=2, m=2: => [8,-1]=7 and [6,7]=13 => 20; also [ -1,6]=5 and [7,...]...
  // best: [8,-1] and [6,7] -> 7 + 13 = 20.
  EXPECT_EQ(20, solution_.maxSum(nums, 2, 2));
}

INSTANTIATE_TEST_SUITE_P(
    SumOfKSubarraysWithLengthAtLeastMTestInstance,
    SumOfKSubarraysWithLengthAtLeastMTest,
    ::testing::ValuesIn(
        SumOfKSubarraysWithLengthAtLeastMSolution().getStrategyNames()));

}  // namespace problem_3473
}  // namespace leetcode
