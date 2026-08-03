#include <gtest/gtest.h>
#include "leetcode/problems/find-minimum-in-rotated-sorted-array-ii.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_154 {
namespace {

class FindMinimumInRotatedSortedArrayIiTest
    : public ::testing::TestWithParam<std::string> {
protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  FindMinimumInRotatedSortedArrayIiSolution solution;
};

TEST_P(FindMinimumInRotatedSortedArrayIiTest, Example1) {
  std::vector<int> nums = {1, 3, 5};
  EXPECT_EQ(1, solution.findMin(nums));
}

TEST_P(FindMinimumInRotatedSortedArrayIiTest, Example2) {
  std::vector<int> nums = {2, 2, 2, 0, 1};
  EXPECT_EQ(0, solution.findMin(nums));
}

TEST_P(FindMinimumInRotatedSortedArrayIiTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {1};
  EXPECT_EQ(1, solution.findMin(nums));
}

TEST_P(FindMinimumInRotatedSortedArrayIiTest, SelfAuthoredAllEqual) {
  std::vector<int> nums = {3, 3, 3, 3, 3};
  EXPECT_EQ(3, solution.findMin(nums));
}

TEST_P(FindMinimumInRotatedSortedArrayIiTest, SelfAuthoredNotRotatedWithDuplicates) {
  std::vector<int> nums = {1, 2, 2, 3, 4, 4};
  EXPECT_EQ(1, solution.findMin(nums));
}

TEST_P(FindMinimumInRotatedSortedArrayIiTest, SelfAuthoredRotatedAtDuplicateBoundary) {
  std::vector<int> nums = {4, 4, 5, 6, 0, 1, 4};
  EXPECT_EQ(0, solution.findMin(nums));
}

INSTANTIATE_TEST_SUITE_P(
    FindMinimumInRotatedSortedArrayIiTestSuite,
    FindMinimumInRotatedSortedArrayIiTest,
    ::testing::ValuesIn(
        FindMinimumInRotatedSortedArrayIiSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_154
}  // namespace leetcode
