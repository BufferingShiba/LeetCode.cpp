#include <gtest/gtest.h>
#include "leetcode/problems/kth-missing-positive-number.h"

using namespace leetcode::problem_1539;

class KthMissingPositiveNumberTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
  KthMissingPositiveNumberSolution solution;
};

TEST_P(KthMissingPositiveNumberTest, Example1) {
  std::vector<int> arr = {2, 3, 4, 7, 11};
  int k = 5;
  EXPECT_EQ(solution.findKthPositive(arr, k), 9);
}

TEST_P(KthMissingPositiveNumberTest, Example2) {
  std::vector<int> arr = {1, 2, 3, 4};
  int k = 2;
  EXPECT_EQ(solution.findKthPositive(arr, k), 6);
}

TEST_P(KthMissingPositiveNumberTest, SelfAuthoredAllPresentFromOne) {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  int k = 3;
  // 缺失: 6,7,8,...; 第3个 = 8
  EXPECT_EQ(solution.findKthPositive(arr, k), 8);
}

TEST_P(KthMissingPositiveNumberTest, SelfAuthoredMissingFromStart) {
  std::vector<int> arr = {5, 6, 7};
  int k = 4;
  // 缺失: 1,2,3,4,8,...; 第4个 = 4
  EXPECT_EQ(solution.findKthPositive(arr, k), 4);
}

TEST_P(KthMissingPositiveNumberTest, SelfAuthoredKEqualsOne) {
  std::vector<int> arr = {2, 4, 6};
  int k = 1;
  // 缺失: 1,3,5,7,...; 第1个 = 1
  EXPECT_EQ(solution.findKthPositive(arr, k), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    KthMissingPositiveNumberTest,
    testing::ValuesIn(KthMissingPositiveNumberSolution().getStrategyNames()));
