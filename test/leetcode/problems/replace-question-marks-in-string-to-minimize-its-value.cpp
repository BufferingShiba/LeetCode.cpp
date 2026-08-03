#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/replace-question-marks-in-string-to-minimize-its-value.h"

namespace leetcode {
namespace problem_3081 {

class ReplaceQuestionMarksInStringToMinimizeItsValueTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ReplaceQuestionMarksInStringToMinimizeItsValueSolution solution_;
};

TEST_P(ReplaceQuestionMarksInStringToMinimizeItsValueTest, Example1) {
  std::string s = "???";
  std::string result = solution_.minimizeStringValue(s);
  EXPECT_EQ(result, "abc");
}

TEST_P(ReplaceQuestionMarksInStringToMinimizeItsValueTest, Example2) {
  std::string s = "a?a?";
  std::string result = solution_.minimizeStringValue(s);
  EXPECT_EQ(result, "abac");
}

TEST_P(ReplaceQuestionMarksInStringToMinimizeItsValueTest, SelfAuthoredNoQuestionMark) {
  std::string s = "hello";
  std::string result = solution_.minimizeStringValue(s);
  EXPECT_EQ(result, "hello");
}

TEST_P(ReplaceQuestionMarksInStringToMinimizeItsValueTest, SelfAuthoredSingleQuestionMark) {
  std::string s = "z?";
  std::string result = solution_.minimizeStringValue(s);
  EXPECT_EQ(result, "za");
}


// LeetCode 失败用例: WrongAnswerCase1
TEST_P(ReplaceQuestionMarksInStringToMinimizeItsValueTest, WrongAnswerCase1) {
  std::string s = "abcdefghijklmnopqrstuvwxy??";
    std::string result = solution_.minimizeStringValue(s);
    EXPECT_EQ(result, "abcdefghijklmnopqrstuvwxyaz");
}
INSTANTIATE_TEST_SUITE_P(
    ReplaceQuestionMarksInStringToMinimizeItsValueTestSuite,
    ReplaceQuestionMarksInStringToMinimizeItsValueTest,
    ::testing::ValuesIn(
        ReplaceQuestionMarksInStringToMinimizeItsValueSolution()
            .getStrategyNames()));

}  // namespace problem_3081
}  // namespace leetcode
