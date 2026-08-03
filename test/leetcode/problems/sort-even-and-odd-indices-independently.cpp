#include "leetcode/problems/sort-even-and-odd-indices-independently.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2164 {

class SortEvenAndOddIndicesIndependentlyTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SortEvenAndOddIndicesIndependentlySolution solution;
};

TEST_P(SortEvenAndOddIndicesIndependentlyTest, Example1) {
  vector<int> nums = {4, 1, 2, 3};
  vector<int> expected = {2, 3, 4, 1};
  EXPECT_EQ(expected, solution.sortEvenOdd(nums));
}

TEST_P(SortEvenAndOddIndicesIndependentlyTest, Example2) {
  vector<int> nums = {2, 1};
  vector<int> expected = {2, 1};
  EXPECT_EQ(expected, solution.sortEvenOdd(nums));
}

TEST_P(SortEvenAndOddIndicesIndependentlyTest, SelfAuthoredSingleElement) {
  vector<int> nums = {7};
  vector<int> expected = {7};
  EXPECT_EQ(expected, solution.sortEvenOdd(nums));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, SortEvenAndOddIndicesIndependentlyTest,
    ::testing::ValuesIn(
        SortEvenAndOddIndicesIndependentlySolution().getStrategyNames()));

}  // namespace problem_2164
}  // namespace leetcode
