#include "leetcode/problems/html-entity-parser.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode::problem_1410 {

class HtmlEntityParserTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  HtmlEntityParserSolution solution_;
};

TEST_P(HtmlEntityParserTest, Example1) {
  EXPECT_EQ("& is an HTML entity but &ambassador; is not.",
            solution_.entityParser(
                "&amp; is an HTML entity but &ambassador; is not."));
}

TEST_P(HtmlEntityParserTest, Example2) {
  EXPECT_EQ("and I quote: \"...\"",
            solution_.entityParser("and I quote: &quot;...&quot;"));
}

TEST_P(HtmlEntityParserTest, SelfAuthoredAllEntities) {
  EXPECT_EQ("\" ' & > < /",
            solution_.entityParser(
                "&quot; &apos; &amp; &gt; &lt; &frasl;"));
}

TEST_P(HtmlEntityParserTest, SelfAuthoredNoEntities) {
  EXPECT_EQ("hello world", solution_.entityParser("hello world"));
}

TEST_P(HtmlEntityParserTest, SelfAuthoredAmpersandNotEntity) {
  EXPECT_EQ("& not an entity", solution_.entityParser("& not an entity"));
}

INSTANTIATE_TEST_SUITE_P(
    HtmlEntityParserTestSuite, HtmlEntityParserTest,
    ::testing::ValuesIn(HtmlEntityParserSolution().getStrategyNames()));

}  // namespace leetcode::problem_1410
