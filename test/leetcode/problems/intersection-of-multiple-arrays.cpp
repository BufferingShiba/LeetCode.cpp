#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/intersection-of-multiple-arrays.h"

namespace leetcode::problem_2248 {

class IntersectionOfMultipleArraysTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  IntersectionOfMultipleArraysSolution solution;
};

TEST_P(IntersectionOfMultipleArraysTest, Example1) {
  std::vector<std::vector<int>> nums = {{3, 1, 2, 4, 5}, {1, 2, 3, 4}, {3, 4, 5, 6}};
  EXPECT_EQ((std::vector<int>{3, 4}), solution.intersection(nums));
}

TEST_P(IntersectionOfMultipleArraysTest, Example2) {
  std::vector<std::vector<int>> nums = {{1, 2, 3}, {4, 5, 6}};
  EXPECT_EQ((std::vector<int>{}), solution.intersection(nums));
}

TEST_P(IntersectionOfMultipleArraysTest, SelfAuthoredSingleArrayReturnsSortedDistinct) {
  std::vector<std::vector<int>> nums = {{5, 3, 1}};
  EXPECT_EQ((std::vector<int>{1, 3, 5}), solution.intersection(nums));
}

INSTANTIATE_TEST_SUITE_P(
    IntersectionOfMultipleArraysTestSuite,
    IntersectionOfMultipleArraysTest,
    ::testing::ValuesIn(IntersectionOfMultipleArraysSolution().getStrategyNames()));

}  // namespace leetcode::problem_2248
