#include <gtest/gtest.h>

#include "leetcode/problems/parse-lisp-expression.h"

using namespace leetcode::problem_736;

class ParseLispExpressionTest : public testing::TestWithParam<std::string> {
 protected:
  ParseLispExpressionSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(ParseLispExpressionTest, Example1) {
  EXPECT_EQ(
      solution.evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))"), 14);
}

TEST_P(ParseLispExpressionTest, Example2) {
  EXPECT_EQ(solution.evaluate("(let x 3 x 2 x)"), 2);
}

TEST_P(ParseLispExpressionTest, Example3) {
  EXPECT_EQ(solution.evaluate("(let x 1 y 2 x (add x y) (add x y))"), 5);
}

TEST_P(ParseLispExpressionTest, SelfAuthoredSimpleAdd) {
  EXPECT_EQ(solution.evaluate("(add 1 2)"), 3);
}

TEST_P(ParseLispExpressionTest, SelfAuthoredSimpleMult) {
  EXPECT_EQ(solution.evaluate("(mult 3 4)"), 12);
}

TEST_P(ParseLispExpressionTest, SelfAuthoredNegativeInteger) {
  EXPECT_EQ(solution.evaluate("(add -1 5)"), 4);
}

TEST_P(ParseLispExpressionTest, SelfAuthoredNestedScopes) {
  // inner let shadows outer x
  EXPECT_EQ(solution.evaluate("(let x 2 (add (let x 3 x) x))"), 5);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, ParseLispExpressionTest,
    testing::ValuesIn(ParseLispExpressionSolution().getStrategyNames()));
