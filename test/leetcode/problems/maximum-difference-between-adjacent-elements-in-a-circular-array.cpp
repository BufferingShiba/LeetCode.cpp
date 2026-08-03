#include <gtest/gtest.h>

#include "leetcode/problems/maximum-difference-between-adjacent-elements-in-a-circular-array.h"

namespace leetcode::problem_3423 {

class MaximumDifferenceBetweenAdjacentElementsInACircularArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumDifferenceBetweenAdjacentElementsInACircularArraySolution solution;
};

TEST_P(MaximumDifferenceBetweenAdjacentElementsInACircularArrayTest,
       Example1) {
  std::vector<int> nums{1, 2, 4};
  EXPECT_EQ(solution.maxAdjacentDistance(nums), 3);
}

TEST_P(MaximumDifferenceBetweenAdjacentElementsInACircularArrayTest,
       Example2) {
  std::vector<int> nums{-5, -10, -5};
  EXPECT_EQ(solution.maxAdjacentDistance(nums), 5);
}

TEST_P(MaximumDifferenceBetweenAdjacentElementsInACircularArrayTest,
       SelfAuthoredMinSize) {
  std::vector<int> nums{3, 8};
  // |3-8|=5, |8-3|=5 (circular wrap), max = 5
  EXPECT_EQ(solution.maxAdjacentDistance(nums), 5);
}

TEST_P(MaximumDifferenceBetweenAdjacentElementsInACircularArrayTest,
       SelfAuthoredMaxWrap) {
  std::vector<int> nums{0, 10, 1, 10};
  // 0-10=10, 10-1=9, 1-10=9, 10-0=10 (wrap) -> max 10
  EXPECT_EQ(solution.maxAdjacentDistance(nums), 10);
}

INSTANTIATE_TEST_SUITE_P(
    MaxAdjacentDistance, MaximumDifferenceBetweenAdjacentElementsInACircularArrayTest,
    ::testing::ValuesIn(
        MaximumDifferenceBetweenAdjacentElementsInACircularArraySolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_3423
