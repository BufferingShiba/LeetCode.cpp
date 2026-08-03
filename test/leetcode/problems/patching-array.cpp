#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/patching-array.h"

namespace leetcode::problem_330 {

class PatchingArrayTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PatchingArraySolution solution;
};

TEST_P(PatchingArrayTest, Example1) {
  std::vector<int> nums = {1, 3};
  int n = 6;
  EXPECT_EQ(solution.minPatches(nums, n), 1);
}

TEST_P(PatchingArrayTest, Example2) {
  std::vector<int> nums = {1, 5, 10};
  int n = 20;
  EXPECT_EQ(solution.minPatches(nums, n), 2);
}

TEST_P(PatchingArrayTest, Example3) {
  std::vector<int> nums = {1, 2, 2};
  int n = 5;
  EXPECT_EQ(solution.minPatches(nums, n), 0);
}

TEST_P(PatchingArrayTest, SelfAuthored_AlreadyCovered) {
  std::vector<int> nums = {1, 2, 4, 8};
  int n = 15;
  // [1,2,4,8] covers [1,15] already
  EXPECT_EQ(solution.minPatches(nums, n), 0);
}

TEST_P(PatchingArrayTest, SelfAuthored_NeedOneAtEnd) {
  std::vector<int> nums = {1, 2, 4, 8};
  int n = 16;
  // covers [1,15], need patch 16 to reach n=16
  EXPECT_EQ(solution.minPatches(nums, n), 1);
}

TEST_P(PatchingArrayTest, SelfAuthored_EmptyStart) {
  std::vector<int> nums = {2, 4};
  int n = 7;
  // no 1, need patch 1 first, then 1+2=3 cover [1,3], need patch 4? Let's trace:
  // miss=1, nums[0]=2>1 → patch 1, miss=2, patches=1
  // miss=2, nums[0]=2<=2 → miss=4, i=1
  // miss=4, nums[1]=4<=4 → miss=8, i=2
  // miss=8>7 → stop, patches=1
  EXPECT_EQ(solution.minPatches(nums, n), 1);
}

TEST_P(PatchingArrayTest, SelfAuthored_LargeN) {
  std::vector<int> nums = {1, 2, 31, 33};
  int n = 2147483647;
  // just ensure no overflow
  int result = solution.minPatches(nums, n);
  EXPECT_GE(result, 0);
}

INSTANTIATE_TEST_SUITE_P(Strategies, PatchingArrayTest,
                         testing::ValuesIn(PatchingArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_330
