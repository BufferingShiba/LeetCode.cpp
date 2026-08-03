#include <gtest/gtest.h>
#include <string>

#include "leetcode/problems/remove-trailing-zeros-from-a-string.h"

namespace leetcode {
namespace problem_2710 {

class RemoveTrailingZerosFromAStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  RemoveTrailingZerosFromAStringSolution solution_;
};

TEST_P(RemoveTrailingZerosFromAStringTest, Example1) {
  EXPECT_EQ("512301", solution_.removeTrailingZeros("51230100"));
}

TEST_P(RemoveTrailingZerosFromAStringTest, Example2) {
  EXPECT_EQ("123", solution_.removeTrailingZeros("123"));
}

TEST_P(RemoveTrailingZerosFromAStringTest, MultipleTrailingZeros) {
  EXPECT_EQ("1", solution_.removeTrailingZeros("1000"));
}

TEST_P(RemoveTrailingZerosFromAStringTest, SingleDigitNoZero) {
  EXPECT_EQ("5", solution_.removeTrailingZeros("5"));
}

INSTANTIATE_TEST_SUITE_P(
    RemoveTrailingZerosFromAStringTestCases, RemoveTrailingZerosFromAStringTest,
    ::testing::ValuesIn(RemoveTrailingZerosFromAStringSolution().getStrategyNames()));

}  // namespace problem_2710
}  // namespace leetcode
