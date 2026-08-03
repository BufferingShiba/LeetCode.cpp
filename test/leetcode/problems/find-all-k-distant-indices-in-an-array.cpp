#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-all-k-distant-indices-in-an-array.h"

namespace leetcode::problem_2200 {

class FindAllKDistantIndicesInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindAllKDistantIndicesInAnArraySolution solution;
};

TEST_P(FindAllKDistantIndicesInAnArrayTest, Example1) {
  std::vector<int> nums{3, 4, 9, 1, 3, 9, 5};
  std::vector<int> expected{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(expected, solution.findKDistantIndices(nums, 9, 1));
}

TEST_P(FindAllKDistantIndicesInAnArrayTest, Example2) {
  std::vector<int> nums{2, 2, 2, 2, 2};
  std::vector<int> expected{0, 1, 2, 3, 4};
  EXPECT_EQ(expected, solution.findKDistantIndices(nums, 2, 2));
}

TEST_P(FindAllKDistantIndicesInAnArrayTest, SingleKeyAtEnd) {
  std::vector<int> nums{5, 1, 1, 1, 9};
  std::vector<int> expected{2, 3, 4};
  EXPECT_EQ(expected, solution.findKDistantIndices(nums, 9, 2));
}

INSTANTIATE_TEST_SUITE_P(
    FindAllKDistantIndicesInAnArrayTestSuite,
    FindAllKDistantIndicesInAnArrayTest,
    ::testing::ValuesIn(
        FindAllKDistantIndicesInAnArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_2200
