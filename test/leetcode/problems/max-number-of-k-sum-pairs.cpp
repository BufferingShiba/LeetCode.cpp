#include <gtest/gtest.h>
#include "leetcode/problems/max-number-of-k-sum-pairs.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1679 {
namespace {

class MaxNumberOfKSumPairsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaxNumberOfKSumPairsSolution solution_;
};

TEST_P(MaxNumberOfKSumPairsTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4};
  int k = 5;
  EXPECT_EQ(2, solution_.maxOperations(nums, k));
}

TEST_P(MaxNumberOfKSumPairsTest, Example2) {
  std::vector<int> nums = {3, 1, 3, 4, 3};
  int k = 6;
  EXPECT_EQ(1, solution_.maxOperations(nums, k));
}

TEST_P(MaxNumberOfKSumPairsTest, SelfAuthoredSingleElementNoPair) {
  std::vector<int> nums = {1};
  int k = 2;
  EXPECT_EQ(0, solution_.maxOperations(nums, k));
}

TEST_P(MaxNumberOfKSumPairsTest, SelfAuthoredAllPairsFormed) {
  std::vector<int> nums = {2, 2, 2, 2};
  int k = 4;
  EXPECT_EQ(2, solution_.maxOperations(nums, k));
}

TEST_P(MaxNumberOfKSumPairsTest, SelfAuthoredMultipleCandidatesChooseBest) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  int k = 5;
  EXPECT_EQ(2, solution_.maxOperations(nums, k));
}

INSTANTIATE_TEST_SUITE_P(
    MaxNumberOfKSumPairsTestSuite, MaxNumberOfKSumPairsTest,
    ::testing::ValuesIn(MaxNumberOfKSumPairsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1679
}  // namespace leetcode
