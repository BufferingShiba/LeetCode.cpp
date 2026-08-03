#include <gtest/gtest.h>

#include "leetcode/problems/minimum-number-of-operations-to-have-distinct-elements.h"

namespace leetcode::problem_3779 {

using Solution = MinimumNumberOfOperationsToHaveDistinctElementsSolution;

class MinimumNumberOfOperationsToHaveDistinctElementsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  Solution solution_;
};

TEST_P(MinimumNumberOfOperationsToHaveDistinctElementsTest, Example1) {
  std::vector<int> nums = {3, 8, 3, 6, 5, 8};
  EXPECT_EQ(solution_.minOperations(nums), 1);
}

TEST_P(MinimumNumberOfOperationsToHaveDistinctElementsTest, Example2) {
  std::vector<int> nums = {2, 2};
  EXPECT_EQ(solution_.minOperations(nums), 1);
}

TEST_P(MinimumNumberOfOperationsToHaveDistinctElementsTest, Example3) {
  std::vector<int> nums = {4, 3, 5, 1, 2};
  EXPECT_EQ(solution_.minOperations(nums), 0);
}

TEST_P(MinimumNumberOfOperationsToHaveDistinctElementsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {7};
  EXPECT_EQ(solution_.minOperations(nums), 0);
}

TEST_P(MinimumNumberOfOperationsToHaveDistinctElementsTest, SelfAuthoredAllSame) {
  std::vector<int> nums = {1, 1, 1, 1, 1, 1};
  // 每次删3个，6个元素需要2次操作才能清空
  EXPECT_EQ(solution_.minOperations(nums), 2);
}

TEST_P(MinimumNumberOfOperationsToHaveDistinctElementsTest, SelfAuthoredDuplicateAtEnd) {
  std::vector<int> nums = {1, 2, 3, 4, 5, 5};
  // 从右向左：j=5->5, j=4->5重复, i=5, ans=ceil(5/3)=2
  // 验证：删前3个得[4,5,5]有重复；再删3个得[] => 2次
  EXPECT_EQ(solution_.minOperations(nums), 2);
}

TEST_P(MinimumNumberOfOperationsToHaveDistinctElementsTest, SelfAuthoredNeedMultipleOps) {
  std::vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
  // n=10, 从右向左: j=9->5, j=8->5重复! i=9, ans=ceil(9/3)=3
  EXPECT_EQ(solution_.minOperations(nums), 3);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumNumberOfOperationsToHaveDistinctElementsTest,
    ::testing::ValuesIn(
        MinimumNumberOfOperationsToHaveDistinctElementsSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_3779
