#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/goal-parser-interpretation.h"

namespace leetcode {
namespace problem_1678 {

class GoalParserInterpretationTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  GoalParserInterpretationSolution solution;
};

TEST_P(GoalParserInterpretationTest, Example1) {
  EXPECT_EQ("Goal", solution.interpret("G()(al)"));
}

TEST_P(GoalParserInterpretationTest, Example2) {
  EXPECT_EQ("Gooooal", solution.interpret("G()()()()(al)"));
}

TEST_P(GoalParserInterpretationTest, Example3) {
  EXPECT_EQ("alGalooG", solution.interpret("(al)G(al)()()G"));
}

TEST_P(GoalParserInterpretationTest, SelfAuthoredSingleG) {
  EXPECT_EQ("G", solution.interpret("G"));
}

INSTANTIATE_TEST_SUITE_P(
    GoalParserInterpretationTestSuite, GoalParserInterpretationTest,
    ::testing::ValuesIn(GoalParserInterpretationSolution().getStrategyNames()));

}  // namespace problem_1678
}  // namespace leetcode
