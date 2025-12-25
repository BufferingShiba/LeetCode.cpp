#include "leetcode/problems/maximize-happiness-of-selected-children.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3075 {

class MaximizeHappinessOfSelectedChildrenTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximizeHappinessOfSelectedChildrenSolution solution;
};

TEST_P(MaximizeHappinessOfSelectedChildrenTest, Example1) {
  vector<int> happiness = {1, 2, 3};
  int k = 2;
  long long expected = 4;
  long long result = solution.maximumHappinessSum(happiness, k);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximizeHappinessOfSelectedChildrenTest, Example2) {
  vector<int> happiness = {1, 1, 1, 1};
  int k = 2;
  long long expected = 1;
  long long result = solution.maximumHappinessSum(happiness, k);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximizeHappinessOfSelectedChildrenTest, Example3) {
  vector<int> happiness = {2, 3, 4, 5};
  int k = 1;
  long long expected = 5;
  long long result = solution.maximumHappinessSum(happiness, k);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximizeHappinessOfSelectedChildrenTest, SingleElement) {
  vector<int> happiness = {10};
  int k = 1;
  long long expected = 10;
  long long result = solution.maximumHappinessSum(happiness, k);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximizeHappinessOfSelectedChildrenTest, AllZero) {
  vector<int> happiness = {0, 0, 0};
  int k = 3;
  long long expected = 0;
  long long result = solution.maximumHappinessSum(happiness, k);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximizeHappinessOfSelectedChildrenTest, LargeValues) {
  vector<int> happiness = {100000000, 100000000, 100000000};
  int k = 3;
  long long expected = 299999997;  // 100000000 + (100000000-1) + (100000000-2)
  long long result = solution.maximumHappinessSum(happiness, k);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximizeHappinessOfSelectedChildrenTest, DecreasingValues) {
  vector<int> happiness = {5, 4, 3, 2, 1};
  int k = 5;
  long long expected = 9;  // 5 + 3 + 1 + 0 + 0
  long long result = solution.maximumHappinessSum(happiness, k);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximizeHappinessOfSelectedChildrenTest, KEqualsN) {
  vector<int> happiness = {10, 8, 6, 4, 2};
  int k = 5;
  long long expected = 10 + 7 + 4 + 1 + 0;  // 10-0 + max(0,8-1) + max(0,6-2) + max(0,4-3) + max(0,2-4)
  // 10 + 7 + 4 + 1 + 0 = 22
  long long result = solution.maximumHappinessSum(happiness, k);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximizeHappinessOfSelectedChildrenTest, KGreaterThanEffective) {
  vector<int> happiness = {5, 5, 5};
  int k = 5;  // k > n, 但函数调用时 k <= n 是约束，所以不测这种情况
  // 根据约束 1 <= k <= n，所以 k 不会大于 n
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximizeHappinessOfSelectedChildrenTest,
    ::testing::ValuesIn(MaximizeHappinessOfSelectedChildrenSolution().getStrategyNames()));

}  // namespace problem_3075
}  // namespace leetcode