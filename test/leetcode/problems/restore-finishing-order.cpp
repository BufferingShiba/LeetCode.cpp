#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/restore-finishing-order.h"

namespace leetcode::problem_3668 {

class RestoreFinishingOrderTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RestoreFinishingOrderSolution solution;
};

TEST_P(RestoreFinishingOrderTest, Example1) {
  std::vector<int> order{3, 1, 2, 5, 4};
  std::vector<int> friends{1, 3, 4};
  std::vector<int> expected{3, 1, 4};
  EXPECT_EQ(solution.recoverOrder(order, friends), expected);
}

TEST_P(RestoreFinishingOrderTest, Example2) {
  std::vector<int> order{1, 4, 5, 3, 2};
  std::vector<int> friends{2, 5};
  std::vector<int> expected{5, 2};
  EXPECT_EQ(solution.recoverOrder(order, friends), expected);
}

TEST_P(RestoreFinishingOrderTest, SelfAuthoredSingleFriendFirst) {
  std::vector<int> order{2, 3, 1, 4, 5};
  std::vector<int> friends{3};
  std::vector<int> expected{3};
  EXPECT_EQ(solution.recoverOrder(order, friends), expected);
}

INSTANTIATE_TEST_SUITE_P(
    RestoreFinishingOrderTestSuite, RestoreFinishingOrderTest,
    ::testing::ValuesIn(RestoreFinishingOrderSolution().getStrategyNames()));

}  // namespace leetcode::problem_3668
