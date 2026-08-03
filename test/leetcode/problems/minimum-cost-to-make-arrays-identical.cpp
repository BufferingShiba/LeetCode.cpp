#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-cost-to-make-arrays-identical.h"

namespace leetcode {
namespace problem_3424 {

class MinimumCostToMakeArraysIdenticalTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumCostToMakeArraysIdenticalSolution solution;
};

TEST_P(MinimumCostToMakeArraysIdenticalTest, Example1) {
  std::vector<int> arr = {-7, 9, 5};
  std::vector<int> brr = {7, -2, -5};
  long long k = 2;
  EXPECT_EQ(13, solution.minCost(arr, brr, k));
}

TEST_P(MinimumCostToMakeArraysIdenticalTest, Example2) {
  std::vector<int> arr = {2, 1};
  std::vector<int> brr = {2, 1};
  long long k = 0;
  EXPECT_EQ(0, solution.minCost(arr, brr, k));
}

TEST_P(MinimumCostToMakeArraysIdenticalTest, SplitNeverWorth) {
  // Without split: |1-1|+|2-3| = 1. With split: sorted match |1-1|+|2-3|=1 plus k.
  // min(1, 1+100) = 1.
  std::vector<int> arr = {1, 2};
  std::vector<int> brr = {1, 3};
  long long k = 100;
  EXPECT_EQ(1, solution.minCost(arr, brr, k));
}

TEST_P(MinimumCostToMakeArraysIdenticalTest, SplitWorthWithZeroK) {
  // Without split: |3-1|+|1-3| = 4. With split (k=0 free): reorder to sorted
  // [1,3], which exactly matches, cost 0.
  std::vector<int> arr = {3, 1};
  std::vector<int> brr = {1, 3};
  long long k = 0;
  EXPECT_EQ(0, solution.minCost(arr, brr, k));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCostToMakeArraysIdenticalTestSuite,
    MinimumCostToMakeArraysIdenticalTest,
    ::testing::ValuesIn(MinimumCostToMakeArraysIdenticalSolution().getStrategyNames()));

}  // namespace problem_3424
}  // namespace leetcode
