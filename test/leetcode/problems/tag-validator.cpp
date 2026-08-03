#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/tag-validator.h"

namespace leetcode {
namespace problem_591 {

class TagValidatorTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  TagValidatorSolution solution_;
};

TEST_P(TagValidatorTest, Example1) {
  EXPECT_TRUE(solution_.isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>"));
}

TEST_P(TagValidatorTest, Example2) {
  EXPECT_TRUE(solution_.isValid("<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>"));
}

TEST_P(TagValidatorTest, Example3) {
  EXPECT_FALSE(solution_.isValid("<A>  <B> </A>   </B>"));
}

TEST_P(TagValidatorTest, SelfAuthoredEmptyInvalid) {
  EXPECT_FALSE(solution_.isValid(""));
}

TEST_P(TagValidatorTest, SelfAuthoredNotWrappedInTag) {
  EXPECT_FALSE(solution_.isValid("<A></A>extra"));
}

TEST_P(TagValidatorTest, SelfAuthoredNotWrappedInTagPlainText) {
  EXPECT_FALSE(solution_.isValid("plain text"));
}

TEST_P(TagValidatorTest, SelfAuthoredInvalidTagNameLength) {
  EXPECT_FALSE(solution_.isValid("<ABCDEFGHIJ>text</ABCDEFGHIJ>"));
}

TEST_P(TagValidatorTest, SelfAuthoredLowercaseTagName) {
  EXPECT_FALSE(solution_.isValid("<a></a>"));
}

TEST_P(TagValidatorTest, SelfAuthoredUnmatchedEndTag) {
  EXPECT_FALSE(solution_.isValid("<A></B>"));
}

TEST_P(TagValidatorTest, SelfAuthoredValidNestedTags) {
  EXPECT_TRUE(solution_.isValid("<A><B>text</B></A>"));
}

TEST_P(TagValidatorTest, SelfAuthoredValidCDataInsideTag) {
  EXPECT_TRUE(solution_.isValid("<A><![CDATA[x]]></A>"));
}

TEST_P(TagValidatorTest, SelfAuthoredMismatchedClosingOrder) {
  EXPECT_FALSE(solution_.isValid("<A><B></A></B>"));
}

TEST_P(TagValidatorTest, SelfAuthoredCDataAtTopLevelInvalid) {
  EXPECT_FALSE(solution_.isValid("<A></A><![CDATA[x]]>"));
}

TEST_P(TagValidatorTest, SelfAuthoredUnclosedCData) {
  EXPECT_FALSE(solution_.isValid("<A><![CDATA[x]></A>"));
}

TEST_P(TagValidatorTest, SelfAuthoredInvalidEndTagName) {
  EXPECT_FALSE(solution_.isValid("<A>text</a>"));
}

TEST_P(TagValidatorTest, SelfAuthoredNoContentTag) {
  EXPECT_TRUE(solution_.isValid("<A></A>"));
}


// LeetCode 失败用例: WrongAnswerCase1
TEST_P(TagValidatorTest, WrongAnswerCase1) {
  // 输入: "<A></A><B></B>"
    // 期望: false
    EXPECT_FALSE(solution_.isValid("<A></A><B></B>"));

    // 最外层已闭合后再出现内容也应无效
    EXPECT_FALSE(solution_.isValid("<A></A>x"));
    EXPECT_FALSE(solution_.isValid("<A></A><A></A>"));
}
INSTANTIATE_TEST_SUITE_P(
    TagValidatorTestSuite,
    TagValidatorTest,
    ::testing::ValuesIn(TagValidatorSolution().getStrategyNames()));

}  // namespace problem_591
}  // namespace leetcode
