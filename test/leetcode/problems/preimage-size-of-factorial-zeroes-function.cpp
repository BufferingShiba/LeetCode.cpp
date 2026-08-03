#include "leetcode/problems/preimage-size-of-factorial-zeroes-function.h"

#include <gtest/gtest.h>
#include <string>

namespace leetcode {
namespace problem_793 {
namespace {

class PreimageSizeOfFactorialZeroesFunctionTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  PreimageSizeOfFactorialZeroesFunctionSolution solution;
};

TEST_P(PreimageSizeOfFactorialZeroesFunctionTest, Example1) {
  EXPECT_EQ(solution.preimageSizeFZF(0), 5);
}

TEST_P(PreimageSizeOfFactorialZeroesFunctionTest, Example2) {
  EXPECT_EQ(solution.preimageSizeFZF(5), 0);
}

TEST_P(PreimageSizeOfFactorialZeroesFunctionTest, Example3) {
  EXPECT_EQ(solution.preimageSizeFZF(3), 5);
}

TEST_P(PreimageSizeOfFactorialZeroesFunctionTest, KOne) {
  // f(x)=1 for x=5..9
  EXPECT_EQ(solution.preimageSizeFZF(1), 5);
}

TEST_P(PreimageSizeOfFactorialZeroesFunctionTest, KFour) {
  // f(20)=4, f(x)=4 for x=20..24
  EXPECT_EQ(solution.preimageSizeFZF(4), 5);
}

TEST_P(PreimageSizeOfFactorialZeroesFunctionTest, KSeven) {
  // f(30)=6+1=7, f(x)=7 for x=30..34
  EXPECT_EQ(solution.preimageSizeFZF(7), 5);
}

INSTANTIATE_TEST_SUITE_P(
    PreimageSizeOfFactorialZeroesFunctionSuite,
    PreimageSizeOfFactorialZeroesFunctionTest,
    ::testing::ValuesIn(
        PreimageSizeOfFactorialZeroesFunctionSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_793
}  // namespace leetcode
