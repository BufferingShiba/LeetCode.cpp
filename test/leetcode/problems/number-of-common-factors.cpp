#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-common-factors.h"

namespace leetcode {
namespace problem_2427 {

class NumberOfCommonFactorsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfCommonFactorsSolution solution;
};

TEST_P(NumberOfCommonFactorsTest, Example1) {
  EXPECT_EQ(solution.commonFactors(12, 6), 4);
}

TEST_P(NumberOfCommonFactorsTest, Example2) {
  EXPECT_EQ(solution.commonFactors(25, 30), 2);
}

TEST_P(NumberOfCommonFactorsTest, SelfAuthoredEqualValues) {
  EXPECT_EQ(solution.commonFactors(100, 100), 9);
}

TEST_P(NumberOfCommonFactorsTest, SelfAuthoredCoprimeSmall) {
  EXPECT_EQ(solution.commonFactors(7, 13), 1);
}

TEST_P(NumberOfCommonFactorsTest, SelfAuthoredMinBoundary) {
  EXPECT_EQ(solution.commonFactors(1, 1000), 1);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfCommonFactorsTestSuite, NumberOfCommonFactorsTest,
    ::testing::ValuesIn(NumberOfCommonFactorsSolution().getStrategyNames()));

}  // namespace problem_2427
}  // namespace leetcode
