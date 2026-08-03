#include <gtest/gtest.h>
#include "leetcode/problems/xor-after-range-multiplication-queries-ii.h"

using namespace leetcode::problem_3655;

class XorAfterRangeMultiplicationQueriesIiTest : public testing::TestWithParam<std::string> {
 protected:
  XorAfterRangeMultiplicationQueriesIiSolution solution;
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(XorAfterRangeMultiplicationQueriesIiTest, Example1) {
  std::vector<int> nums = {1, 1, 1};
  std::vector<std::vector<int>> queries = {{0, 2, 1, 4}};
  EXPECT_EQ(solution.xorAfterQueries(nums, queries), 4);
}

TEST_P(XorAfterRangeMultiplicationQueriesIiTest, Example2) {
  std::vector<int> nums = {2, 3, 1, 5, 4};
  std::vector<std::vector<int>> queries = {{1, 4, 2, 3}, {0, 2, 1, 2}};
  EXPECT_EQ(solution.xorAfterQueries(nums, queries), 31);
}

INSTANTIATE_TEST_SUITE_P(
  Strategies,
  XorAfterRangeMultiplicationQueriesIiTest,
  testing::ValuesIn(XorAfterRangeMultiplicationQueriesIiSolution().getStrategyNames())
);
