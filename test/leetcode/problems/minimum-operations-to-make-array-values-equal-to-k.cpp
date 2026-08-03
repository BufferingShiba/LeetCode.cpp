#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-operations-to-make-array-values-equal-to-k.h"

namespace leetcode::problem_3375 {

class MinimumOperationsToMakeArrayValuesEqualToKTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumOperationsToMakeArrayValuesEqualToKSolution solution_;
};

TEST_P(MinimumOperationsToMakeArrayValuesEqualToKTest, Example1) {
  std::vector<int> nums{5, 2, 5, 4, 5};
  EXPECT_EQ(solution_.minOperations(nums, 2), 2);
}

TEST_P(MinimumOperationsToMakeArrayValuesEqualToKTest, Example2) {
  std::vector<int> nums{2, 1, 2};
  EXPECT_EQ(solution_.minOperations(nums, 2), -1);
}

TEST_P(MinimumOperationsToMakeArrayValuesEqualToKTest, Example3) {
  std::vector<int> nums{9, 7, 5, 3};
  EXPECT_EQ(solution_.minOperations(nums, 1), 4);
}

TEST_P(MinimumOperationsToMakeArrayValuesEqualToKTest, SelfAuthoredAlreadyEqual) {
  std::vector<int> nums{5, 5, 5};
  EXPECT_EQ(solution_.minOperations(nums, 5), 0);
}

TEST_P(MinimumOperationsToMakeArrayValuesEqualToKTest, SelfAuthoredSingleDistinctGreater) {
  std::vector<int> nums{3, 3, 3, 3};
  EXPECT_EQ(solution_.minOperations(nums, 2), 1);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumOperationsToMakeArrayValuesEqualToKTestSuite,
    MinimumOperationsToMakeArrayValuesEqualToKTest,
    ::testing::ValuesIn(
        MinimumOperationsToMakeArrayValuesEqualToKSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_3375
