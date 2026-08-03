#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/remove-outermost-parentheses.h"

namespace leetcode::problem_1022 {
namespace {

using namespace leetcode::problem_1021;

class RemoveOutermostParenthesesTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  RemoveOutermostParenthesesSolution solution_;
};

TEST_P(RemoveOutermostParenthesesTest, Example1) {
  EXPECT_EQ(solution_.removeOuterParentheses("(()())(())"), "()()()");
}

TEST_P(RemoveOutermostParenthesesTest, Example2) {
  EXPECT_EQ(solution_.removeOuterParentheses("(()())(())(()(()))"), "()()()()(())");
}

TEST_P(RemoveOutermostParenthesesTest, Example3) {
  EXPECT_EQ(solution_.removeOuterParentheses("()()"), "");
}

TEST_P(RemoveOutermostParenthesesTest, SelfAuthoredSinglePrimitive) {
  EXPECT_EQ(solution_.removeOuterParentheses("(()())"), "()()");
}

TEST_P(RemoveOutermostParenthesesTest, SelfAuthoredNestedPrimitive) {
  EXPECT_EQ(solution_.removeOuterParentheses("((()))"), "(())");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    RemoveOutermostParenthesesTest,
    testing::ValuesIn(RemoveOutermostParenthesesSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_1022
