#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/count-special-integers.h"

namespace leetcode::problem_2376 {

class CountSpecialIntegersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountSpecialIntegersSolution solution;
};

TEST_P(CountSpecialIntegersTest, Example1) {
  EXPECT_EQ(solution.countSpecialNumbers(20), 19);
}

TEST_P(CountSpecialIntegersTest, Example2) {
  EXPECT_EQ(solution.countSpecialNumbers(5), 5);
}

TEST_P(CountSpecialIntegersTest, Example3) {
  EXPECT_EQ(solution.countSpecialNumbers(135), 110);
}

INSTANTIATE_TEST_SUITE_P(
    CountSpecialIntegersTestSuite, CountSpecialIntegersTest,
    ::testing::ValuesIn(CountSpecialIntegersSolution().getStrategyNames()));

}  // namespace leetcode::problem_2376
