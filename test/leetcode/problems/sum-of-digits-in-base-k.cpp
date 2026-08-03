#include <gtest/gtest.h>

#include "leetcode/problems/sum-of-digits-in-base-k.h"

namespace leetcode {
namespace problem_1837 {
namespace {

class SumOfDigitsInBaseKTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  SumOfDigitsInBaseKSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }

 public:
  static std::vector<std::string> GetStrategies() {
    return SumOfDigitsInBaseKSolution().getStrategyNames();
  }
};

TEST_P(SumOfDigitsInBaseKTest, Example1) {
  int expected = 9;
  EXPECT_EQ(solution.sumBase(34, 6), expected);
}

TEST_P(SumOfDigitsInBaseKTest, Example2) {
  int expected = 1;
  EXPECT_EQ(solution.sumBase(10, 10), expected);
}

TEST_P(SumOfDigitsInBaseKTest, SelfAuthoredBase2) {
  // n = 7 -> binary 111, sum = 3
  EXPECT_EQ(solution.sumBase(7, 2), 3);
}

TEST_P(SumOfDigitsInBaseKTest, SelfAuthoredMinN) {
  // n = 1 in any base K -> digit is 1
  EXPECT_EQ(solution.sumBase(1, 7), 1);
}

INSTANTIATE_TEST_SUITE_P(
    SumOfDigitsInBaseKTestSuite, SumOfDigitsInBaseKTest,
    ::testing::ValuesIn(SumOfDigitsInBaseKTest::GetStrategies()));

}  // namespace
}  // namespace problem_1837
}  // namespace leetcode
