#include <gtest/gtest.h>
#include "leetcode/problems/partition-array-such-that-maximum-difference-is-k.h"

namespace leetcode {
namespace problem_2294 {

class PartitionArraySuchThatMaximumDifferenceIsKTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PartitionArraySuchThatMaximumDifferenceIsKSolution solution;
};

TEST_P(PartitionArraySuchThatMaximumDifferenceIsKTest, Example1) {
  std::vector<int> nums = {3, 6, 1, 2, 5};
  int k = 2;
  EXPECT_EQ(solution.partitionArray(nums, k), 2);
}

TEST_P(PartitionArraySuchThatMaximumDifferenceIsKTest, Example2) {
  std::vector<int> nums = {1, 2, 3};
  int k = 1;
  EXPECT_EQ(solution.partitionArray(nums, k), 2);
}

TEST_P(PartitionArraySuchThatMaximumDifferenceIsKTest, Example3) {
  std::vector<int> nums = {2, 2, 4, 5};
  int k = 0;
  EXPECT_EQ(solution.partitionArray(nums, k), 3);
}

TEST_P(PartitionArraySuchThatMaximumDifferenceIsKTest, SingleElement) {
  std::vector<int> nums = {7};
  int k = 3;
  EXPECT_EQ(solution.partitionArray(nums, k), 1);
}

TEST_P(PartitionArraySuchThatMaximumDifferenceIsKTest, AllWithinK) {
  std::vector<int> nums = {1, 2, 3, 4};
  int k = 3;
  EXPECT_EQ(solution.partitionArray(nums, k), 1);
}

TEST_P(PartitionArraySuchThatMaximumDifferenceIsKTest, StrideLargerThanK) {
  std::vector<int> nums = {1, 3, 5, 7};
  int k = 1;
  EXPECT_EQ(solution.partitionArray(nums, k), 4);
}

INSTANTIATE_TEST_SUITE_P(
    PartitionArraySuchThatMaximumDifferenceIsKTestSuite,
    PartitionArraySuchThatMaximumDifferenceIsKTest,
    ::testing::ValuesIn(PartitionArraySuchThatMaximumDifferenceIsKSolution().getStrategyNames()));

}  // namespace problem_2294
}  // namespace leetcode
