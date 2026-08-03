#include <gtest/gtest.h>
#include "leetcode/problems/assign-cookies.h"

using namespace leetcode::problem_455;

class AssignCookiesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  AssignCookiesSolution solution;
};

TEST_P(AssignCookiesTest, Example1) {
  std::vector<int> g = {1, 2, 3};
  std::vector<int> s = {1, 1};
  EXPECT_EQ(solution.findContentChildren(g, s), 1);
}

TEST_P(AssignCookiesTest, Example2) {
  std::vector<int> g = {1, 2};
  std::vector<int> s = {1, 2, 3};
  EXPECT_EQ(solution.findContentChildren(g, s), 2);
}

TEST_P(AssignCookiesTest, SelfAuthoredNoCookies) {
  std::vector<int> g = {1, 2, 3};
  std::vector<int> s = {};
  EXPECT_EQ(solution.findContentChildren(g, s), 0);
}

TEST_P(AssignCookiesTest, SelfAuthoredAllSatisfied) {
  std::vector<int> g = {1, 1, 1};
  std::vector<int> s = {1, 1, 1};
  EXPECT_EQ(solution.findContentChildren(g, s), 3);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    AssignCookiesTest,
    ::testing::ValuesIn(AssignCookiesSolution().getStrategyNames()));
