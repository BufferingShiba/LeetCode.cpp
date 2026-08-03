#include <gtest/gtest.h>

#include "leetcode/problems/smallest-divisible-digit-product-i.h"

namespace leetcode::problem_3345 {
namespace {

class SmallestDivisibleDigitProductITest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SmallestDivisibleDigitProductISolution solution_;
};

TEST_P(SmallestDivisibleDigitProductITest, OfficialExamples) {
  EXPECT_EQ(solution_.smallestNumber(10, 2), 10);
  EXPECT_EQ(solution_.smallestNumber(15, 3), 16);
}

TEST_P(SmallestDivisibleDigitProductITest, SelfAuthored) {
  // t=1: any number works, answer is n itself
  EXPECT_EQ(solution_.smallestNumber(7, 1), 7);
  // n=1, t=5: need digit product divisible by 5; digit product of 1=1,2=2,3=3,4=4,5=5 -> 5
  EXPECT_EQ(solution_.smallestNumber(1, 5), 5);
  // n=99, t=10: 99 product=81 not div by 10; 100 product=0 div by 10 -> 100
  EXPECT_EQ(solution_.smallestNumber(99, 10), 100);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    SmallestDivisibleDigitProductITest,
    testing::ValuesIn(
        SmallestDivisibleDigitProductISolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_3345
