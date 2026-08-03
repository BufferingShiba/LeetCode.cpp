#include <gtest/gtest.h>

#include "leetcode/problems/maximum-rows-covered-by-columns.h"

namespace leetcode::problem_2397 {

class MaximumRowsCoveredByColumnsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumRowsCoveredByColumnsSolution solution_;
};

TEST_P(MaximumRowsCoveredByColumnsTest, Example1) {
  std::vector<std::vector<int>> matrix = {
      {0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 0, 1}};
  EXPECT_EQ(3, solution_.maximumRows(matrix, 2));
}

TEST_P(MaximumRowsCoveredByColumnsTest, Example2) {
  std::vector<std::vector<int>> matrix = {{1}, {0}};
  EXPECT_EQ(2, solution_.maximumRows(matrix, 1));
}

TEST_P(MaximumRowsCoveredByColumnsTest, SingleRowNotFullyCovered) {
  // Row has three 1s but only two columns selected => not covered.
  std::vector<std::vector<int>> matrix = {{1, 1, 1}};
  EXPECT_EQ(0, solution_.maximumRows(matrix, 2));
}

TEST_P(MaximumRowsCoveredByColumnsTest, AllZeroRowsCovered) {
  std::vector<std::vector<int>> matrix = {{0, 0}, {0, 0}};
  EXPECT_EQ(2, solution_.maximumRows(matrix, 1));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumRowsCoveredByColumnsTestSuite, MaximumRowsCoveredByColumnsTest,
    ::testing::ValuesIn(
        MaximumRowsCoveredByColumnsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2397
