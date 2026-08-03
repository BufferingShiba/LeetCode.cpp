#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/next-greater-element-iii.h"

namespace leetcode {
namespace problem_556 {
namespace {

class NextGreaterElementIiiTest : public ::testing::TestWithParam<std::string> {
 protected:
  NextGreaterElementIiiSolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(NextGreaterElementIiiTest, Example1) {
  EXPECT_EQ(21, solution.nextGreaterElement(12));
}

TEST_P(NextGreaterElementIiiTest, Example2) {
  EXPECT_EQ(-1, solution.nextGreaterElement(21));
}

TEST_P(NextGreaterElementIiiTest, SelfAuthoredSingleDigit) {
  EXPECT_EQ(-1, solution.nextGreaterElement(3));
}

TEST_P(NextGreaterElementIiiTest, SelfAuthoredOverflow) {
  EXPECT_EQ(-1, solution.nextGreaterElement(1999999999));
}

INSTANTIATE_TEST_SUITE_P(
    NextGreaterElementIiiTests, NextGreaterElementIiiTest,
    ::testing::ValuesIn(NextGreaterElementIiiSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_556
}  // namespace leetcode
