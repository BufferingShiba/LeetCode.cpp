#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-unique-subarray-sum-after-deletion.h"

namespace leetcode {
namespace problem_3487 {
namespace {

using MaximumUniqueSubarraySumAfterDeletionTest =
    ::testing::TestWithParam<std::string>;

class SolutionFixture : public MaximumUniqueSubarraySumAfterDeletionTest {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MaximumUniqueSubarraySumAfterDeletionSolution solution_;
};

TEST_P(SolutionFixture, Example1) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  EXPECT_EQ(15, solution_.maxSum(nums));
}

TEST_P(SolutionFixture, Example2) {
  std::vector<int> nums = {1, 1, 0, 1, 1};
  EXPECT_EQ(1, solution_.maxSum(nums));
}

TEST_P(SolutionFixture, Example3) {
  std::vector<int> nums = {1, 2, -1, -2, 1, 0, -1};
  EXPECT_EQ(3, solution_.maxSum(nums));
}

TEST_P(SolutionFixture, SelfAuthoredAllNegative) {
  std::vector<int> nums = {-3, -1, -2};
  EXPECT_EQ(-1, solution_.maxSum(nums));
}

TEST_P(SolutionFixture, SelfAuthoredSingleZero) {
  std::vector<int> nums = {0, 0, 0};
  EXPECT_EQ(0, solution_.maxSum(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumUniqueSubarraySumAfterDeletion,
    SolutionFixture,
    ::testing::ValuesIn(
        MaximumUniqueSubarraySumAfterDeletionSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3487
}  // namespace leetcode
