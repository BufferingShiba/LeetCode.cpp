#include <gtest/gtest.h>
#include "leetcode/problems/nth-magical-number.h"

namespace leetcode {
namespace problem_878 {
namespace {

class NthMagicalNumberTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NthMagicalNumberSolution solution_;
};

TEST_P(NthMagicalNumberTest, Example1) {
  EXPECT_EQ(solution_.nthMagicalNumber(1, 2, 3), 2);
}

TEST_P(NthMagicalNumberTest, Example2) {
  EXPECT_EQ(solution_.nthMagicalNumber(4, 2, 3), 6);
}

TEST_P(NthMagicalNumberTest, SelfAuthoredLargeN) {
  // n=1e9, a=2, b=4 -> only even numbers are magical, count < n for small x.
  // Result is 2*n mod 1e9+7 = 2e9 mod 1e9+7.
  EXPECT_EQ(solution_.nthMagicalNumber(1000000000, 2, 4), 999999993);
}

TEST_P(NthMagicalNumberTest, SelfAuthoredSameDivisibility) {
  // a=3, b=6: lcm=6, count = x/3 + x/6 - x/6 = x/3. 5th magical = 15.
  EXPECT_EQ(solution_.nthMagicalNumber(5, 3, 6), 15);
}

TEST_P(NthMagicalNumberTest, SelfAuthoredSingle) {
  EXPECT_EQ(solution_.nthMagicalNumber(1, 10, 10), 10);
}

INSTANTIATE_TEST_SUITE_P(
    NthMagicalNumberTestCases,
    NthMagicalNumberTest,
    ::testing::ValuesIn(NthMagicalNumberSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_878
}  // namespace leetcode
