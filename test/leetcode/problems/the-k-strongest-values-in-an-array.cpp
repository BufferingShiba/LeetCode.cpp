#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

#include "leetcode/problems/the-k-strongest-values-in-an-array.h"

namespace leetcode {
namespace problem_1471 {
namespace {

bool isStronger(int x, int y, int m) {
  int dx = std::abs(x - m);
  int dy = std::abs(y - m);
  if (dx != dy) return dx > dy;
  return x > y;
}

bool isValid(const std::vector<int>& result, const std::vector<int>& arr,
             int k, int m) {
  if (static_cast<int>(result.size()) != k) return false;
  std::vector<int> arrSet(arr.begin(), arr.end());
  for (int v : result) {
    auto it = std::find(arrSet.begin(), arrSet.end(), v);
    if (it == arrSet.end()) return false;
    arrSet.erase(it);
  }
  std::vector<int> unselected = arrSet;
  for (int s : result) {
    for (int u : unselected) {
      if (isStronger(u, s, m)) return false;
    }
  }
  return true;
}

}  // namespace

class TheKStrongestValuesInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  TheKStrongestValuesInAnArraySolution solution;
};

TEST_P(TheKStrongestValuesInAnArrayTest, Example1) {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  int k = 2;
  auto sorted = arr;
  std::sort(sorted.begin(), sorted.end());
  int m = sorted[(sorted.size() - 1) / 2];
  std::vector<int> result = solution.getStrongest(arr, k);
  EXPECT_TRUE(isValid(result, arr, k, m));
  std::sort(result.begin(), result.end());
  EXPECT_EQ(result, std::vector<int>({1, 5}));
}

TEST_P(TheKStrongestValuesInAnArrayTest, Example2) {
  std::vector<int> arr = {1, 1, 3, 5, 5};
  int k = 2;
  auto sorted = arr;
  std::sort(sorted.begin(), sorted.end());
  int m = sorted[(sorted.size() - 1) / 2];
  std::vector<int> result = solution.getStrongest(arr, k);
  EXPECT_TRUE(isValid(result, arr, k, m));
  std::sort(result.begin(), result.end());
  EXPECT_EQ(result, std::vector<int>({5, 5}));
}

TEST_P(TheKStrongestValuesInAnArrayTest, Example3) {
  std::vector<int> arr = {6, 7, 11, 7, 6, 8};
  int k = 5;
  auto sorted = arr;
  std::sort(sorted.begin(), sorted.end());
  int m = sorted[(sorted.size() - 1) / 2];
  std::vector<int> result = solution.getStrongest(arr, k);
  EXPECT_TRUE(isValid(result, arr, k, m));
}

TEST_P(TheKStrongestValuesInAnArrayTest, SelfAuthoredAllElementsSelected) {
  std::vector<int> arr = {1, 1, 2, 2};
  int k = 4;
  auto sorted = arr;
  std::sort(sorted.begin(), sorted.end());
  int m = sorted[(sorted.size() - 1) / 2];
  std::vector<int> result = solution.getStrongest(arr, k);
  EXPECT_TRUE(isValid(result, arr, k, m));
}

INSTANTIATE_TEST_SUITE_P(
    TheKStrongestValuesInAnArrayTests, TheKStrongestValuesInAnArrayTest,
    ::testing::ValuesIn(
        TheKStrongestValuesInAnArraySolution().getStrategyNames()));

}  // namespace problem_1471
}  // namespace leetcode
