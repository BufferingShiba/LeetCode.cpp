#include <gtest/gtest.h>

#include "leetcode/problems/sliding-window-maximum.h"

namespace leetcode {
namespace problem_239 {

class SlidingWindowMaximumTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SlidingWindowMaximumSolution solution_;
};

TEST_P(SlidingWindowMaximumTest, Example1) {
  std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  std::vector<int> expected = {3, 3, 5, 5, 6, 7};
  EXPECT_EQ(solution_.maxSlidingWindow(nums, k), expected);
}

TEST_P(SlidingWindowMaximumTest, Example2) {
  std::vector<int> nums = {1};
  int k = 1;
  std::vector<int> expected = {1};
  EXPECT_EQ(solution_.maxSlidingWindow(nums, k), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    SlidingWindowMaximumTest,
    testing::ValuesIn(SlidingWindowMaximumSolution().getStrategyNames()));

}  // namespace problem_239
}  // namespace leetcode
