#include <gtest/gtest.h>

#include "leetcode/problems/time-needed-to-rearrange-a-binary-string.h"

namespace leetcode {
namespace problem_2380 {

class TimeNeededToRearrangeABinaryStringTest : public ::testing::TestWithParam<std::string> {
 protected:
  TimeNeededToRearrangeABinaryStringSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(TimeNeededToRearrangeABinaryStringTest, Example1) {
  EXPECT_EQ(solution.secondsToRemoveOccurrences("0110101"), 4);
}

TEST_P(TimeNeededToRearrangeABinaryStringTest, Example2) {
  EXPECT_EQ(solution.secondsToRemoveOccurrences("11100"), 0);
}

TEST_P(TimeNeededToRearrangeABinaryStringTest, SelfAuthored) {
  EXPECT_EQ(solution.secondsToRemoveOccurrences("00111"), 4);
  EXPECT_EQ(solution.secondsToRemoveOccurrences("0101"), 2);
  EXPECT_EQ(solution.secondsToRemoveOccurrences("1010"), 1);
  EXPECT_EQ(solution.secondsToRemoveOccurrences("000111"), 5);
  EXPECT_EQ(solution.secondsToRemoveOccurrences("010"), 1);
  EXPECT_EQ(solution.secondsToRemoveOccurrences("0010"), 2);
  EXPECT_EQ(solution.secondsToRemoveOccurrences("0"), 0);
  EXPECT_EQ(solution.secondsToRemoveOccurrences("1"), 0);
  EXPECT_EQ(solution.secondsToRemoveOccurrences("10"), 0);
  EXPECT_EQ(solution.secondsToRemoveOccurrences("01"), 1);
}

INSTANTIATE_TEST_SUITE_P(Strategies,
                         TimeNeededToRearrangeABinaryStringTest,
                         ::testing::ValuesIn(
                             TimeNeededToRearrangeABinaryStringSolution().getStrategyNames()));

}  // namespace problem_2380
}  // namespace leetcode
