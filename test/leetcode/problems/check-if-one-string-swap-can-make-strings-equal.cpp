#include <gtest/gtest.h>

#include "leetcode/problems/check-if-one-string-swap-can-make-strings-equal.h"

namespace leetcode::problem_1790 {

class CheckIfOneStringSwapCanMakeStringsEqualTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CheckIfOneStringSwapCanMakeStringsEqualSolution solution_;
};

TEST_P(CheckIfOneStringSwapCanMakeStringsEqualTest, Example1) {
  EXPECT_TRUE(solution_.areAlmostEqual("bank", "kanb"));
}

TEST_P(CheckIfOneStringSwapCanMakeStringsEqualTest, Example2) {
  EXPECT_FALSE(solution_.areAlmostEqual("attack", "defend"));
}

TEST_P(CheckIfOneStringSwapCanMakeStringsEqualTest, Example3) {
  EXPECT_TRUE(solution_.areAlmostEqual("kelb", "kelb"));
}

TEST_P(CheckIfOneStringSwapCanMakeStringsEqualTest, SelfAuthored) {
  // single swap works
  EXPECT_TRUE(solution_.areAlmostEqual("ab", "ba"));
  // one mismatch only (impossible with one swap)
  EXPECT_FALSE(solution_.areAlmostEqual("ab", "ac"));
  // same string, length 1
  EXPECT_TRUE(solution_.areAlmostEqual("a", "a"));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CheckIfOneStringSwapCanMakeStringsEqualTest,
    testing::ValuesIn(
        CheckIfOneStringSwapCanMakeStringsEqualSolution().getStrategyNames()));

}  // namespace leetcode::problem_1790
