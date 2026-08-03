#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-nesting-depth-of-the-parentheses.h"

namespace leetcode {
namespace problem_1614 {

class MaximumNestingDepthOfTheParenthesesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumNestingDepthOfTheParenthesesSolution solution_;
};

TEST_P(MaximumNestingDepthOfTheParenthesesTest, Example1) {
  EXPECT_EQ(solution_.maxDepth("(1+(2*3)+((8)/4))+1"), 3);
}

TEST_P(MaximumNestingDepthOfTheParenthesesTest, Example2) {
  EXPECT_EQ(solution_.maxDepth("(1)+((2))+(((3)))"), 3);
}

TEST_P(MaximumNestingDepthOfTheParenthesesTest, Example3) {
  EXPECT_EQ(solution_.maxDepth("()(())((()()))"), 3);
}

TEST_P(MaximumNestingDepthOfTheParenthesesTest, SelfAuthoredSingleParenthesis) {
  EXPECT_EQ(solution_.maxDepth("()"), 1);
}

TEST_P(MaximumNestingDepthOfTheParenthesesTest, SelfAuthoredNoParenthesis) {
  EXPECT_EQ(solution_.maxDepth("1+2*3/4"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNestingDepthOfTheParenthesesTestSuite,
    MaximumNestingDepthOfTheParenthesesTest,
    ::testing::ValuesIn(
        MaximumNestingDepthOfTheParenthesesSolution().getStrategyNames()));

}  // namespace problem_1614
}  // namespace leetcode
