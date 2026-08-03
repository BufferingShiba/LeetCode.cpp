#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-number-of-distinct-elements-after-operations.h"

namespace leetcode::problem_3397 {

namespace {

int runTestCase(std::vector<int> nums, int k) {
  std::vector<std::string> strategies =
      MaximumNumberOfDistinctElementsAfterOperationsSolution().getStrategyNames();
  MaximumNumberOfDistinctElementsAfterOperationsSolution solution;
  solution.setStrategy(strategies.front());
  return solution.maxDistinctElements(nums, k);
}

}  // namespace

class MaximumNumberOfDistinctElementsAfterOperationsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumNumberOfDistinctElementsAfterOperationsSolution solution;
};

TEST_P(MaximumNumberOfDistinctElementsAfterOperationsTest, Example1) {
  std::vector<int> nums{1, 2, 2, 3, 3, 4};
  EXPECT_EQ(6, solution.maxDistinctElements(nums, 2));
}

TEST_P(MaximumNumberOfDistinctElementsAfterOperationsTest, Example2) {
  std::vector<int> nums{4, 4, 4, 4};
  EXPECT_EQ(3, solution.maxDistinctElements(nums, 1));
}

TEST_P(MaximumNumberOfDistinctElementsAfterOperationsTest, SingleElement) {
  std::vector<int> nums{5};
  EXPECT_EQ(1, solution.maxDistinctElements(nums, 0));
}

TEST_P(MaximumNumberOfDistinctElementsAfterOperationsTest, ZeroK) {
  std::vector<int> nums{1, 1, 2, 2, 3};
  EXPECT_EQ(3, solution.maxDistinctElements(nums, 0));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfDistinctElementsAfterOperationsTestSuite,
    MaximumNumberOfDistinctElementsAfterOperationsTest,
    ::testing::ValuesIn(MaximumNumberOfDistinctElementsAfterOperationsSolution()
                            .getStrategyNames()));

}  // namespace leetcode::problem_3397
