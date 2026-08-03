#include <gtest/gtest.h>

#include "leetcode/problems/find-the-minimum-cost-array-permutation.h"

namespace leetcode::problem_3149 {

class FindTheMinimumCostArrayPermutationTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  FindTheMinimumCostArrayPermutationSolution solution;
};

TEST_P(FindTheMinimumCostArrayPermutationTest, Example1) {
  std::vector<int> nums = {1, 0, 2};
  std::vector<int> expected = {0, 1, 2};
  EXPECT_EQ(solution.findPermutation(nums), expected);
}

TEST_P(FindTheMinimumCostArrayPermutationTest, Example2) {
  std::vector<int> nums = {0, 2, 1};
  std::vector<int> expected = {0, 2, 1};
  EXPECT_EQ(solution.findPermutation(nums), expected);
}

TEST_P(FindTheMinimumCostArrayPermutationTest, MinSize) {
  std::vector<int> nums = {1, 0};
  auto result = solution.findPermutation(nums);
  EXPECT_EQ(result.size(), 2);
  EXPECT_EQ(result[0], 0);
}

TEST_P(FindTheMinimumCostArrayPermutationTest, SelfAuthoredSmall) {
  std::vector<int> nums = {0, 1, 2};
  std::vector<int> expected = {0, 1, 2};
  EXPECT_EQ(solution.findPermutation(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindTheMinimumCostArrayPermutationTest,
    testing::ValuesIn(
        FindTheMinimumCostArrayPermutationSolution().getStrategyNames()));

}  // namespace leetcode::problem_3149
