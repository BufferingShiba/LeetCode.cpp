#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/partition-array-into-two-arrays-to-minimize-sum-difference.h"

namespace leetcode {
namespace problem_2035 {
namespace {

class PartitionArrayIntoTwoArraysToMinimizeSumDifferenceTest
    : public testing::TestWithParam<std::string> {
 protected:
  PartitionArrayIntoTwoArraysToMinimizeSumDifferenceSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(PartitionArrayIntoTwoArraysToMinimizeSumDifferenceTest, Example1) {
  std::vector<int> nums = {3, 9, 7, 3};
  EXPECT_EQ(solution.minimumDifference(nums), 2);
}

TEST_P(PartitionArrayIntoTwoArraysToMinimizeSumDifferenceTest, Example2) {
  std::vector<int> nums = {-36, 36};
  EXPECT_EQ(solution.minimumDifference(nums), 72);
}

TEST_P(PartitionArrayIntoTwoArraysToMinimizeSumDifferenceTest, Example3) {
  std::vector<int> nums = {2, -1, 0, 4, -2, -9};
  EXPECT_EQ(solution.minimumDifference(nums), 0);
}

TEST_P(PartitionArrayIntoTwoArraysToMinimizeSumDifferenceTest, SelfAuthoredSinglePair) {
  // n = 1, two elements each going to a separate array.
  std::vector<int> nums = {5, 5};
  EXPECT_EQ(solution.minimumDifference(nums), 0);
  std::vector<int> nums2 = {-7, 3};
  EXPECT_EQ(solution.minimumDifference(nums2), 10);
}

TEST_P(PartitionArrayIntoTwoArraysToMinimizeSumDifferenceTest, SelfAuthoredAllSame) {
  std::vector<int> nums = {10000000, 10000000, 10000000, 10000000};
  EXPECT_EQ(solution.minimumDifference(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    PartitionArrayIntoTwoArraysToMinimizeSumDifferenceTestSuite,
    PartitionArrayIntoTwoArraysToMinimizeSumDifferenceTest,
    testing::ValuesIn(PartitionArrayIntoTwoArraysToMinimizeSumDifferenceSolution()
                          .getStrategyNames()));

}  // namespace
}  // namespace problem_2035
}  // namespace leetcode
