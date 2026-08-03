#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/minimum-number-of-operations-to-make-string-sorted.h"

namespace leetcode::problem_1830 {

using solution_type = MinimumNumberOfOperationsToMakeStringSortedSolution;

class MinimumNumberOfOperationsToMakeStringSortedTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  solution_type solution_;
};

TEST_P(MinimumNumberOfOperationsToMakeStringSortedTest, Example1) {
  EXPECT_EQ(solution_.makeStringSorted("cba"), 5);
}

TEST_P(MinimumNumberOfOperationsToMakeStringSortedTest, Example2) {
  EXPECT_EQ(solution_.makeStringSorted("aabaa"), 2);
}

TEST_P(MinimumNumberOfOperationsToMakeStringSortedTest, SelfAuthoredAlreadySorted) {
  EXPECT_EQ(solution_.makeStringSorted("abc"), 0);
}

TEST_P(MinimumNumberOfOperationsToMakeStringSortedTest, SelfAuthoredAllSame) {
  EXPECT_EQ(solution_.makeStringSorted("aaaa"), 0);
}

TEST_P(MinimumNumberOfOperationsToMakeStringSortedTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution_.makeStringSorted("z"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfOperationsToMakeStringSortedTestCases,
    MinimumNumberOfOperationsToMakeStringSortedTest,
    ::testing::ValuesIn(solution_type().getStrategyNames()));

}  // namespace leetcode::problem_1830
