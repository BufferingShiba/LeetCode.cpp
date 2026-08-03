#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/find-maximum-non-decreasing-array-length.h"

namespace leetcode {
namespace problem_2945 {

class FindMaximumNonDecreasingArrayLengthTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  FindMaximumNonDecreasingArrayLengthSolution solution_;
};

TEST_P(FindMaximumNonDecreasingArrayLengthTest, Example1) {
  std::vector<int> nums = {5, 2, 2};
  EXPECT_EQ(solution_.findMaximumLength(nums), 1);
}

TEST_P(FindMaximumNonDecreasingArrayLengthTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(solution_.findMaximumLength(nums), 4);
}

TEST_P(FindMaximumNonDecreasingArrayLengthTest, Example3) {
  std::vector<int> nums = {4, 3, 2, 6};
  EXPECT_EQ(solution_.findMaximumLength(nums), 3);
}

TEST_P(FindMaximumNonDecreasingArrayLengthTest, SingleElement) {
  std::vector<int> nums = {7};
  EXPECT_EQ(solution_.findMaximumLength(nums), 1);
}

TEST_P(FindMaximumNonDecreasingArrayLengthTest, TwoElementsIncreasing) {
  std::vector<int> nums = {2, 5};
  EXPECT_EQ(solution_.findMaximumLength(nums), 2);
}

TEST_P(FindMaximumNonDecreasingArrayLengthTest, TwoElementsDecreasing) {
  std::vector<int> nums = {5, 2};
  EXPECT_EQ(solution_.findMaximumLength(nums), 1);
}

TEST_P(FindMaximumNonDecreasingArrayLengthTest, EqualElements) {
  std::vector<int> nums = {3, 3, 3, 3};
  EXPECT_EQ(solution_.findMaximumLength(nums), 4);
}

TEST_P(FindMaximumNonDecreasingArrayLengthTest, MergeMiddle) {
  // [2,1,1,1,1] -> merge [1,1] to 2 -> [2,2,1,1] -> merge [1,1] to 2 -> [2,2,2] length 3
  std::vector<int> nums = {2, 1, 1, 1, 1};
  EXPECT_EQ(solution_.findMaximumLength(nums), 3);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindMaximumNonDecreasingArrayLengthTest,
    ::testing::ValuesIn(
        FindMaximumNonDecreasingArrayLengthSolution().getStrategyNames()));

}  // namespace problem_2945
}  // namespace leetcode
