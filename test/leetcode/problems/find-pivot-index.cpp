#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-pivot-index.h"

namespace leetcode {
namespace problem_724 {

class FindPivotIndexTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindPivotIndexSolution solution;
};

TEST_P(FindPivotIndexTest, Example1) {
  std::vector<int> nums = {1, 7, 3, 6, 5, 6};
  EXPECT_EQ(3, solution.pivotIndex(nums));
}

TEST_P(FindPivotIndexTest, Example2) {
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(-1, solution.pivotIndex(nums));
}

TEST_P(FindPivotIndexTest, Example3) {
  std::vector<int> nums = {2, 1, -1};
  EXPECT_EQ(0, solution.pivotIndex(nums));
}

TEST_P(FindPivotIndexTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  EXPECT_EQ(0, solution.pivotIndex(nums));
}

TEST_P(FindPivotIndexTest, SelfAuthoredLastIndexPivot) {
  std::vector<int> nums = {1, 2, 3, 0};
  EXPECT_EQ(-1, solution.pivotIndex(nums));
}

INSTANTIATE_TEST_SUITE_P(
    FindPivotIndexStrategies, FindPivotIndexTest,
    ::testing::ValuesIn(FindPivotIndexSolution().getStrategyNames()));

}  // namespace problem_724
}  // namespace leetcode
