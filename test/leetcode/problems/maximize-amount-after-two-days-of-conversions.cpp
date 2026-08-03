#include <gtest/gtest.h>

#include <cmath>
#include <string>
#include <vector>

#include "leetcode/problems/maximize-amount-after-two-days-of-conversions.h"

namespace leetcode {
namespace problem_3387 {

namespace {

void expectNear(double actual, double expected) {
  EXPECT_NEAR(actual, expected, 1e-6);
}

}  // namespace

class MaximizeAmountAfterTwoDaysOfConversionsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximizeAmountAfterTwoDaysOfConversionsSolution solution;
};

TEST_P(MaximizeAmountAfterTwoDaysOfConversionsTest, Example1) {
  std::string initialCurrency = "EUR";
  std::vector<std::vector<std::string>> pairs1 = {{"EUR", "USD"}, {"USD", "JPY"}};
  std::vector<double> rates1 = {2.0, 3.0};
  std::vector<std::vector<std::string>> pairs2 = {
      {"JPY", "USD"}, {"USD", "CHF"}, {"CHF", "EUR"}};
  std::vector<double> rates2 = {4.0, 5.0, 6.0};
  expectNear(solution.maxAmount(initialCurrency, pairs1, rates1, pairs2, rates2),
             720.0);
}

TEST_P(MaximizeAmountAfterTwoDaysOfConversionsTest, Example2) {
  std::string initialCurrency = "NGN";
  std::vector<std::vector<std::string>> pairs1 = {{"NGN", "EUR"}};
  std::vector<double> rates1 = {9.0};
  std::vector<std::vector<std::string>> pairs2 = {{"NGN", "EUR"}};
  std::vector<double> rates2 = {6.0};
  expectNear(solution.maxAmount(initialCurrency, pairs1, rates1, pairs2, rates2),
             1.5);
}

TEST_P(MaximizeAmountAfterTwoDaysOfConversionsTest, Example3) {
  std::string initialCurrency = "USD";
  std::vector<std::vector<std::string>> pairs1 = {{"USD", "EUR"}};
  std::vector<double> rates1 = {1.0};
  std::vector<std::vector<std::string>> pairs2 = {{"EUR", "JPY"}};
  std::vector<double> rates2 = {10.0};
  expectNear(solution.maxAmount(initialCurrency, pairs1, rates1, pairs2, rates2),
             1.0);
}

TEST_P(MaximizeAmountAfterTwoDaysOfConversionsTest, SelfAuthoredNoConversionBothDays) {
  std::string initialCurrency = "USD";
  std::vector<std::vector<std::string>> pairs1;
  std::vector<double> rates1;
  std::vector<std::vector<std::string>> pairs2;
  std::vector<double> rates2;
  expectNear(solution.maxAmount(initialCurrency, pairs1, rates1, pairs2, rates2),
             1.0);
}

TEST_P(MaximizeAmountAfterTwoDaysOfConversionsTest, SelfAuthoredSmallSelfAuthored) {
  // day1: USD->EUR at 2.0, day2: USD->EUR at 4.0 (reverse for EUR->USD).
  // Convert USD->EUR day1 (2.0), then EUR->USD day2 using 1/4.0 => 2.0/4.0 = 0.5.
  // Not beneficial, so answer is 1.0.
  std::string initialCurrency = "USD";
  std::vector<std::vector<std::string>> pairs1 = {{"USD", "EUR"}};
  std::vector<double> rates1 = {2.0};
  std::vector<std::vector<std::string>> pairs2 = {{"USD", "EUR"}};
  std::vector<double> rates2 = {4.0};
  expectNear(solution.maxAmount(initialCurrency, pairs1, rates1, pairs2, rates2),
             1.0);
}

INSTANTIATE_TEST_SUITE_P(
    MaximizeAmountAfterTwoDaysOfConversionsTests,
    MaximizeAmountAfterTwoDaysOfConversionsTest,
    ::testing::ValuesIn(MaximizeAmountAfterTwoDaysOfConversionsSolution()
                            .getStrategyNames()));

}  // namespace problem_3387
}  // namespace leetcode
