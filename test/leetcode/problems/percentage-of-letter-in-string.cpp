#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/percentage-of-letter-in-string.h"

namespace leetcode {
namespace problem_2278 {

class PercentageOfLetterInStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PercentageOfLetterInStringSolution solution;
};

TEST_P(PercentageOfLetterInStringTest, Example1) {
  EXPECT_EQ(33, solution.percentageLetter("foobar", 'o'));
}

TEST_P(PercentageOfLetterInStringTest, Example2) {
  EXPECT_EQ(0, solution.percentageLetter("jjjj", 'k'));
}

TEST_P(PercentageOfLetterInStringTest, SelfAuthoredAllMatch) {
  EXPECT_EQ(100, solution.percentageLetter("aaaa", 'a'));
}

TEST_P(PercentageOfLetterInStringTest, SelfAuthoredSingleCharMatch) {
  EXPECT_EQ(100, solution.percentageLetter("z", 'z'));
}

TEST_P(PercentageOfLetterInStringTest, SelfAuthoredNoMatch) {
  EXPECT_EQ(0, solution.percentageLetter("hello", 'x'));
}

INSTANTIATE_TEST_SUITE_P(
    PercentageOfLetterInStringTestInstance, PercentageOfLetterInStringTest,
    ::testing::ValuesIn(PercentageOfLetterInStringSolution().getStrategyNames()));

}  // namespace problem_2278
}  // namespace leetcode
