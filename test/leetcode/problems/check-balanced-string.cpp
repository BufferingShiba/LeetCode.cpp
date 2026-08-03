#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/check-balanced-string.h"

namespace leetcode {
namespace problem_3340 {
namespace {

class CheckBalancedStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  CheckBalancedStringSolution solution_;
};

TEST_P(CheckBalancedStringTest, Example1) {
  EXPECT_FALSE(solution_.isBalanced("1234"));
}

TEST_P(CheckBalancedStringTest, Example2) {
  EXPECT_TRUE(solution_.isBalanced("24123"));
}

TEST_P(CheckBalancedStringTest, SelfAuthoredSingleDigitEachSide) {
  EXPECT_TRUE(solution_.isBalanced("11"));
}

TEST_P(CheckBalancedStringTest, SelfAuthoredAllEvenIndices) {
  EXPECT_FALSE(solution_.isBalanced("5"));
}

INSTANTIATE_TEST_SUITE_P(
    CheckBalancedStringTestSuite, CheckBalancedStringTest,
    ::testing::ValuesIn(CheckBalancedStringSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3340
}  // namespace leetcode
