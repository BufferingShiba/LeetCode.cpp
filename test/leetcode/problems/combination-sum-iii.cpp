#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/combination-sum-iii.h"

namespace leetcode::problem_216 {

class CombinationSumIiiTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CombinationSumIiiSolution solution_;
};

TEST_P(CombinationSumIiiTest, Example1) {
  int k = 3, n = 7;
  auto result = solution_.combinationSum3(k, n);
  std::vector<std::vector<int>> expected = {{1, 2, 4}};
  EXPECT_EQ(result, expected);
}

TEST_P(CombinationSumIiiTest, Example2) {
  int k = 3, n = 9;
  auto result = solution_.combinationSum3(k, n);
  std::vector<std::vector<int>> expected = {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}};
  EXPECT_EQ(result, expected);
}

TEST_P(CombinationSumIiiTest, Example3) {
  int k = 4, n = 1;
  auto result = solution_.combinationSum3(k, n);
  std::vector<std::vector<int>> expected = {};
  EXPECT_EQ(result, expected);
}

TEST_P(CombinationSumIiiTest, SelfAuthoredEdge) {
  // k=2, n=5 → 1+4=5, 2+3=5
  int k = 2, n = 5;
  auto result = solution_.combinationSum3(k, n);
  std::vector<std::vector<int>> expected = {{1, 4}, {2, 3}};
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(Strategies, CombinationSumIiiTest,
                         testing::ValuesIn(CombinationSumIiiSolution()
                                               .getStrategyNames()));

}  // namespace leetcode::problem_216
