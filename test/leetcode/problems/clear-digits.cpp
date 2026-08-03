#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/clear-digits.h"

namespace leetcode::problem_3174 {

class ClearDigitsTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ClearDigitsSolution solution_;
};

TEST_P(ClearDigitsTest, Examples) {
  // Example 1
  EXPECT_EQ(solution_.clearDigits("abc"), "abc");
  // Example 2
  EXPECT_EQ(solution_.clearDigits("cb34"), "");
}

TEST_P(ClearDigitsTest, SelfAuthored) {
  // No digits
  EXPECT_EQ(solution_.clearDigits("a"), "a");
  // All digits matched with letters
  EXPECT_EQ(solution_.clearDigits("a1b2c3"), "");
  // Interleaved
  EXPECT_EQ(solution_.clearDigits("ab12cd34"), "");
}

INSTANTIATE_TEST_SUITE_P(, ClearDigitsTest,
                         testing::ValuesIn(ClearDigitsSolution().getStrategyNames()));

}  // namespace leetcode::problem_3174
