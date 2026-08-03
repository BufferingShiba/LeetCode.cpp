#include <gtest/gtest.h>

#include "leetcode/problems/minimum-prefix-removal-to-make-array-strictly-increasing.h"

namespace leetcode::problem_3818 {

class MinimumPrefixRemovalToMakeArrayStrictlyIncreasingTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  MinimumPrefixRemovalToMakeArrayStrictlyIncreasingSolution solution;
};

TEST_P(MinimumPrefixRemovalToMakeArrayStrictlyIncreasingTest, Example1) {
  std::vector<int> nums = {1, -1, 2, 3, 3, 4, 5};
  EXPECT_EQ(solution.minimumPrefixLength(nums), 4);
}

TEST_P(MinimumPrefixRemovalToMakeArrayStrictlyIncreasingTest, Example2) {
  std::vector<int> nums = {4, 3, -2, -5};
  EXPECT_EQ(solution.minimumPrefixLength(nums), 3);
}

TEST_P(MinimumPrefixRemovalToMakeArrayStrictlyIncreasingTest, Example3) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(solution.minimumPrefixLength(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumPrefixRemovalToMakeArrayStrictlyIncreasingTest,
    testing::ValuesIn(
        MinimumPrefixRemovalToMakeArrayStrictlyIncreasingSolution().getStrategyNames()));

}  // namespace leetcode::problem_3818
