#include <gtest/gtest.h>

#include <algorithm>

#include "leetcode/problems/combination-sum-ii.h"

namespace leetcode::problem_40 {
namespace {

using ParamType = std::string;

class CombinationSumIiTest : public testing::TestWithParam<ParamType> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CombinationSumIiSolution solution_;
};

TEST_P(CombinationSumIiTest, Example1) {
  std::vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;
  auto result = solution_.combinationSum2(candidates, target);

  // Sort each subset and the result itself for canonical comparison
  for (auto& subset : result) {
    std::sort(subset.begin(), subset.end());
  }
  std::sort(result.begin(), result.end());

  std::vector<std::vector<int>> expected = {{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}};
  for (auto& subset : expected) {
    std::sort(subset.begin(), subset.end());
  }
  std::sort(expected.begin(), expected.end());

  EXPECT_EQ(result, expected);
}

TEST_P(CombinationSumIiTest, Example2) {
  std::vector<int> candidates = {2, 5, 2, 1, 2};
  int target = 5;
  auto result = solution_.combinationSum2(candidates, target);

  for (auto& subset : result) {
    std::sort(subset.begin(), subset.end());
  }
  std::sort(result.begin(), result.end());

  std::vector<std::vector<int>> expected = {{1, 2, 2}, {5}};
  for (auto& subset : expected) {
    std::sort(subset.begin(), subset.end());
  }
  std::sort(expected.begin(), expected.end());

  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(, CombinationSumIiTest,
                         testing::ValuesIn(CombinationSumIiSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_40
