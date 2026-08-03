#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/make-sum-divisible-by-p.h"

namespace leetcode::problem_1590 {

class MakeSumDivisibleByPTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MakeSumDivisibleByPSolution solution_;
};

TEST_P(MakeSumDivisibleByPTest, Example1) {
  std::vector<int> nums = {3, 1, 4, 2};
  int p = 6;
  EXPECT_EQ(solution_.minSubarray(nums, p), 1);
}

TEST_P(MakeSumDivisibleByPTest, Example2) {
  std::vector<int> nums = {6, 3, 5, 2};
  int p = 9;
  EXPECT_EQ(solution_.minSubarray(nums, p), 2);
}

TEST_P(MakeSumDivisibleByPTest, Example3) {
  std::vector<int> nums = {1, 2, 3};
  int p = 3;
  EXPECT_EQ(solution_.minSubarray(nums, p), 0);
}

TEST_P(MakeSumDivisibleByPTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  int p = 7;
  // total = 5, target = 5%7 = 5, 无法移除单个元素（会移除整个数组），返回 -1
  EXPECT_EQ(solution_.minSubarray(nums, p), -1);
}

TEST_P(MakeSumDivisibleByPTest, SelfAuthoredWholeArrayForbidden) {
  std::vector<int> nums = {1, 2};
  int p = 3;
  // total = 3, target = 0, already divisible, return 0
  EXPECT_EQ(solution_.minSubarray(nums, p), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MakeSumDivisibleByPTest,
    testing::ValuesIn(MakeSumDivisibleByPSolution().getStrategyNames()));

}  // namespace leetcode::problem_1590
