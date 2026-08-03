#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/add-digits.h"

namespace leetcode {
namespace problem_258 {

class AddDigitsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  AddDigitsSolution solution;
};

TEST_P(AddDigitsTest, Example1) {
  EXPECT_EQ(2, solution.addDigits(38));
}

TEST_P(AddDigitsTest, Example2) {
  EXPECT_EQ(0, solution.addDigits(0));
}

TEST_P(AddDigitsTest, SelfAuthoredMultipleOf9) {
  // 9 is a multiple of 9 but its digital root is 9 (not 0).
  EXPECT_EQ(9, solution.addDigits(9));
  // 18 -> 1 + 8 -> 9
  EXPECT_EQ(9, solution.addDigits(18));
}

INSTANTIATE_TEST_SUITE_P(
    AddDigitsTestSuite, AddDigitsTest,
    ::testing::ValuesIn(AddDigitsSolution().getStrategyNames()));

}  // namespace problem_258
}  // namespace leetcode
