#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/strong-password-checker-ii.h"

namespace leetcode::problem_2299 {

class StrongPasswordCheckerIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  StrongPasswordCheckerIiSolution solution;
};

TEST_P(StrongPasswordCheckerIiTest, Example1) {
  EXPECT_TRUE(solution.strongPasswordCheckerII("IloveLe3tcode!"));
}

TEST_P(StrongPasswordCheckerIiTest, Example2) {
  EXPECT_FALSE(solution.strongPasswordCheckerII("Me+You--IsMyDream"));
}

TEST_P(StrongPasswordCheckerIiTest, Example3) {
  EXPECT_FALSE(solution.strongPasswordCheckerII("1aB!"));
}

TEST_P(StrongPasswordCheckerIiTest, SelfAuthoredMissingUppercase) {
  EXPECT_FALSE(solution.strongPasswordCheckerII("abcdefg1!"));
}

TEST_P(StrongPasswordCheckerIiTest, SelfAuthoredAdjacentSameChar) {
  EXPECT_FALSE(solution.strongPasswordCheckerII("AbcD12!!x"));
}

TEST_P(StrongPasswordCheckerIiTest, SelfAuthoredValidStrongPassword) {
  EXPECT_TRUE(solution.strongPasswordCheckerII("Ab1!cdef"));
}

INSTANTIATE_TEST_SUITE_P(
    StrongPasswordCheckerIiTests, StrongPasswordCheckerIiTest,
    ::testing::ValuesIn(StrongPasswordCheckerIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_2299
