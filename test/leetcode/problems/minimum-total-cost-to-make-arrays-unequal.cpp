#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-total-cost-to-make-arrays-unequal.h"

namespace leetcode {
namespace problem_2499 {
namespace {

class MinimumTotalCostToMakeArraysUnequalTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumTotalCostToMakeArraysUnequalSolution solution;
};

TEST_P(MinimumTotalCostToMakeArraysUnequalTest, Example1) {
  std::vector<int> nums1 = {1, 2, 3, 4, 5};
  std::vector<int> nums2 = {1, 2, 3, 4, 5};
  EXPECT_EQ(10, solution.getSolution()(nums1, nums2));
}

TEST_P(MinimumTotalCostToMakeArraysUnequalTest, Example2) {
  std::vector<int> nums1 = {2, 2, 2, 1, 3};
  std::vector<int> nums2 = {1, 2, 2, 3, 3};
  EXPECT_EQ(10, solution.getSolution()(nums1, nums2));
}

TEST_P(MinimumTotalCostToMakeArraysUnequalTest, Example3) {
  std::vector<int> nums1 = {1, 2, 2};
  std::vector<int> nums2 = {1, 2, 2};
  EXPECT_EQ(-1, solution.getSolution()(nums1, nums2));
}

TEST_P(MinimumTotalCostToMakeArraysUnequalTest, AlreadyUnequal) {
  std::vector<int> nums1 = {1, 2, 3};
  std::vector<int> nums2 = {3, 1, 2};
  EXPECT_EQ(0, solution.getSolution()(nums1, nums2));
}


// LeetCode 失败用例: WrongAnswerCase1
TEST_P(MinimumTotalCostToMakeArraysUnequalTest, WrongAnswerCase1) {
  std::vector<int> nums1 = {1, 2, 2};
    std::vector<int> nums2 = {2, 1, 2};
    EXPECT_EQ(-1, solution.getSolution()(nums1, nums2));
}
INSTANTIATE_TEST_SUITE_P(
    MinimumTotalCostToMakeArraysUnequalTestInstance,
    MinimumTotalCostToMakeArraysUnequalTest,
    ::testing::ValuesIn(
        MinimumTotalCostToMakeArraysUnequalSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2499
}  // namespace leetcode
