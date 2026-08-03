#include "leetcode/problems/calculate-score-after-performing-instructions.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3522 {
namespace {

class CalculateScoreAfterPerformingInstructionsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CalculateScoreAfterPerformingInstructionsSolution solution;
};

TEST_P(CalculateScoreAfterPerformingInstructionsTest, Example1) {
  std::vector<std::string> instructions = {"jump", "add", "add", "jump", "add", "jump"};
  std::vector<int> values = {2, 1, 3, 1, -2, -3};
  EXPECT_EQ(1, solution.calculateScore(instructions, values));
}

TEST_P(CalculateScoreAfterPerformingInstructionsTest, Example2) {
  std::vector<std::string> instructions = {"jump", "add", "add"};
  std::vector<int> values = {3, 1, 1};
  EXPECT_EQ(0, solution.calculateScore(instructions, values));
}

TEST_P(CalculateScoreAfterPerformingInstructionsTest, Example3) {
  std::vector<std::string> instructions = {"jump"};
  std::vector<int> values = {0};
  EXPECT_EQ(0, solution.calculateScore(instructions, values));
}

TEST_P(CalculateScoreAfterPerformingInstructionsTest, SelfAuthoredSimpleAdd) {
  std::vector<std::string> instructions = {"add", "add", "add"};
  std::vector<int> values = {1, 2, 3};
  EXPECT_EQ(6, solution.calculateScore(instructions, values));
}

TEST_P(CalculateScoreAfterPerformingInstructionsTest, SelfAuthoredJumpBackThenGoOut) {
  // jump(2) -> add(+5) -> jump(-1) back to index1 -> already visited
  std::vector<std::string> instructions = {"jump", "add", "jump"};
  std::vector<int> values = {2, 5, -1};
  EXPECT_EQ(5, solution.calculateScore(instructions, values));
}

TEST_P(CalculateScoreAfterPerformingInstructionsTest, SelfAuthoredNegativeJumpOutOfBounds) {
  std::vector<std::string> instructions = {"jump", "add"};
  std::vector<int> values = {-1, 5};
  // i=0 jump -> i=-1 out of bounds
  EXPECT_EQ(0, solution.calculateScore(instructions, values));
}

INSTANTIATE_TEST_SUITE_P(
    CalculateScoreAfterPerformingInstructionsTestSuite,
    CalculateScoreAfterPerformingInstructionsTest,
    ::testing::ValuesIn(
        CalculateScoreAfterPerformingInstructionsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3522
}  // namespace leetcode
