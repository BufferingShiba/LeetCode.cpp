#include <gtest/gtest.h>

#include "leetcode/problems/count-symmetric-integers.h"
#include <string>

namespace leetcode::problem_2843 {

using CountSymmetricIntegersTest = ::testing::TestWithParam<std::string>;

class CountSymmetricIntegersParamTest : public CountSymmetricIntegersTest {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  CountSymmetricIntegersSolution solution;
};

TEST_P(CountSymmetricIntegersParamTest, Example1) {
  EXPECT_EQ(solution.countSymmetricIntegers(1, 100), 9);
}

TEST_P(CountSymmetricIntegersParamTest, Example2) {
  EXPECT_EQ(solution.countSymmetricIntegers(1200, 1230), 4);
}

TEST_P(CountSymmetricIntegersParamTest, SelfAuthoredSingleRange) {
  EXPECT_EQ(solution.countSymmetricIntegers(11, 11), 1);
}

TEST_P(CountSymmetricIntegersParamTest, SelfAuthoredNoSymmetricInOddDigits) {
  EXPECT_EQ(solution.countSymmetricIntegers(100, 110), 0);
}

TEST_P(CountSymmetricIntegersParamTest, SelfAuthoredFourDigitVerifiable) {
  EXPECT_EQ(solution.countSymmetricIntegers(1000, 1003), 1);
}

INSTANTIATE_TEST_SUITE_P(
    CountSymmetricIntegersStrategies,
    CountSymmetricIntegersParamTest,
    ::testing::ValuesIn(CountSymmetricIntegersSolution().getStrategyNames()));

}  // namespace leetcode::problem_2843
