#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/process-string-with-special-operations-ii.h"

namespace leetcode {
namespace problem_3614 {

class ProcessStringWithSpecialOperationsIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ProcessStringWithSpecialOperationsIiSolution solution_;
};

TEST_P(ProcessStringWithSpecialOperationsIiTest, Example1) {
  EXPECT_EQ('a', solution_.processStr("a#b%*", 1));
}

TEST_P(ProcessStringWithSpecialOperationsIiTest, Example2) {
  EXPECT_EQ('d', solution_.processStr("cd%#*#", 3));
}

TEST_P(ProcessStringWithSpecialOperationsIiTest, Example3) {
  EXPECT_EQ('.', solution_.processStr("z*#", 0));
}

TEST_P(ProcessStringWithSpecialOperationsIiTest, SelfAuthoredKOutOfBounds) {
  EXPECT_EQ('.', solution_.processStr("abc", 3));
}

TEST_P(ProcessStringWithSpecialOperationsIiTest, SelfAuthoredSingleCharNoOps) {
  EXPECT_EQ('x', solution_.processStr("x", 0));
}

INSTANTIATE_TEST_SUITE_P(
    ProcessStringWithSpecialOperationsIiTestSuite,
    ProcessStringWithSpecialOperationsIiTest,
    ::testing::ValuesIn(
        ProcessStringWithSpecialOperationsIiSolution().getStrategyNames()));

}  // namespace problem_3614
}  // namespace leetcode
