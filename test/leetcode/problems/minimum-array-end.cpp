#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/minimum-array-end.h"

namespace leetcode {
namespace problem_3133 {
namespace {

class MinimumArrayEndTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumArrayEndSolution solution;
};

TEST_P(MinimumArrayEndTest, Example1) {
  EXPECT_EQ(solution.minEnd(3, 4), 6);
}

TEST_P(MinimumArrayEndTest, Example2) {
  EXPECT_EQ(solution.minEnd(2, 7), 15);
}

TEST_P(MinimumArrayEndTest, SingleElement) {
  EXPECT_EQ(solution.minEnd(1, 12345), 12345);
}

TEST_P(MinimumArrayEndTest, EmbedsAcrossSetBits) {
  EXPECT_EQ(solution.minEnd(5, 4), 12);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumArrayEndStrategyTests, MinimumArrayEndTest,
    ::testing::ValuesIn(MinimumArrayEndSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3133
}  // namespace leetcode
