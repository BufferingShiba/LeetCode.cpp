#include <gtest/gtest.h>

#include "leetcode/problems/complete-prime-number.h"

namespace leetcode {
namespace problem_3765 {
namespace {

class CompletePrimeNumberTest : public ::testing::TestWithParam<std::string> {
 protected:
  CompletePrimeNumberSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(CompletePrimeNumberTest, Example1) {
  EXPECT_TRUE(solution.completePrime(23));
}

TEST_P(CompletePrimeNumberTest, Example2) {
  EXPECT_FALSE(solution.completePrime(39));
}

TEST_P(CompletePrimeNumberTest, Example3) {
  EXPECT_TRUE(solution.completePrime(7));
}

TEST_P(CompletePrimeNumberTest, SelfAuthoredSingleDigitNonPrime) {
  EXPECT_FALSE(solution.completePrime(1));
  EXPECT_FALSE(solution.completePrime(4));
  EXPECT_FALSE(solution.completePrime(9));
}

TEST_P(CompletePrimeNumberTest, SelfAuthoredSingleDigitPrime) {
  EXPECT_TRUE(solution.completePrime(2));
  EXPECT_TRUE(solution.completePrime(3));
  EXPECT_TRUE(solution.completePrime(5));
}

TEST_P(CompletePrimeNumberTest, SelfAuthoredTwoDigitCompletePrimes) {
  // 23 和 37 都是：2,3,23,37 是素数，3,7,23,37 是素数
  EXPECT_TRUE(solution.completePrime(23));
  EXPECT_TRUE(solution.completePrime(37));
  EXPECT_TRUE(solution.completePrime(53));
  EXPECT_TRUE(solution.completePrime(73));
}

TEST_P(CompletePrimeNumberTest, SelfAuthoredNonCompleteDueToPrefix) {
  // 29: 2 prime, 29 prime → prefix ok; 9 not prime → suffix fails
  EXPECT_FALSE(solution.completePrime(29));
  // 31: 3 prime, 31 prime → prefix ok; 1 not prime → suffix fails
  EXPECT_FALSE(solution.completePrime(31));
}

TEST_P(CompletePrimeNumberTest, SelfAuthoredNonCompleteDueToSuffix) {
  // 有些数前缀全素数但后缀不满足
  EXPECT_FALSE(solution.completePrime(20));  // 2 prime, 20 not; suffix 0 not
}

TEST_P(CompletePrimeNumberTest, SelfAuthoredLargerNumber) {
  // 233: 前缀 2,23,233; 后缀 3,33,233
  // 2,23,233 prime; 3 prime; 33 not → false
  EXPECT_FALSE(solution.completePrime(233));
}

TEST_P(CompletePrimeNumberTest, SelfAuthoredKnownCompletePrimes) {
  // 一些已知的完全素数 (OEIS 相关序列)
  EXPECT_TRUE(solution.completePrime(2));
  EXPECT_TRUE(solution.completePrime(3));
  EXPECT_TRUE(solution.completePrime(5));
  EXPECT_TRUE(solution.completePrime(7));
  EXPECT_TRUE(solution.completePrime(23));
  EXPECT_TRUE(solution.completePrime(37));
  EXPECT_TRUE(solution.completePrime(53));
  EXPECT_TRUE(solution.completePrime(73));
  EXPECT_TRUE(solution.completePrime(373));
}

TEST_P(CompletePrimeNumberTest, SelfAuthoredEdgeCaseLargeNonPrime) {
  // 10^9 = 1000000000 不是素数
  EXPECT_FALSE(solution.completePrime(1000000000));
}

INSTANTIATE_TEST_SUITE_P(Strategies, CompletePrimeNumberTest,
                         ::testing::ValuesIn(
                             CompletePrimeNumberSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3765
}  // namespace leetcode
