#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/zigzag-grid-traversal-with-skip.h"

namespace leetcode::problem_3417 {

namespace {

void AssertResult(const std::vector<int>& expected,
                  const std::vector<int>& actual) {
  EXPECT_EQ(expected, actual);
}

}  // namespace

class ZigzagGridTraversalWithSkipTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ZigzagGridTraversalWithSkipSolution solution_;
};

TEST_P(ZigzagGridTraversalWithSkipTest, Example1) {
  std::vector<std::vector<int>> grid{{1, 2}, {3, 4}};
  AssertResult({1, 4}, solution_.zigzagTraversal(grid));
}

TEST_P(ZigzagGridTraversalWithSkipTest, Example2) {
  std::vector<std::vector<int>> grid{{2, 1}, {2, 1}, {2, 1}};
  AssertResult({2, 1, 2}, solution_.zigzagTraversal(grid));
}

TEST_P(ZigzagGridTraversalWithSkipTest, Example3) {
  std::vector<std::vector<int>> grid{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  AssertResult({1, 3, 5, 7, 9}, solution_.zigzagTraversal(grid));
}

TEST_P(ZigzagGridTraversalWithSkipTest, SelfAuthoredWideGrid) {
  std::vector<std::vector<int>> grid{{1, 2, 3, 4}, {5, 6, 7, 8}};
  // snake: 1 2 3 4 8 7 6 5 -> even indices: 1 3 8 6
  AssertResult({1, 3, 8, 6}, solution_.zigzagTraversal(grid));
}

INSTANTIATE_TEST_SUITE_P(
    ZigzagGridTraversalWithSkipTests, ZigzagGridTraversalWithSkipTest,
    ::testing::ValuesIn(
        ZigzagGridTraversalWithSkipSolution().getStrategyNames()));

}  // namespace leetcode::problem_3417
