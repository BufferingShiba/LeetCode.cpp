#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/fair-distribution-of-cookies.h"

namespace leetcode {
namespace problem_2305 {

class FairDistributionOfCookiesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FairDistributionOfCookiesSolution solution;
};

TEST_P(FairDistributionOfCookiesTest, Example1) {
  std::vector<int> cookies = {8, 15, 10, 20, 8};
  int k = 2;
  EXPECT_EQ(solution.distributeCookies(cookies, k), 31);
}

TEST_P(FairDistributionOfCookiesTest, Example2) {
  std::vector<int> cookies = {6, 1, 3, 2, 2, 4, 1, 2};
  int k = 3;
  EXPECT_EQ(solution.distributeCookies(cookies, k), 7);
}

TEST_P(FairDistributionOfCookiesTest, SelfAuthoredAllToOneChildIsolated) {
  // k == n，每个孩子只能拿一袋，不公平度 = 最大袋子
  std::vector<int> cookies = {1, 5, 9};
  int k = 3;
  EXPECT_EQ(solution.distributeCookies(cookies, k), 9);
}

INSTANTIATE_TEST_SUITE_P(
    FairDistributionOfCookiesTestSuite, FairDistributionOfCookiesTest,
    ::testing::ValuesIn(FairDistributionOfCookiesSolution().getStrategyNames()));

}  // namespace problem_2305
}  // namespace leetcode
