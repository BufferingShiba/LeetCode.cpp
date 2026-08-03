#include <gtest/gtest.h>

#include "leetcode/problems/find-maximum-value-in-a-constrained-sequence.h"

namespace leetcode {
namespace problem_3796 {
namespace {

using FindMaximumValueInAConstrainedSequenceTest =
    ::testing::TestWithParam<std::string>;

TEST_P(FindMaximumValueInAConstrainedSequenceTest, Example1) {
  FindMaximumValueInAConstrainedSequenceSolution solution;
  solution.setStrategy(GetParam());
  int n = 10;
  std::vector<std::vector<int>> restrictions = {{3, 1}, {8, 1}};
  std::vector<int> diff = {2, 2, 3, 1, 4, 5, 1, 1, 2};
  EXPECT_EQ(solution.findMaxVal(n, restrictions, diff), 6);
}

TEST_P(FindMaximumValueInAConstrainedSequenceTest, Example2) {
  FindMaximumValueInAConstrainedSequenceSolution solution;
  solution.setStrategy(GetParam());
  int n = 8;
  std::vector<std::vector<int>> restrictions = {{3, 2}};
  std::vector<int> diff = {3, 5, 2, 4, 2, 3, 1};
  EXPECT_EQ(solution.findMaxVal(n, restrictions, diff), 12);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindMaximumValueInAConstrainedSequenceTest,
    ::testing::ValuesIn(
        FindMaximumValueInAConstrainedSequenceSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3796
}  // namespace leetcode
