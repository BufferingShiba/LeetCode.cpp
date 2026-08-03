#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/partition-to-k-equal-sum-subsets.h"

namespace leetcode {
namespace problem_698 {
namespace {

class PartitionToKEqualSumSubsetsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PartitionToKEqualSumSubsetsSolution solution;
};

TEST_P(PartitionToKEqualSumSubsetsTest, Example1) {
  std::vector<int> nums{4, 3, 2, 3, 5, 2, 1};
  int k = 4;
  EXPECT_TRUE(solution.canPartitionKSubsets(nums, k));
}

TEST_P(PartitionToKEqualSumSubsetsTest, Example2) {
  std::vector<int> nums{1, 2, 3, 4};
  int k = 3;
  EXPECT_FALSE(solution.canPartitionKSubsets(nums, k));
}

TEST_P(PartitionToKEqualSumSubsetsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{1};
  int k = 1;
  EXPECT_TRUE(solution.canPartitionKSubsets(nums, k));
}

TEST_P(PartitionToKEqualSumSubsetsTest, SelfAuthoredAllSameValues) {
  std::vector<int> nums{2, 2, 2, 2};
  int k = 2;
  EXPECT_TRUE(solution.canPartitionKSubsets(nums, k));
}

TEST_P(PartitionToKEqualSumSubsetsTest, SelfAuthoredImpossibleSingleValueLargerThanTarget) {
  std::vector<int> nums{1, 2, 2};
  int k = 2;
  EXPECT_FALSE(solution.canPartitionKSubsets(nums, k));
}

INSTANTIATE_TEST_SUITE_P(
    PartitionToKEqualSumSubsetsTestInstance,
    PartitionToKEqualSumSubsetsTest,
    ::testing::ValuesIn(PartitionToKEqualSumSubsetsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_698
}  // namespace leetcode
