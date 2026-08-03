#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/xor-operation-in-an-array.h"

namespace leetcode::problem_1486 {

class XorOperationInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  XorOperationInAnArraySolution solution_;
};

TEST_P(XorOperationInAnArrayTest, Example1) {
  EXPECT_EQ(8, xorOperation(5, 0));
}

TEST_P(XorOperationInAnArrayTest, Example2) {
  EXPECT_EQ(8, xorOperation(4, 3));
}

TEST_P(XorOperationInAnArrayTest, SelfAuthoredSingleElement) {
  EXPECT_EQ(7, xorOperation(1, 7));
}

INSTANTIATE_TEST_SUITE_P(
    XorOperationInAnArrayTestCases, XorOperationInAnArrayTest,
    ::testing::ValuesIn(XorOperationInAnArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_1486
