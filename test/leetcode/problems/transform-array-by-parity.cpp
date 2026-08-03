#include <gtest/gtest.h>

#include "leetcode/problems/transform-array-by-parity.h"

namespace leetcode::problem_3467 {

class TransformArrayByParityTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  TransformArrayByParitySolution solution;
};

TEST_P(TransformArrayByParityTest, OfficialExamples) {
  std::vector<int> nums;
  std::vector<int> expected;

  if (GetParam() == "Counting") {
    nums = {4, 3, 2, 1};
    expected = {0, 0, 1, 1};
    EXPECT_EQ(solution.transformArray(nums), expected);

    nums = {1, 5, 1, 4, 2};
    expected = {0, 0, 1, 1, 1};
    EXPECT_EQ(solution.transformArray(nums), expected);
  }
}

TEST_P(TransformArrayByParityTest, SelfAuthored) {
  // All evens
  std::vector<int> nums = {2, 4, 6};
  std::vector<int> expected = {0, 0, 0};
  EXPECT_EQ(solution.transformArray(nums), expected);

  // All odds
  nums = {1, 3, 5};
  expected = {1, 1, 1};
  EXPECT_EQ(solution.transformArray(nums), expected);

  // Single element even
  nums = {10};
  expected = {0};
  EXPECT_EQ(solution.transformArray(nums), expected);

  // Single element odd
  nums = {7};
  expected = {1};
  EXPECT_EQ(solution.transformArray(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(Strategies, TransformArrayByParityTest,
                         testing::ValuesIn(
                             TransformArrayByParitySolution().getStrategyNames()));

}  // namespace leetcode::problem_3467
