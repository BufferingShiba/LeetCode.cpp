#include <gtest/gtest.h>

#include "leetcode/problems/soup-servings.h"

using namespace leetcode::problem_808;

class SoupServingsTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  SoupServingsSolution solution;
};

TEST_P(SoupServingsTest, Example1) {
  double result = solution.soupServings(50);
  EXPECT_NEAR(result, 0.62500, 1e-5);
}

TEST_P(SoupServingsTest, Example2) {
  double result = solution.soupServings(100);
  EXPECT_NEAR(result, 0.71875, 1e-5);
}

TEST_P(SoupServingsTest, SelfAuthoredEdgeCaseZero) {
  double result = solution.soupServings(0);
  EXPECT_NEAR(result, 0.5, 1e-5);
}

TEST_P(SoupServingsTest, SelfAuthoredLargeNThreshold) {
  double result = solution.soupServings(5000);
  EXPECT_NEAR(result, 1.0, 1e-5);
}

INSTANTIATE_TEST_SUITE_P(Strategies, SoupServingsTest,
                         testing::ValuesIn(SoupServingsSolution().getStrategyNames()));
