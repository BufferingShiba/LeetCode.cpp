#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/factorial-trailing-zeroes.h"

namespace leetcode {
namespace problem_172 {
namespace {

class FactorialTrailingZeroesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FactorialTrailingZeroesSolution solution_;
};

TEST_P(FactorialTrailingZeroesTest, Example1) {
  EXPECT_EQ(solution_.trailingZeroes(3), 0);
}

TEST_P(FactorialTrailingZeroesTest, Example2) {
  EXPECT_EQ(solution_.trailingZeroes(5), 1);
}

TEST_P(FactorialTrailingZeroesTest, Example3) {
  EXPECT_EQ(solution_.trailingZeroes(0), 0);
}

TEST_P(FactorialTrailingZeroesTest, SelfAuthoredEdgeCase25) {
  EXPECT_EQ(solution_.trailingZeroes(25), 6);
}

TEST_P(FactorialTrailingZeroesTest, SelfAuthoredEdgeCase100) {
  EXPECT_EQ(solution_.trailingZeroes(100), 24);
}

INSTANTIATE_TEST_SUITE_P(
    FactorialTrailingZeroesTestSuite, FactorialTrailingZeroesTest,
    ::testing::ValuesIn(FactorialTrailingZeroesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_172
}  // namespace leetcode
