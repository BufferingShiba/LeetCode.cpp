#include "leetcode/problems/string-transformation.h"

#include <gtest/gtest.h>

namespace leetcode::problem_2851 {

class StringTransformationTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  StringTransformationSolution solution;
};

TEST_P(StringTransformationTest, Example1) {
  EXPECT_EQ(solution.numberOfWays("abcd", "cdab", 2), 2);
}

TEST_P(StringTransformationTest, Example2) {
  EXPECT_EQ(solution.numberOfWays("ababab", "ababab", 1), 2);
}

TEST_P(StringTransformationTest, SelfAuthoredSingleStep) {
  // k=1, from s to t. count cyclic matches where rotate by exactly one
  // chosen step... choose suffix length l -> shift by n-l.
  // s="ab", n=2, steps length 1 only -> shifts by 1 -> "ba"=t => 1 way.
  EXPECT_EQ(solution.numberOfWays("ab", "ab", 1), 0);
}

TEST_P(StringTransformationTest, SelfAuthoredUnreachable) {
  // s="abc", t="abd" -> no rotation of s equals t, and s != t.
  EXPECT_EQ(solution.numberOfWays("abc", "abd", 3), 0);
}

INSTANTIATE_TEST_SUITE_P(
    StringTransformationTestSuite, StringTransformationTest,
    ::testing::ValuesIn(StringTransformationSolution().getStrategyNames()));

}  // namespace leetcode::problem_2851
