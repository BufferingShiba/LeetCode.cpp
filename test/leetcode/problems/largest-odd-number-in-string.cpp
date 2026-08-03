#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/largest-odd-number-in-string.h"

namespace leetcode {
namespace problem_1903 {

class LargestOddNumberInStringTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  LargestOddNumberInStringSolution solution_;
};

TEST_P(LargestOddNumberInStringTest, Example1) {
  EXPECT_EQ(solution_.largestOddNumber("52"), "5");
}

TEST_P(LargestOddNumberInStringTest, Example2) {
  EXPECT_EQ(solution_.largestOddNumber("4206"), "");
}

TEST_P(LargestOddNumberInStringTest, Example3) {
  EXPECT_EQ(solution_.largestOddNumber("35427"), "35427");
}

TEST_P(LargestOddNumberInStringTest, SelfAuthoredSingleOddDigit) {
  EXPECT_EQ(solution_.largestOddNumber("8"), "");
  EXPECT_EQ(solution_.largestOddNumber("7"), "7");
}

TEST_P(LargestOddNumberInStringTest, SelfAuthoredLeadingEvenPrefix) {
  EXPECT_EQ(solution_.largestOddNumber("2468135"), "2468135");
  EXPECT_EQ(solution_.largestOddNumber("24680"), "");
}

TEST_P(LargestOddNumberInStringTest, SelfAuthoredTrailingOddsDifferentPrefixes) {
  EXPECT_EQ(solution_.largestOddNumber("100002"), "1");
  EXPECT_EQ(solution_.largestOddNumber("239537672423884969653287101"
                                       ""), "239537672423884969653287101");
}

INSTANTIATE_TEST_SUITE_P(
    LargestOddNumberInStringTestSuite, LargestOddNumberInStringTest,
    ::testing::ValuesIn(LargestOddNumberInStringSolution().getStrategyNames()));

}  // namespace problem_1903
}  // namespace leetcode
