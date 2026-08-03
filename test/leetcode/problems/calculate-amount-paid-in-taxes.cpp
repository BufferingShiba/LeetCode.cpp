#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/core.h"
#include "leetcode/problems/calculate-amount-paid-in-taxes.h"

namespace leetcode::problem_2303 {

class CalculateAmountPaidInTaxesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CalculateAmountPaidInTaxesSolution solution;
};

TEST_P(CalculateAmountPaidInTaxesTest, Example1) {
  std::vector<std::vector<int>> brackets = {{3, 50}, {7, 10}, {12, 25}};
  int income = 10;
  double expected = 2.65000;
  EXPECT_NEAR(solution.calculateTax(brackets, income), expected, 1e-5);
}

TEST_P(CalculateAmountPaidInTaxesTest, Example2) {
  std::vector<std::vector<int>> brackets = {{1, 0}, {4, 25}, {5, 50}};
  int income = 2;
  double expected = 0.25000;
  EXPECT_NEAR(solution.calculateTax(brackets, income), expected, 1e-5);
}

TEST_P(CalculateAmountPaidInTaxesTest, Example3) {
  std::vector<std::vector<int>> brackets = {{2, 50}};
  int income = 0;
  double expected = 0.00000;
  EXPECT_NEAR(solution.calculateTax(brackets, income), expected, 1e-5);
}

TEST_P(CalculateAmountPaidInTaxesTest, SelfAuthoredIncomeExceedsAllBrackets) {
  std::vector<std::vector<int>> brackets = {{3, 10}, {5, 20}};
  int income = 100;
  // 3*10% + 2*20% = 0.3 + 0.4 = 0.7
  double expected = 0.70000;
  EXPECT_NEAR(solution.calculateTax(brackets, income), expected, 1e-5);
}

TEST_P(CalculateAmountPaidInTaxesTest, SelfAuthoredIncomeWithinFirstBracket) {
  std::vector<std::vector<int>> brackets = {{5, 40}, {10, 30}};
  int income = 3;
  // 3*40% = 1.2
  double expected = 1.20000;
  EXPECT_NEAR(solution.calculateTax(brackets, income), expected, 1e-5);
}

TEST_P(CalculateAmountPaidInTaxesTest, SelfAuthoredZeroPercentBracket) {
  std::vector<std::vector<int>> brackets = {{2, 0}, {5, 100}};
  int income = 5;
  // 2*0% + 3*100% = 3.0
  double expected = 3.00000;
  EXPECT_NEAR(solution.calculateTax(brackets, income), expected, 1e-5);
}

INSTANTIATE_TEST_SUITE_P(
    CalculateAmountPaidInTaxesTestSuite, CalculateAmountPaidInTaxesTest,
    ::testing::ValuesIn(CalculateAmountPaidInTaxesSolution().getStrategyNames()));

}  // namespace leetcode::problem_2303
