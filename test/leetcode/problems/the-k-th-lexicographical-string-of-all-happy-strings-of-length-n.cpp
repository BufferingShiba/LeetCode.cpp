#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n.h"

namespace leetcode::problem_1415 {

class TheKThLexicographicalStringOfAllHappyStringsOfLengthNTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  TheKThLexicographicalStringOfAllHappyStringsOfLengthNSolution solution_;
};

TEST_P(TheKThLexicographicalStringOfAllHappyStringsOfLengthNTest, Example1) {
  EXPECT_EQ(solution_.getHappyString(1, 3), "c");
}

TEST_P(TheKThLexicographicalStringOfAllHappyStringsOfLengthNTest, Example2) {
  EXPECT_EQ(solution_.getHappyString(1, 4), "");
}

TEST_P(TheKThLexicographicalStringOfAllHappyStringsOfLengthNTest, Example3) {
  EXPECT_EQ(solution_.getHappyString(3, 9), "cab");
}

TEST_P(TheKThLexicographicalStringOfAllHappyStringsOfLengthNTest, SelfAuthoredFirstString) {
  EXPECT_EQ(solution_.getHappyString(3, 1), "aba");
}

TEST_P(TheKThLexicographicalStringOfAllHappyStringsOfLengthNTest, SelfAuthoredLastHappyString) {
  // 长度 1 恰好有 3 个 happy 字符串，第 3 个是 "c"
  EXPECT_EQ(solution_.getHappyString(2, 6), "cb");
}

INSTANTIATE_TEST_SUITE_P(
    TheKThLexicographicalStringOfAllHappyStringsOfLengthNTestInstance,
    TheKThLexicographicalStringOfAllHappyStringsOfLengthNTest,
    ::testing::ValuesIn(
        TheKThLexicographicalStringOfAllHappyStringsOfLengthNSolution().getStrategyNames()));

}  // namespace leetcode::problem_1415
