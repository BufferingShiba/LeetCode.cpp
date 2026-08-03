#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/largest-element-in-an-array-after-merge-operations.h"

namespace leetcode::problem_2789 {

class LargestElementInAnArrayAfterMergeOperationsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LargestElementInAnArrayAfterMergeOperationsSolution solution;
};

TEST_P(LargestElementInAnArrayAfterMergeOperationsTest, Example1) {
  std::vector<int> nums{2, 3, 7, 9, 3};
  EXPECT_EQ(solution.maxArrayValue(nums), 21LL);
}

TEST_P(LargestElementInAnArrayAfterMergeOperationsTest, Example2) {
  std::vector<int> nums{5, 3, 3};
  EXPECT_EQ(solution.maxArrayValue(nums), 11LL);
}

TEST_P(LargestElementInAnArrayAfterMergeOperationsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{7};
  EXPECT_EQ(solution.maxArrayValue(nums), 7LL);
}

TEST_P(LargestElementInAnArrayAfterMergeOperationsTest, SelfAuthoredTwoElementsMergeable) {
  std::vector<int> nums{2, 5};
  EXPECT_EQ(solution.maxArrayValue(nums), 7LL);
}

TEST_P(LargestElementInAnArrayAfterMergeOperationsTest, SelfAuthoredTwoElementsNotMergeable) {
  std::vector<int> nums{8, 3};
  EXPECT_EQ(solution.maxArrayValue(nums), 8LL);
}

INSTANTIATE_TEST_SUITE_P(
    LargestElementInAnArrayAfterMergeOperationsTestSuite,
    LargestElementInAnArrayAfterMergeOperationsTest,
    ::testing::ValuesIn(std::vector<std::string>{"GreedyMergeFromRight"}));

}  // namespace leetcode::problem_2789
