#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/capitalize-the-title.h"

namespace leetcode::problem_2129 {

class CapitalizeTheTitleTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CapitalizeTheTitleSolution solution;
};

TEST_P(CapitalizeTheTitleTest, Example1) {
  EXPECT_EQ(solution.getSolution()("capiTalIze tHe titLe"), "Capitalize The Title");
}

TEST_P(CapitalizeTheTitleTest, Example2) {
  EXPECT_EQ(solution.getSolution()("First leTTeR of EACH Word"), "First Letter of Each Word");
}

TEST_P(CapitalizeTheTitleTest, Example3) {
  EXPECT_EQ(solution.getSolution()("i lOve leetcode"), "i Love Leetcode");
}

TEST_P(CapitalizeTheTitleTest, SelfAuthoredSingleLetterWord) {
  EXPECT_EQ(solution.getSolution()("i"), "i");
}

INSTANTIATE_TEST_SUITE_P(
    CapitalizeTheTitleTestSuite, CapitalizeTheTitleTest,
    ::testing::ValuesIn(CapitalizeTheTitleSolution().getStrategyNames()));

}  // namespace leetcode::problem_2129
