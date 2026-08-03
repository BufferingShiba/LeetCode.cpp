#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-operations-to-make-the-array-increasing.h"

namespace leetcode::problem_1827 {

class MinimumOperationsToMakeTheArrayIncreasingTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumOperationsToMakeTheArrayIncreasingSolution solution;
};

TEST_P(MinimumOperationsToMakeTheArrayIncreasingTest, Example1) {
  std::vector<int> nums = {1, 1, 1};
  EXPECT_EQ(3, solution.minOperations(nums));
}

TEST_P(MinimumOperationsToMakeTheArrayIncreasingTest, Example2) {
  std::vector<int> nums = {1, 5, 2, 4, 1};
  EXPECT_EQ(14, solution.minOperations(nums));
}

TEST_P(MinimumOperationsToMakeTheArrayIncreasingTest, Example3) {
  std::vector<int> nums = {8};
  EXPECT_EQ(0, solution.minOperations(nums));
}

TEST_P(MinimumOperationsToMakeTheArrayIncreasingTest, SingleElement) {
  std::vector<int> nums = {5};
  EXPECT_EQ(0, solution.minOperations(nums));
}

TEST_P(MinimumOperationsToMakeTheArrayIncreasingTest, AlreadyIncreasing) {
  std::vector<int> nums = {1, 2, 3, 5};
  EXPECT_EQ(0, solution.minOperations(nums));
}

TEST_P(MinimumOperationsToMakeTheArrayIncreasingTest, ReverseSorted) {
  std::vector<int> nums = {4, 3, 2, 1};
  // 3->5: +2, 2->6: +4, 1->7: +6; total 12
  EXPECT_EQ(12, solution.minOperations(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumOperationsToMakeTheArrayIncreasingTestSuite,
    MinimumOperationsToMakeTheArrayIncreasingTest,
    ::testing::ValuesIn(
        MinimumOperationsToMakeTheArrayIncreasingSolution().getStrategyNames()));

}  // namespace leetcode::problem_1827
