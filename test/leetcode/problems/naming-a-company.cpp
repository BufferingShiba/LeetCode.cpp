#include <gtest/gtest.h>

#include "leetcode/problems/naming-a-company.h"

using namespace leetcode::problem_2306;

class NamingACompanyTest : public testing::TestWithParam<std::string> {
 protected:
  NamingACompanySolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(NamingACompanyTest, Example1) {
  std::vector<std::string> ideas = {"coffee", "donuts", "time", "toffee"};
  EXPECT_EQ(solution.distinctNames(ideas), 6);
}

TEST_P(NamingACompanyTest, Example2) {
  std::vector<std::string> ideas = {"lack", "back"};
  EXPECT_EQ(solution.distinctNames(ideas), 0);
}

INSTANTIATE_TEST_SUITE_P(AllStrategies, NamingACompanyTest,
                         testing::ValuesIn(
                             NamingACompanySolution().getStrategyNames()));
