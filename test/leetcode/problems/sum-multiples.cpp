#include <gtest/gtest.h>

#include "leetcode/problems/sum-multiples.h"

using namespace leetcode::problem_2652;

class SumMultiplesTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
  SumMultiplesSolution solution;
};

TEST_P(SumMultiplesTest, Example1) {
  EXPECT_EQ(solution.sumOfMultiples(7), 21);
}

TEST_P(SumMultiplesTest, Example2) {
  EXPECT_EQ(solution.sumOfMultiples(10), 40);
}

TEST_P(SumMultiplesTest, Example3) {
  EXPECT_EQ(solution.sumOfMultiples(9), 30);
}

INSTANTIATE_TEST_SUITE_P(
  SumMultiples,
  SumMultiplesTest,
  testing::ValuesIn(SumMultiplesSolution().getStrategyNames())
);
