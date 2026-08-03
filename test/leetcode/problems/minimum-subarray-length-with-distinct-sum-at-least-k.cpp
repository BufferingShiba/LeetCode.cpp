#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-subarray-length-with-distinct-sum-at-least-k.h"

namespace leetcode::problem_3795 {
namespace {

using TestParams = std::string;

class MinimumSubarrayLengthWithDistinctSumAtLeastKTest
    : public testing::TestWithParam<TestParams> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MinimumSubarrayLengthWithDistinctSumAtLeastKSolution solution_;
};

TEST_P(MinimumSubarrayLengthWithDistinctSumAtLeastKTest, Example1) {
  std::vector<int> nums = {2, 2, 3, 1};
  int k = 4;
  EXPECT_EQ(solution_.minLength(nums, k), 2);
}

TEST_P(MinimumSubarrayLengthWithDistinctSumAtLeastKTest, Example2) {
  std::vector<int> nums = {3, 2, 3, 4};
  int k = 5;
  EXPECT_EQ(solution_.minLength(nums, k), 2);
}

TEST_P(MinimumSubarrayLengthWithDistinctSumAtLeastKTest, Example3) {
  std::vector<int> nums = {5, 5, 4};
  int k = 5;
  EXPECT_EQ(solution_.minLength(nums, k), 1);
}

TEST_P(MinimumSubarrayLengthWithDistinctSumAtLeastKTest, SelfAuthoredNoSolution) {
  std::vector<int> nums = {1, 1, 1};
  int k = 10;
  EXPECT_EQ(solution_.minLength(nums, k), -1);
}

TEST_P(MinimumSubarrayLengthWithDistinctSumAtLeastKTest, SelfAuthoredSingleElementEnough) {
  std::vector<int> nums = {10, 1, 2};
  int k = 9;
  EXPECT_EQ(solution_.minLength(nums, k), 1);
}

TEST_P(MinimumSubarrayLengthWithDistinctSumAtLeastKTest, SelfAuthoredAllDistinct) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  int k = 9;
  // 不同值子数组 [2,3,4] 和=9，长度=3；或 [4,5] 和=9 长度=2
  EXPECT_EQ(solution_.minLength(nums, k), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumSubarrayLengthWithDistinctSumAtLeastKTest,
    testing::ValuesIn(
        MinimumSubarrayLengthWithDistinctSumAtLeastKSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_3795
