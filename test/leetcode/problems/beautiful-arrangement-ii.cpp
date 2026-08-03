
#include "leetcode/problems/beautiful-arrangement-ii.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_667 {

class BeautifulArrangementIiTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BeautifulArrangementIiSolution solution;
};

static void Verify(int n, int k, const vector<int>& ans) {
  // 检查长度
  ASSERT_EQ(ans.size(), static_cast<size_t>(n));
  // 检查是 1..n 的排列
  vector<int> sorted = ans;
  sort(sorted.begin(), sorted.end());
  for (int i = 0; i < n; ++i) {
    EXPECT_EQ(sorted[i], i + 1) << "missing element " << (i + 1);
  }
  // 检查不同差值的数量
  unordered_set<int> distinct;
  for (int i = 1; i < n; ++i) {
    distinct.insert(abs(ans[i] - ans[i - 1]));
  }
  EXPECT_EQ(distinct.size(), static_cast<size_t>(k));
}

TEST_P(BeautifulArrangementIiTest, Example1) {
  int n = 3, k = 1;
  vector<int> result = solution.constructArray(n, k);
  Verify(n, k, result);
}

TEST_P(BeautifulArrangementIiTest, Example2) {
  int n = 3, k = 2;
  vector<int> result = solution.constructArray(n, k);
  Verify(n, k, result);
}

TEST_P(BeautifulArrangementIiTest, SelfAuthoredMinimalCase) {
  int n = 2, k = 1;
  vector<int> result = solution.constructArray(n, k);
  Verify(n, k, result);
}

TEST_P(BeautifulArrangementIiTest, SelfAuthoredMaxK) {
  int n = 6, k = 5;
  vector<int> result = solution.constructArray(n, k);
  Verify(n, k, result);
}

TEST_P(BeautifulArrangementIiTest, SelfAuthoredMediumCase) {
  int n = 10, k = 4;
  vector<int> result = solution.constructArray(n, k);
  Verify(n, k, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, BeautifulArrangementIiTest,
    ::testing::ValuesIn(BeautifulArrangementIiSolution().getStrategyNames()));

}  // namespace problem_667
}  // namespace leetcode
