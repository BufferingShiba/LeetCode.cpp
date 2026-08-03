#include <gtest/gtest.h>

#include "leetcode/problems/find-the-maximum-number-of-marked-indices.h"

namespace leetcode::problem_2576 {

namespace {
using FindTheMaximumNumberOfMarkedIndicesTest = ::testing::TestWithParam<std::string>;
}

TEST_P(FindTheMaximumNumberOfMarkedIndicesTest, Example1) {
  FindTheMaximumNumberOfMarkedIndicesSolution solution;
  solution.setStrategy(GetParam());
  std::vector<int> nums = {3, 5, 2, 4};
  EXPECT_EQ(solution.maxNumOfMarkedIndices(nums), 2);
}

TEST_P(FindTheMaximumNumberOfMarkedIndicesTest, Example2) {
  FindTheMaximumNumberOfMarkedIndicesSolution solution;
  solution.setStrategy(GetParam());
  std::vector<int> nums = {9, 2, 5, 4};
  EXPECT_EQ(solution.maxNumOfMarkedIndices(nums), 4);
}

TEST_P(FindTheMaximumNumberOfMarkedIndicesTest, Example3) {
  FindTheMaximumNumberOfMarkedIndicesSolution solution;
  solution.setStrategy(GetParam());
  std::vector<int> nums = {7, 6, 8};
  EXPECT_EQ(solution.maxNumOfMarkedIndices(nums), 0);
}

TEST_P(FindTheMaximumNumberOfMarkedIndicesTest, SelfAuthored) {
  FindTheMaximumNumberOfMarkedIndicesSolution solution;
  solution.setStrategy(GetParam());

  auto check = [&](std::vector<int> nums, int expected) {
    EXPECT_EQ(solution.maxNumOfMarkedIndices(nums), expected);
  };
  check({1, 2}, 2);  // 2*1 <= 2
  check({1, 1}, 0);  // 2*1 > 1
  check({10}, 0);    // single element
}

INSTANTIATE_TEST_SUITE_P(
    FindTheMaximumNumberOfMarkedIndicesTestSuite, FindTheMaximumNumberOfMarkedIndicesTest,
    ::testing::ValuesIn(FindTheMaximumNumberOfMarkedIndicesSolution().getStrategyNames()));

}  // namespace leetcode::problem_2576
