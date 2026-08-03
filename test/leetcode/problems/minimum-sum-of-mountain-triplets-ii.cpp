#include <gtest/gtest.h>

#include "leetcode/problems/minimum-sum-of-mountain-triplets-ii.h"

namespace leetcode {
namespace problem_2909 {

class MinimumSumOfMountainTripletsIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumSumOfMountainTripletsIiSolution solution_;
};

TEST_P(MinimumSumOfMountainTripletsIiTest, Example1) {
  std::vector<int> nums{8, 6, 1, 5, 3};
  EXPECT_EQ(9, solution_.minimumSum(nums));
}

TEST_P(MinimumSumOfMountainTripletsIiTest, Example2) {
  std::vector<int> nums{5, 4, 8, 7, 10, 2};
  EXPECT_EQ(13, solution_.minimumSum(nums));
}

TEST_P(MinimumSumOfMountainTripletsIiTest, Example3) {
  std::vector<int> nums{6, 5, 4, 3, 4, 5};
  EXPECT_EQ(-1, solution_.minimumSum(nums));
}

TEST_P(MinimumSumOfMountainTripletsIiTest, SelfAuthoredEdgeIncreasing) {
  std::vector<int> nums{1, 2, 3, 4, 5};
  EXPECT_EQ(-1, solution_.minimumSum(nums));
}

TEST_P(MinimumSumOfMountainTripletsIiTest, SelfAuthoredEdgeDecreasing) {
  std::vector<int> nums{5, 4, 3, 2, 1};
  EXPECT_EQ(-1, solution_.minimumSum(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumSumOfMountainTripletsIiTestSuite,
    MinimumSumOfMountainTripletsIiTest,
    ::testing::ValuesIn(
        MinimumSumOfMountainTripletsIiSolution().getStrategyNames()));

}  // namespace problem_2909
}  // namespace leetcode
