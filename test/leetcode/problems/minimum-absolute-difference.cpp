#include "leetcode/problems/minimum-absolute-difference.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1200 {

class MinimumAbsoluteDifferenceTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumAbsoluteDifferenceSolution solution;
};

TEST_P(MinimumAbsoluteDifferenceTest, Example1) {
  vector<int> arr = {4, 2, 1, 3};
  vector<vector<int>> expected = {{1, 2}, {2, 3}, {3, 4}};
  vector<vector<int>> result = solution.minimumAbsDifference(arr);
  EXPECT_EQ(expected, result);
}

TEST_P(MinimumAbsoluteDifferenceTest, Example2) {
  vector<int> arr = {1, 3, 6, 10, 15};
  vector<vector<int>> expected = {{1, 3}};
  vector<vector<int>> result = solution.minimumAbsDifference(arr);
  EXPECT_EQ(expected, result);
}

TEST_P(MinimumAbsoluteDifferenceTest, Example3) {
  vector<int> arr = {3, 8, -10, 23, 19, -4, -14, 27};
  vector<vector<int>> expected = {{-14, -10}, {19, 23}, {23, 27}};
  vector<vector<int>> result = solution.minimumAbsDifference(arr);
  EXPECT_EQ(expected, result);
}

TEST_P(MinimumAbsoluteDifferenceTest, TwoElements) {
  vector<int> arr = {5, 2};
  vector<vector<int>> expected = {{2, 5}};
  vector<vector<int>> result = solution.minimumAbsDifference(arr);
  EXPECT_EQ(expected, result);
}

TEST_P(MinimumAbsoluteDifferenceTest, AllEqualDifference) {
  vector<int> arr = {1, 2, 3, 4, 5};
  vector<vector<int>> expected = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  vector<vector<int>> result = solution.minimumAbsDifference(arr);
  EXPECT_EQ(expected, result);
}

TEST_P(MinimumAbsoluteDifferenceTest, LargeArray) {
  // 测试排序算法的性能（暴力法会超时，但这里只是验证正确性）
  vector<int> arr = {100, 200, 300, 400, 500};
  vector<vector<int>> expected = {{100, 200}, {200, 300}, {300, 400}, {400, 500}};
  vector<vector<int>> result = solution.minimumAbsDifference(arr);
  EXPECT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumAbsoluteDifferenceTest,
    ::testing::ValuesIn(MinimumAbsoluteDifferenceSolution().getStrategyNames()));

}  // namespace problem_1200
}  // namespace leetcode