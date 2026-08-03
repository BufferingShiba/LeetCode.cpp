#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/number-of-zigzag-arrays-i.h"

namespace leetcode::problem_3699 {
namespace {

class NumberOfZigzagArraysITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfZigzagArraysISolution solution_;
};

TEST_P(NumberOfZigzagArraysITest, Example1) {
  EXPECT_EQ(solution_.zigZagArrays(3, 4, 5), 2);
}

TEST_P(NumberOfZigzagArraysITest, Example2) {
  EXPECT_EQ(solution_.zigZagArrays(3, 1, 3), 10);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfZigzagArraysITestSuite, NumberOfZigzagArraysITest,
    ::testing::ValuesIn(NumberOfZigzagArraysISolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_3699
