#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/richest-customer-wealth.h"

namespace leetcode {
namespace problem_1672 {

class RichestCustomerWealthTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RichestCustomerWealthSolution solution;
};

TEST_P(RichestCustomerWealthTest, Example1) {
  std::vector<std::vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}};
  EXPECT_EQ(6, solution.maximumWealth(accounts));
}

TEST_P(RichestCustomerWealthTest, Example2) {
  std::vector<std::vector<int>> accounts = {{1, 5}, {7, 3}, {3, 5}};
  EXPECT_EQ(10, solution.maximumWealth(accounts));
}

TEST_P(RichestCustomerWealthTest, Example3) {
  std::vector<std::vector<int>> accounts = {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
  EXPECT_EQ(17, solution.maximumWealth(accounts));
}

TEST_P(RichestCustomerWealthTest, SelfAuthoredSingleCustomer) {
  std::vector<std::vector<int>> accounts = {{5}};
  EXPECT_EQ(5, solution.maximumWealth(accounts));
}

INSTANTIATE_TEST_SUITE_P(
    RichestCustomerWealthTestSuite, RichestCustomerWealthTest,
    ::testing::ValuesIn(RichestCustomerWealthSolution().getStrategyNames()));

}  // namespace problem_1672
}  // namespace leetcode
