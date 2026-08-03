#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-number-of-jumps-to-reach-the-last-index.h"

namespace leetcode {
namespace problem_2770 {

class MaximumNumberOfJumpsToReachTheLastIndexTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumNumberOfJumpsToReachTheLastIndexSolution solution_;
};

TEST_P(MaximumNumberOfJumpsToReachTheLastIndexTest, Example1) {
  std::vector<int> nums = {1, 3, 6, 4, 1, 2};
  int target = 2;
  EXPECT_EQ(3, solution_.maximumJumps(nums, target));
}

TEST_P(MaximumNumberOfJumpsToReachTheLastIndexTest, Example2) {
  std::vector<int> nums = {1, 3, 6, 4, 1, 2};
  int target = 3;
  EXPECT_EQ(5, solution_.maximumJumps(nums, target));
}

TEST_P(MaximumNumberOfJumpsToReachTheLastIndexTest, Example3) {
  std::vector<int> nums = {1, 3, 6, 4, 1, 2};
  int target = 0;
  EXPECT_EQ(-1, solution_.maximumJumps(nums, target));
}

TEST_P(MaximumNumberOfJumpsToReachTheLastIndexTest, SelfAuthoredDirectJump) {
  std::vector<int> nums = {0, 2};
  int target = 3;
  EXPECT_EQ(1, solution_.maximumJumps(nums, target));
}

TEST_P(MaximumNumberOfJumpsToReachTheLastIndexTest, SelfAuthoredUnreachableLast) {
  std::vector<int> nums = {0, 100};
  int target = 5;
  EXPECT_EQ(-1, solution_.maximumJumps(nums, target));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfJumpsToReachTheLastIndexTestSuite,
    MaximumNumberOfJumpsToReachTheLastIndexTest,
    ::testing::ValuesIn(
        MaximumNumberOfJumpsToReachTheLastIndexSolution()
            .getStrategyNames()));

}  // namespace problem_2770
}  // namespace leetcode
