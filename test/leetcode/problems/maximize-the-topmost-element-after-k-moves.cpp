#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximize-the-topmost-element-after-k-moves.h"

namespace leetcode {
namespace problem_2202 {
namespace {

using MaximizeTheTopmostElementAfterKMovesTest = ::testing::TestWithParam<std::string>;

}  // namespace

TEST_P(MaximizeTheTopmostElementAfterKMovesTest, Examples) {
  MaximizeTheTopmostElementAfterKMovesSolution solution;
  solution.setStrategy(GetParam());

  {
    std::vector<int> nums = {5, 2, 2, 4, 0, 6};
    EXPECT_EQ(solution.maximumTop(nums, 4), 5);
  }
  {
    std::vector<int> nums = {2};
    EXPECT_EQ(solution.maximumTop(nums, 1), -1);
  }
}

TEST_P(MaximizeTheTopmostElementAfterKMovesTest, SelfAuthored) {
  MaximizeTheTopmostElementAfterKMovesSolution solution;
  solution.setStrategy(GetParam());

  {
    // k = 0 -> top stays nums[0].
    std::vector<int> nums = {7, 3, 9};
    EXPECT_EQ(solution.maximumTop(nums, 0), 7);
  }
  {
    // n == 1, even k -> single element remains.
    std::vector<int> nums = {4};
    EXPECT_EQ(solution.maximumTop(nums, 2), 4);
    EXPECT_EQ(solution.maximumTop(nums, 5), -1);
  }
  {
    // n == 2, k == 1 -> pop top, nums[1] on top.
    std::vector<int> nums = {1, 8};
    EXPECT_EQ(solution.maximumTop(nums, 1), 8);
  }
  {
    // k >= n -> can place the global maximum on top.
    std::vector<int> nums = {3, 9, 1};
    EXPECT_EQ(solution.maximumTop(nums, 3), 9);
    EXPECT_EQ(solution.maximumTop(nums, 7), 9);
  }
}

INSTANTIATE_TEST_SUITE_P(
    MaximizeTheTopmostElementAfterKMovesTestParameters,
    MaximizeTheTopmostElementAfterKMovesTest,
    ::testing::ValuesIn(
        MaximizeTheTopmostElementAfterKMovesSolution().getStrategyNames()));

}  // namespace problem_2202
}  // namespace leetcode
