#include <gtest/gtest.h>
#include "leetcode/problems/count-monobit-integers.h"

using namespace leetcode::problem_3827;

class CountMonobitIntegersTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
  CountMonobitIntegersSolution solution;
};

TEST_P(CountMonobitIntegersTest, Example1) {
  EXPECT_EQ(solution.countMonobit(1), 2);
}

TEST_P(CountMonobitIntegersTest, Example2) {
  EXPECT_EQ(solution.countMonobit(4), 3);
}

TEST_P(CountMonobitIntegersTest, SelfAuthoredZero) {
  EXPECT_EQ(solution.countMonobit(0), 1);
}

TEST_P(CountMonobitIntegersTest, SelfAuthoredAllMonobitUpTo7) {
  EXPECT_EQ(solution.countMonobit(7), 4);
}

TEST_P(CountMonobitIntegersTest, SelfAuthoredLargerN) {
  EXPECT_EQ(solution.countMonobit(1000), 10);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CountMonobitIntegersTest,
    testing::ValuesIn(CountMonobitIntegersSolution().getStrategyNames()));
