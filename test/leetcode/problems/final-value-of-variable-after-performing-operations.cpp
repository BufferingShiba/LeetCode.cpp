#include <gtest/gtest.h>
#include "leetcode/problems/final-value-of-variable-after-performing-operations.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2011 {
namespace {

class FinalValueOfVariableAfterPerformingOperationsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FinalValueOfVariableAfterPerformingOperationsSolution solution_;
};

TEST_P(FinalValueOfVariableAfterPerformingOperationsTest, Example1) {
  std::vector<std::string> operations = {"--X", "X++", "X++"};
  EXPECT_EQ(1, solution_.finalValueAfterOperations(operations));
}

TEST_P(FinalValueOfVariableAfterPerformingOperationsTest, Example2) {
  std::vector<std::string> operations = {"++X", "++X", "X++"};
  EXPECT_EQ(3, solution_.finalValueAfterOperations(operations));
}

TEST_P(FinalValueOfVariableAfterPerformingOperationsTest, Example3) {
  std::vector<std::string> operations = {"X++", "++X", "--X", "X--"};
  EXPECT_EQ(0, solution_.finalValueAfterOperations(operations));
}

TEST_P(FinalValueOfVariableAfterPerformingOperationsTest, SelfAuthoredSingleDecrement) {
  std::vector<std::string> operations = {"X--"};
  EXPECT_EQ(-1, solution_.finalValueAfterOperations(operations));
}

TEST_P(FinalValueOfVariableAfterPerformingOperationsTest, SelfAuthoredSingleIncrement) {
  std::vector<std::string> operations = {"X++"};
  EXPECT_EQ(1, solution_.finalValueAfterOperations(operations));
}

TEST_P(FinalValueOfVariableAfterPerformingOperationsTest, SelfAuthoredMixedOperations) {
  std::vector<std::string> operations = {"++X", "X--", "--X", "X++"};
  EXPECT_EQ(0, solution_.finalValueAfterOperations(operations));
}

INSTANTIATE_TEST_SUITE_P(
    FinalValueOfVariableAfterPerformingOperationsTestSuite,
    FinalValueOfVariableAfterPerformingOperationsTest,
    testing::ValuesIn(
        FinalValueOfVariableAfterPerformingOperationsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2011
}  // namespace leetcode
