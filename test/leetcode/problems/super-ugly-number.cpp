#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/super-ugly-number.h"

using namespace leetcode::problem_313;

class SuperUglyNumberTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  SuperUglyNumberSolution solution_;
};

TEST_P(SuperUglyNumberTest, Example1) {
  int n = 12;
  std::vector<int> primes = {2, 7, 13, 19};
  EXPECT_EQ(solution_.nthSuperUglyNumber(n, primes), 32);
}

TEST_P(SuperUglyNumberTest, Example2) {
  int n = 1;
  std::vector<int> primes = {2, 3, 5};
  EXPECT_EQ(solution_.nthSuperUglyNumber(n, primes), 1);
}

TEST_P(SuperUglyNumberTest, SelfAuthoredSinglePrime) {
  int n = 10;
  std::vector<int> primes = {2};
  // Sequence: 1, 2, 4, 8, 16, 32, 64, 128, 256, 512
  EXPECT_EQ(solution_.nthSuperUglyNumber(n, primes), 512);
}

TEST_P(SuperUglyNumberTest, SelfAuthoredTwoPrimes) {
  int n = 7;
  std::vector<int> primes = {2, 3};
  // Sequence: 1, 2, 3, 4, 6, 8, 9
  EXPECT_EQ(solution_.nthSuperUglyNumber(n, primes), 9);
}

INSTANTIATE_TEST_SUITE_P(Strategies, SuperUglyNumberTest,
                         ::testing::ValuesIn(
                             SuperUglyNumberSolution().getStrategyNames()));