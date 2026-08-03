#include "leetcode/problems/find-missing-and-repeated-values.h"

#include <gtest/gtest.h>

namespace leetcode::problem_2965 {

class FindMissingAndRepeatedValuesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindMissingAndRepeatedValuesSolution solution;
};

TEST_P(FindMissingAndRepeatedValuesTest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 3}, {2, 2}};
  std::vector<int> expected = {2, 4};
  EXPECT_EQ(solution.findMissingAndRepeatedValues(grid), expected);
}

TEST_P(FindMissingAndRepeatedValuesTest, Example2) {
  std::vector<std::vector<int>> grid = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
  std::vector<int> expected = {9, 5};
  EXPECT_EQ(solution.findMissingAndRepeatedValues(grid), expected);
}

TEST_P(FindMissingAndRepeatedValuesTest, SelfAuthoredMinSize) {
  std::vector<std::vector<int>> grid = {{1, 1}, {3, 4}};
  std::vector<int> expected = {1, 2};
  EXPECT_EQ(solution.findMissingAndRepeatedValues(grid), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FindMissingAndRepeatedValuesTestCases, FindMissingAndRepeatedValuesTest,
    ::testing::ValuesIn(FindMissingAndRepeatedValuesSolution().getStrategyNames()));

}  // namespace leetcode::problem_2965
