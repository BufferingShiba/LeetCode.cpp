#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/sum-of-largest-prime-substrings.h"

namespace leetcode {
namespace problem_3556 {

class SumOfLargestPrimeSubstringsTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  SumOfLargestPrimeSubstringsSolution solution;
};

TEST_P(SumOfLargestPrimeSubstringsTest, OfficialExamples) {
  // Example 1
  EXPECT_EQ(solution.sumOfLargestPrimes("12234"), 1469);
  // Example 2
  EXPECT_EQ(solution.sumOfLargestPrimes("111"), 11);
}

TEST_P(SumOfLargestPrimeSubstringsTest, NoPrime) {
  EXPECT_EQ(solution.sumOfLargestPrimes("468"), 0);
}

TEST_P(SumOfLargestPrimeSubstringsTest, SelfAuthoredSingleDigit) {
  EXPECT_EQ(solution.sumOfLargestPrimes("7"), 7);
  EXPECT_EQ(solution.sumOfLargestPrimes("1"), 0);
}

TEST_P(SumOfLargestPrimeSubstringsTest, SelfAuthoredLeadingZeros) {
  // "002" -> substrings: 0, 0, 2, 00, 02, 002 -> unique nums: 0, 2 -> prime: 2
  EXPECT_EQ(solution.sumOfLargestPrimes("002"), 2);
}

TEST_P(SumOfLargestPrimeSubstringsTest, SelfAuthoredAllSameDigit) {
  // "777" -> substrings: 7, 77, 777 -> primes: 7 (77=7*11, 777=3*7*37, but 777 is not prime)
  EXPECT_EQ(solution.sumOfLargestPrimes("777"), 7);
}

TEST_P(SumOfLargestPrimeSubstringsTest, SelfAuthoredTwoPrimesOnly) {
  // "235" -> substrings: 2,3,5,23,35,235 -> primes: 2,3,5,23 -> top 3: 23+5+3=31
  EXPECT_EQ(solution.sumOfLargestPrimes("235"), 31);
}

INSTANTIATE_TEST_SUITE_P(Strategies, SumOfLargestPrimeSubstringsTest,
                         testing::ValuesIn(SumOfLargestPrimeSubstringsSolution().getStrategyNames()));

}  // namespace problem_3556
}  // namespace leetcode
