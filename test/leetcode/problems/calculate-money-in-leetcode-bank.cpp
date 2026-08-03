#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/calculate-money-in-leetcode-bank.h"

namespace leetcode {
namespace problem_1716 {

class CalculateMoneyInLeetcodeBankTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  CalculateMoneyInLeetcodeBankSolution solution;
};

TEST_P(CalculateMoneyInLeetcodeBankTest, Example1) {
  EXPECT_EQ(solution.totalMoney(4), 10);
}

TEST_P(CalculateMoneyInLeetcodeBankTest, Example2) {
  EXPECT_EQ(solution.totalMoney(10), 37);
}

TEST_P(CalculateMoneyInLeetcodeBankTest, Example3) {
  EXPECT_EQ(solution.totalMoney(20), 96);
}

TEST_P(CalculateMoneyInLeetcodeBankTest, SelfAuthoredSingleDay) {
  EXPECT_EQ(solution.totalMoney(1), 1);
}

TEST_P(CalculateMoneyInLeetcodeBankTest, SelfAuthoredFullWeek) {
  EXPECT_EQ(solution.totalMoney(7), 28);
}

TEST_P(CalculateMoneyInLeetcodeBankTest, SelfAuthoredTwoWeeksAndOneDay) {
  // (1..7) + (2..8) + 3 = 28 + 35 + 3 = 66
  EXPECT_EQ(solution.totalMoney(15), 66);
}

INSTANTIATE_TEST_SUITE_P(
    CalculateMoneyInLeetcodeBankTests,
    CalculateMoneyInLeetcodeBankTest,
    ::testing::ValuesIn(CalculateMoneyInLeetcodeBankSolution().getStrategyNames()));

}  // namespace problem_1716
}  // namespace leetcode
