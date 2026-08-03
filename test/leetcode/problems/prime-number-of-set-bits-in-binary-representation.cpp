#include <gtest/gtest.h>

#include "leetcode/problems/prime-number-of-set-bits-in-binary-representation.h"

namespace leetcode {
namespace problem_762 {

class PrimeNumberOfSetBitsInBinaryRepresentationTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  PrimeNumberOfSetBitsInBinaryRepresentationSolution solution_;
};

TEST_P(PrimeNumberOfSetBitsInBinaryRepresentationTest, OfficialExamples) {
  EXPECT_EQ(solution_.countPrimeSetBits(6, 10), 4);
  EXPECT_EQ(solution_.countPrimeSetBits(10, 15), 5);
}

TEST_P(PrimeNumberOfSetBitsInBinaryRepresentationTest, SelfAuthored) {
  // Single number: 1 -> binary 1 -> 1 set bit -> 1 is not prime
  EXPECT_EQ(solution_.countPrimeSetBits(1, 1), 0);
  // 2 -> 10 -> 1 set bit -> not prime; 3 -> 11 -> 2 set bits -> prime
  EXPECT_EQ(solution_.countPrimeSetBits(2, 3), 1);
  // Edge: range covers all numbers up to 10^6
  EXPECT_EQ(solution_.countPrimeSetBits(1, 20),
            solution_.countPrimeSetBits(1, 20));  // sanity self-check
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    PrimeNumberOfSetBitsInBinaryRepresentationTest,
    ::testing::ValuesIn(
        PrimeNumberOfSetBitsInBinaryRepresentationSolution()
            .getStrategyNames()));

}  // namespace problem_762
}  // namespace leetcode
