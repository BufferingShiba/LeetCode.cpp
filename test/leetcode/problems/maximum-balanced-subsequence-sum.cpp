#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/maximum-balanced-subsequence-sum.h"

namespace leetcode::problem_2926 {
namespace {

class MaximumBalancedSubsequenceSumTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumBalancedSubsequenceSumSolution solution_;
};

TEST_P(MaximumBalancedSubsequenceSumTest, Example1) {
  std::vector<int> nums{3, 3, 5, 6};
  EXPECT_EQ(14, solution_.maxBalancedSubsequenceSum(nums));
}

TEST_P(MaximumBalancedSubsequenceSumTest, Example2) {
  std::vector<int> nums{5, -1, -3, 8};
  EXPECT_EQ(13, solution_.maxBalancedSubsequenceSum(nums));
}

TEST_P(MaximumBalancedSubsequenceSumTest, Example3) {
  std::vector<int> nums{-2, -1};
  EXPECT_EQ(-1, solution_.maxBalancedSubsequenceSum(nums));
}

TEST_P(MaximumBalancedSubsequenceSumTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{7};
  EXPECT_EQ(7, solution_.maxBalancedSubsequenceSum(nums));
}

TEST_P(MaximumBalancedSubsequenceSumTest, SelfAuthoredSingleElementAtBitBoundary) {
  std::vector<int> nums{-7};
  EXPECT_EQ(-7, solution_.maxBalancedSubsequenceSum(nums));
}

TEST_P(MaximumBalancedSubsequenceSumTest, SelfAuthoredAllSameValue) {
  std::vector<int> nums{4, 4, 4, 4};
  // b = [4,3,2,1]; only single elements allowed (non-increasing b blocks chain)
  EXPECT_EQ(4, solution_.maxBalancedSubsequenceSum(nums));
}

TEST_P(MaximumBalancedSubsequenceSumTest, SelfAuthoredIncreasingSequence) {
  std::vector<int> nums{1, 3, 7};
  // b = [1,2,5], all non-decreasing, can take whole array
  EXPECT_EQ(11, solution_.maxBalancedSubsequenceSum(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumBalancedSubsequenceSumTestSuite,
    MaximumBalancedSubsequenceSumTest,
    ::testing::ValuesIn(
        MaximumBalancedSubsequenceSumSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_2926
