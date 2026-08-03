#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/balanced-k-factor-decomposition.h"

namespace leetcode::problem_3669 {

class BalancedKFactorDecompositionTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  BalancedKFactorDecompositionSolution solution_;
};

TEST_P(BalancedKFactorDecompositionTest, Example1) {
  auto res = solution_.minDifference(100, 2);
  ASSERT_EQ(res.size(), 2u);
  long long prod = 1;
  int mn = res[0], mx = res[0];
  for (int v : res) {
    prod *= v;
    mn = std::min(mn, v);
    mx = std::max(mx, v);
  }
  EXPECT_EQ(prod, 100LL);
  EXPECT_EQ(mx - mn, 0);
}

TEST_P(BalancedKFactorDecompositionTest, Example2) {
  auto res = solution_.minDifference(44, 3);
  ASSERT_EQ(res.size(), 3u);
  long long prod = 1;
  int mn = res[0], mx = res[0];
  for (int v : res) {
    prod *= v;
    mn = std::min(mn, v);
    mx = std::max(mx, v);
  }
  EXPECT_EQ(prod, 44LL);
  EXPECT_EQ(mx - mn, 9);
}

INSTANTIATE_TEST_SUITE_P(
    BalancedKFactorDecompositionTestSuite,
    BalancedKFactorDecompositionTest,
    ::testing::ValuesIn(
        BalancedKFactorDecompositionSolution().getStrategyNames()));

}  // namespace leetcode::problem_3669
