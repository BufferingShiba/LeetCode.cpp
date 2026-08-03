#include <gtest/gtest.h>

#include "leetcode/problems/destroy-sequential-targets.h"

namespace leetcode::problem_2453 {

class DestroySequentialTargetsTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DestroySequentialTargetsSolution solution;
};

TEST_P(DestroySequentialTargetsTest, Example1) {
  std::vector<int> nums = {3, 7, 8, 1, 1, 5};
  int space = 2;
  EXPECT_EQ(solution.destroyTargets(nums, space), 1);
}

TEST_P(DestroySequentialTargetsTest, Example2) {
  std::vector<int> nums = {1, 3, 5, 2, 4, 6};
  int space = 2;
  EXPECT_EQ(solution.destroyTargets(nums, space), 1);
}

TEST_P(DestroySequentialTargetsTest, Example3) {
  std::vector<int> nums = {6, 2, 5};
  int space = 100;
  EXPECT_EQ(solution.destroyTargets(nums, space), 2);
}

TEST_P(DestroySequentialTargetsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {42};
  int space = 7;
  EXPECT_EQ(solution.destroyTargets(nums, space), 42);
}

TEST_P(DestroySequentialTargetsTest, SelfAuthoredAllSameRemainder) {
  std::vector<int> nums = {10, 15, 20, 25};
  int space = 5;
  // All nums % 5 == 0, smallest is 10, count = 4
  EXPECT_EQ(solution.destroyTargets(nums, space), 10);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    DestroySequentialTargetsTest,
    testing::ValuesIn(DestroySequentialTargetsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2453
