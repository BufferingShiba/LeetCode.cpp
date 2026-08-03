#include <gtest/gtest.h>
#include <vector>

#include "leetcode/problems/sum-of-absolute-differences-in-a-sorted-array.h"

namespace leetcode {
namespace problem_1685 {
namespace {

class SumOfAbsoluteDifferencesInASortedArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SumOfAbsoluteDifferencesInASortedArraySolution solution;
};

TEST_P(SumOfAbsoluteDifferencesInASortedArrayTest, Example1) {
  std::vector<int> nums = {2, 3, 5};
  std::vector<int> expected = {4, 3, 5};
  EXPECT_EQ(solution.getSumAbsoluteDifferences(nums), expected);
}

TEST_P(SumOfAbsoluteDifferencesInASortedArrayTest, Example2) {
  std::vector<int> nums = {1, 4, 6, 8, 10};
  std::vector<int> expected = {24, 15, 13, 15, 21};
  EXPECT_EQ(solution.getSumAbsoluteDifferences(nums), expected);
}

TEST_P(SumOfAbsoluteDifferencesInASortedArrayTest, TwoElements) {
  std::vector<int> nums = {3, 7};
  std::vector<int> expected = {4, 4};
  EXPECT_EQ(solution.getSumAbsoluteDifferences(nums), expected);
}

TEST_P(SumOfAbsoluteDifferencesInASortedArrayTest, AllEqual) {
  std::vector<int> nums = {5, 5, 5, 5};
  std::vector<int> expected = {0, 0, 0, 0};
  EXPECT_EQ(solution.getSumAbsoluteDifferences(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    SumOfAbsoluteDifferencesInASortedArrayTests,
    SumOfAbsoluteDifferencesInASortedArrayTest,
    ::testing::ValuesIn(
        SumOfAbsoluteDifferencesInASortedArraySolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1685
}  // namespace leetcode
