#include "leetcode/problems/remove-comments.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_722 {

class RemoveCommentsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RemoveCommentsSolution solution;
};

TEST_P(RemoveCommentsTest, Example1) {
  std::vector<std::string> source = {
      "/*Test program */", "int main()", "{ ",
      "  // variable declaration ", "int a, b, c;", "/* This is a test",
      "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
  std::vector<std::string> expected = {"int main()", "{ ", "  ",
                                       "int a, b, c;", "a = b + c;", "}"};
  std::vector<std::string> result = solution.removeComments(source);
  EXPECT_EQ(result, expected);
}

TEST_P(RemoveCommentsTest, Example2) {
  std::vector<std::string> source = {"a/*comment", "line", "more_comment*/b"};
  std::vector<std::string> expected = {"ab"};
  std::vector<std::string> result = solution.removeComments(source);
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    RemoveCommentsTestSuite, RemoveCommentsTest,
    ::testing::ValuesIn(RemoveCommentsSolution().getStrategyNames()));

}  // namespace problem_722
}  // namespace leetcode
