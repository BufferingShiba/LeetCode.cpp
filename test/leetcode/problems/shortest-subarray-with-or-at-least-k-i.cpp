#include <gtest/gtest.h>

#include "leetcode/problems/shortest-subarray-with-or-at-least-k-i.h"

using namespace leetcode::problem_3095;

class ShortestSubarrayWithOrAtLeastKITest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  ShortestSubarrayWithOrAtLeastKISolution solution;
};

TEST_P(ShortestSubarrayWithOrAtLeastKITest, Example1) {
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(solution.minimumSubarrayLength(nums, 2), 1);
}

TEST_P(ShortestSubarrayWithOrAtLeastKITest, Example2) {
  std::vector<int> nums = {2, 1, 8};
  EXPECT_EQ(solution.minimumSubarrayLength(nums, 10), 3);
}

TEST_P(ShortestSubarrayWithOrAtLeastKITest, Example3) {
  std::vector<int> nums = {1, 2};
  EXPECT_EQ(solution.minimumSubarrayLength(nums, 0), 1);
}

TEST_P(ShortestSubarrayWithOrAtLeastKITest, SelfAuthored) {
  // Single element equals k
  {
    std::vector<int> nums = {5};
    EXPECT_EQ(solution.minimumSubarrayLength(nums, 5), 1);
  }
  // No subarray meets k (max OR = 1|2|4 = 7 < 8)
  {
    std::vector<int> nums = {1, 2, 4};
    EXPECT_EQ(solution.minimumSubarrayLength(nums, 8), -1);
  }
  // Entire array needed: 1|2|4|8 = 15 >= 15
  {
    std::vector<int> nums = {1, 2, 4, 8};
    EXPECT_EQ(solution.minimumSubarrayLength(nums, 15), 4);
  }
}

INSTANTIATE_TEST_SUITE_P(
    , ShortestSubarrayWithOrAtLeastKITest,
    testing::ValuesIn(
        ShortestSubarrayWithOrAtLeastKISolution().getStrategyNames()));
