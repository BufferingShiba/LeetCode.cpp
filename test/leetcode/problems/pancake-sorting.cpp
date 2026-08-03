#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/pancake-sorting.h"

namespace leetcode::problem_969 {

namespace {

bool IsSorted(const std::vector<int>& arr) {
  for (size_t i = 1; i < arr.size(); ++i) {
    if (arr[i - 1] > arr[i]) return false;
  }
  return true;
}

void ApplyFlips(std::vector<int> arr, const std::vector<int>& flips,
                std::vector<int>& out) {
  for (int k : flips) {
    std::reverse(arr.begin(), arr.begin() + k);
  }
  out = arr;
}

}  // namespace

class PancakeSortingTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PancakeSortingSolution solution;
};

TEST_P(PancakeSortingTest, Example1) {
  std::vector<int> arr = {3, 2, 4, 1};
  std::vector<int> result = solution.pancakeSort(arr);
  EXPECT_LE(result.size(), static_cast<size_t>(10 * arr.size()));
  std::vector<int> sorted;
  ApplyFlips({3, 2, 4, 1}, result, sorted);
  EXPECT_TRUE(IsSorted(sorted));
}

TEST_P(PancakeSortingTest, Example2) {
  std::vector<int> arr = {1, 2, 3};
  std::vector<int> result = solution.pancakeSort(arr);
  EXPECT_TRUE(result.empty());
}

TEST_P(PancakeSortingTest, SelfAuthoredSingleElement) {
  std::vector<int> arr = {1};
  std::vector<int> result = solution.pancakeSort(arr);
  EXPECT_TRUE(result.empty());
}

TEST_P(PancakeSortingTest, SelfAuthoredReversedArray) {
  std::vector<int> arr = {4, 3, 2, 1};
  std::vector<int> result = solution.pancakeSort(arr);
  EXPECT_LE(result.size(), static_cast<size_t>(10 * arr.size()));
  std::vector<int> sorted;
  ApplyFlips({4, 3, 2, 1}, result, sorted);
  EXPECT_TRUE(IsSorted(sorted));
}

INSTANTIATE_TEST_SUITE_P(
    PancakeSortingTestSuite, PancakeSortingTest,
    testing::ValuesIn(PancakeSortingSolution().getStrategyNames()));

}  // namespace leetcode::problem_969
