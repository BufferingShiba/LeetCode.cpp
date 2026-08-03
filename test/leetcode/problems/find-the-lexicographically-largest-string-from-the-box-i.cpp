#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-lexicographically-largest-string-from-the-box-i.h"

using namespace leetcode::problem_3403;

class FindTheLexicographicallyLargestStringFromTheBoxITest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheLexicographicallyLargestStringFromTheBoxISolution solution;
};

TEST_P(FindTheLexicographicallyLargestStringFromTheBoxITest, Example1) {
  EXPECT_EQ(solution.answerString("dbca", 2), "dbc");
}

TEST_P(FindTheLexicographicallyLargestStringFromTheBoxITest, Example2) {
  EXPECT_EQ(solution.answerString("gggg", 4), "g");
}

TEST_P(FindTheLexicographicallyLargestStringFromTheBoxITest, SelfAuthoredSingleCharK1) {
  EXPECT_EQ(solution.answerString("a", 1), "a");
}

TEST_P(FindTheLexicographicallyLargestStringFromTheBoxITest, SelfAuthoredKEqualsN) {
  EXPECT_EQ(solution.answerString("abcd", 4), "d");
}

TEST_P(FindTheLexicographicallyLargestStringFromTheBoxITest, SelfAuthoredKEqualsTwo) {
  EXPECT_EQ(solution.answerString("abc", 2), "c");
}

TEST_P(FindTheLexicographicallyLargestStringFromTheBoxITest, SelfAuthoredAllSameChar) {
  // n=4, k=3: valid max length = n-k+1 = 2, max substring = "aa"
  EXPECT_EQ(solution.answerString("aaaa", 3), "aa");
}

TEST_P(FindTheLexicographicallyLargestStringFromTheBoxITest, SelfAuthoredMaxCharInMiddle) {
  // word="bca", k=2: maxChar='c' at i=1, must extend to end → "ca"
  EXPECT_EQ(solution.answerString("bca", 2), "ca");
}

TEST_P(FindTheLexicographicallyLargestStringFromTheBoxITest, SelfAuthoredMultipleMaxChars) {
  // word="zzab", k=3: maxChar='z' at 0,1. i=0 len=2 "zz", i=1 len=2 "za". Max "zz".
  EXPECT_EQ(solution.answerString("zzab", 3), "zz");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindTheLexicographicallyLargestStringFromTheBoxITest,
    testing::ValuesIn(
        FindTheLexicographicallyLargestStringFromTheBoxISolution()
            .getStrategyNames()));
