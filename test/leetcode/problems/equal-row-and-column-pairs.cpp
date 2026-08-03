#include <gtest/gtest.h>

#include "leetcode/problems/equal-row-and-column-pairs.h"

namespace leetcode::problem_2352 {

class EqualRowAndColumnPairsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  EqualRowAndColumnPairsSolution solution_;
};

TEST_P(EqualRowAndColumnPairsTest, Example1) {
  std::vector<std::vector<int>> grid = {
      {3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
  EXPECT_EQ(solution_.equalPairs(grid), 1);
}

TEST_P(EqualRowAndColumnPairsTest, Example2) {
  std::vector<std::vector<int>> grid = {
      {3, 1, 2, 2},
      {1, 4, 4, 5},
      {2, 4, 2, 2},
      {2, 4, 2, 2}};
  EXPECT_EQ(solution_.equalPairs(grid), 3);
}

TEST_P(EqualRowAndColumnPairsTest, SelfAuthoredSingleElement) {
  std::vector<std::vector<int>> grid = {{7}};
  EXPECT_EQ(solution_.equalPairs(grid), 1);
}

TEST_P(EqualRowAndColumnPairsTest, SelfAuthoredNoMatch) {
  std::vector<std::vector<int>> grid = {
      {1, 2}, {3, 4}};
  EXPECT_EQ(solution_.equalPairs(grid), 0);
}

INSTANTIATE_TEST_SUITE_P(
    EqualRowAndColumnPairsTestCases,
    EqualRowAndColumnPairsTest,
    ::testing::ValuesIn(EqualRowAndColumnPairsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2352
