#include <gtest/gtest.h>

#include "leetcode/problems/minimum-size-subarray-in-infinite-array.h"

namespace leetcode {
namespace problem_2875 {

class MinimumSizeSubarrayInInfiniteArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumSizeSubarrayInInfiniteArraySolution solution;
};

TEST_P(MinimumSizeSubarrayInInfiniteArrayTest, Example1) {
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(solution.minSizeSubarray(nums, 5), 2);
}

TEST_P(MinimumSizeSubarrayInInfiniteArrayTest, Example2) {
  std::vector<int> nums = {1, 1, 1, 2, 3};
  EXPECT_EQ(solution.minSizeSubarray(nums, 4), 2);
}

TEST_P(MinimumSizeSubarrayInInfiniteArrayTest, Example3) {
  std::vector<int> nums = {2, 4, 6, 8};
  EXPECT_EQ(solution.minSizeSubarray(nums, 3), -1);
}

TEST_P(MinimumSizeSubarrayInInfiniteArrayTest, SelfAuthored) {
  {
    std::vector<int> nums = {1, 2};
    EXPECT_EQ(solution.minSizeSubarray(nums, 6), 4);
  }
  {
    std::vector<int> nums = {3, 1, 2};
    EXPECT_EQ(solution.minSizeSubarray(nums, 5), 2);
  }
  {
    std::vector<int> nums = {5};
    EXPECT_EQ(solution.minSizeSubarray(nums, 5), 1);
  }
  {
    std::vector<int> nums = {2, 3};
    EXPECT_EQ(solution.minSizeSubarray(nums, 8), 3);
  }
  {
    std::vector<int> nums = {2, 2};
    EXPECT_EQ(solution.minSizeSubarray(nums, 3), -1);
  }
}

INSTANTIATE_TEST_SUITE_P(
    , MinimumSizeSubarrayInInfiniteArrayTest,
    ::testing::ValuesIn(
        MinimumSizeSubarrayInInfiniteArraySolution().getStrategyNames()));

}  // namespace problem_2875
}  // namespace leetcode
