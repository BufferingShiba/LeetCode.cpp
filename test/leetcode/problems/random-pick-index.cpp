#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/random-pick-index.h"

namespace leetcode::problem_398 {

class RandomPickIndexTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

TEST_P(RandomPickIndexTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 3, 3};
  RandomPickIndex solution(nums);

  // pick(1): only index 0 is valid.
  EXPECT_EQ(solution.pick(1), 0);

  // pick(3): must always return one of indices 2,3,4 with nums[idx]==3.
  for (int i = 0; i < 200; ++i) {
    int idx = solution.pick(3);
    EXPECT_GE(idx, 2);
    EXPECT_LE(idx, 4);
    EXPECT_EQ(nums[idx], 3);
  }
}

TEST_P(RandomPickIndexTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {42};
  RandomPickIndex solution(nums);
  EXPECT_EQ(solution.pick(42), 0);
}

TEST_P(RandomPickIndexTest, SelfAuthoredAllDuplicates) {
  std::vector<int> nums = {7, 7, 7, 7};
  RandomPickIndex solution(nums);
  for (int i = 0; i < 200; ++i) {
    int idx = solution.pick(7);
    EXPECT_GE(idx, 0);
    EXPECT_LE(idx, 3);
    EXPECT_EQ(nums[idx], 7);
  }
}

INSTANTIATE_TEST_SUITE_P(
    RandomPickIndexTests,
    RandomPickIndexTest,
    ::testing::Values(0));

}  // namespace leetcode::problem_398
