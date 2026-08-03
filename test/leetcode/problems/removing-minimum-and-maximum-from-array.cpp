#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/removing-minimum-and-maximum-from-array.h"

namespace leetcode::problem_2091 {

class RemovingMinimumAndMaximumFromArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RemovingMinimumAndMaximumFromArraySolution solution;
};

TEST_P(RemovingMinimumAndMaximumFromArrayTest, Example1) {
  std::vector<int> nums{2, 10, 7, 5, 4, 1, 8, 6};
  EXPECT_EQ(solution.minimumDeletions(nums), 5);
}

TEST_P(RemovingMinimumAndMaximumFromArrayTest, Example2) {
  std::vector<int> nums{0, -4, 19, 1, 8, -2, -3, 5};
  EXPECT_EQ(solution.minimumDeletions(nums), 3);
}

TEST_P(RemovingMinimumAndMaximumFromArrayTest, Example3) {
  std::vector<int> nums{101};
  EXPECT_EQ(solution.minimumDeletions(nums), 1);
}

TEST_P(RemovingMinimumAndMaximumFromArrayTest, SelfAuthoredMinAndMaxAtEnds) {
  // min at index 0, max at index 4; delete min from front, max from back
  std::vector<int> nums{1, 3, 2, 4, 5};
  EXPECT_EQ(solution.minimumDeletions(nums), 2);
}

INSTANTIATE_TEST_SUITE_P(
    RemovingMinimumAndMaximumFromArrayTestSuite,
    RemovingMinimumAndMaximumFromArrayTest,
    ::testing::ValuesIn(
        RemovingMinimumAndMaximumFromArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_2091
