#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-integers-with-even-digit-sum.h"

namespace leetcode::problem_2180 {

using CountIntegersWithEvenDigitSumTest = ::testing::TestWithParam<std::string>;

class CountIntegersWithEvenDigitSumFixture : public CountIntegersWithEvenDigitSumTest {
 protected:
  CountIntegersWithEvenDigitSum solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(CountIntegersWithEvenDigitSumFixture, Example1) {
  EXPECT_EQ(solution.countEven(4), 2);
}

TEST_P(CountIntegersWithEvenDigitSumFixture, Example2) {
  EXPECT_EQ(solution.countEven(30), 14);
}

TEST_P(CountIntegersWithEvenDigitSumFixture, SelfAuthoredEdgeCaseNum1) {
  EXPECT_EQ(solution.countEven(1), 0);
}

TEST_P(CountIntegersWithEvenDigitSumFixture, SelfAuthoredEdgeCaseNum10) {
  // digits sums even: 2,4,6,8 (4 numbers)
  EXPECT_EQ(solution.countEven(10), 4);
}

INSTANTIATE_TEST_SUITE_P(
    CountIntegersWithEvenDigitSumTests,
    CountIntegersWithEvenDigitSumFixture,
    ::testing::ValuesIn(CountIntegersWithEvenDigitSum().getStrategyNames()));

}  // namespace leetcode::problem_2180
