#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/sort-an-array.h"

namespace leetcode {
namespace problem_912 {

class SortAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SortAnArraySolution solution;
};

TEST_P(SortAnArrayTest, Example1) {
  std::vector<int> nums = {5, 2, 3, 1};
  std::vector<int> expected = {1, 2, 3, 5};
  EXPECT_EQ(solution.sortArray(nums), expected);
}

TEST_P(SortAnArrayTest, Example2) {
  std::vector<int> nums = {5, 1, 1, 2, 0, 0};
  std::vector<int> expected = {0, 0, 1, 1, 2, 5};
  EXPECT_EQ(solution.sortArray(nums), expected);
}

TEST_P(SortAnArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {42};
  std::vector<int> expected = {42};
  EXPECT_EQ(solution.sortArray(nums), expected);
}

TEST_P(SortAnArrayTest, SelfAuthoredAlreadySorted) {
  std::vector<int> nums = {-50000, -1000, 0, 999, 50000};
  std::vector<int> expected = {-50000, -1000, 0, 999, 50000};
  EXPECT_EQ(solution.sortArray(nums), expected);
}

TEST_P(SortAnArrayTest, SelfAuthoredAllEqual) {
  std::vector<int> nums = {3, 3, 3, 3, 3};
  std::vector<int> expected = {3, 3, 3, 3, 3};
  EXPECT_EQ(solution.sortArray(nums), expected);
}

TEST_P(SortAnArrayTest, SelfAuthoredReverseSorted) {
  std::vector<int> nums = {7, 6, 5, 4, 3, 2, 1};
  std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7};
  EXPECT_EQ(solution.sortArray(nums), expected);
}

TEST_P(SortAnArrayTest, SelfAuthoredBoundaryValues) {
  std::vector<int> nums = {50000, -50000};
  std::vector<int> expected = {-50000, 50000};
  EXPECT_EQ(solution.sortArray(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    SortAnArrayStrategies, SortAnArrayTest,
    ::testing::ValuesIn(SortAnArraySolution().getStrategyNames()));

}  // namespace problem_912
}  // namespace leetcode
