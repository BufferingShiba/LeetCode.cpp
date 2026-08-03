#include <gtest/gtest.h>
#include "leetcode/problems/check-if-word-is-valid-after-substitutions.h"

using namespace leetcode::problem_1003;

class CheckIfWordIsValidAfterSubstitutionsTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  CheckIfWordIsValidAfterSubstitutionsSolution solution;
};

TEST_P(CheckIfWordIsValidAfterSubstitutionsTest, Example1) {
  EXPECT_TRUE(solution.isValid("aabcbc"));
}

TEST_P(CheckIfWordIsValidAfterSubstitutionsTest, Example2) {
  EXPECT_TRUE(solution.isValid("abcabcababcc"));
}

TEST_P(CheckIfWordIsValidAfterSubstitutionsTest, Example3) {
  EXPECT_FALSE(solution.isValid("abccba"));
}

TEST_P(CheckIfWordIsValidAfterSubstitutionsTest, SelfAuthored) {
  EXPECT_TRUE(solution.isValid("abc"));
  EXPECT_FALSE(solution.isValid("a"));
  EXPECT_FALSE(solution.isValid("ab"));
  EXPECT_FALSE(solution.isValid("bac"));
  EXPECT_FALSE(solution.isValid("aabbcc"));
  EXPECT_TRUE(solution.isValid("abcabc"));
}

INSTANTIATE_TEST_SUITE_P(, CheckIfWordIsValidAfterSubstitutionsTest,
                         testing::ValuesIn(CheckIfWordIsValidAfterSubstitutionsSolution().getStrategyNames()));
