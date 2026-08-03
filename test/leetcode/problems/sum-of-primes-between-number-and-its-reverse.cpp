#include <gtest/gtest.h>
#include "leetcode/problems/sum-of-primes-between-number-and-its-reverse.h"

namespace leetcode::problem_3918 {

class SumOfPrimesBetweenNumberAndItsReverseTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SumOfPrimesBetweenNumberAndItsReverseSolution solution_;
};

TEST_P(SumOfPrimesBetweenNumberAndItsReverseTest, Example1) {
  EXPECT_EQ(132, solution_.sumOfPrimesInRange(13));
}

TEST_P(SumOfPrimesBetweenNumberAndItsReverseTest, Example2) {
  EXPECT_EQ(17, solution_.sumOfPrimesInRange(10));
}

TEST_P(SumOfPrimesBetweenNumberAndItsReverseTest, Example3) {
  EXPECT_EQ(0, solution_.sumOfPrimesInRange(8));
}

TEST_P(SumOfPrimesBetweenNumberAndItsReverseTest, SingleDigitPrime) {
  EXPECT_EQ(5, solution_.sumOfPrimesInRange(5));
}

TEST_P(SumOfPrimesBetweenNumberAndItsReverseTest, PalindromePrime) {
  EXPECT_EQ(11, solution_.sumOfPrimesInRange(11));
}

TEST_P(SumOfPrimesBetweenNumberAndItsReverseTest, BoundaryValue) {
  EXPECT_EQ(76127, solution_.sumOfPrimesInRange(1000));
}

INSTANTIATE_TEST_SUITE_P(
    SumOfPrimesBetweenNumberAndItsReverseTestSuite,
    SumOfPrimesBetweenNumberAndItsReverseTest,
    ::testing::ValuesIn(
        SumOfPrimesBetweenNumberAndItsReverseSolution().getStrategyNames()));

}  // namespace leetcode::problem_3918
