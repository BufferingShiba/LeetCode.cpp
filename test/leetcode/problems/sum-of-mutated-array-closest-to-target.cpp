#include "leetcode/problems/sum-of-mutated-array-closest-to-target.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1300 {
namespace {

using SumOfMutatedArrayClosestToTargetTestParam = std::string;

}  // namespace

class SumOfMutatedArrayClosestToTargetTest
    : public ::testing::TestWithParam<SumOfMutatedArrayClosestToTargetTestParam> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  SumOfMutatedArrayClosestToTargetSolution solution_;
};

TEST_P(SumOfMutatedArrayClosestToTargetTest, Example1) {
  std::vector<int> arr = {4, 9, 3};
  int target = 10;
  EXPECT_EQ(3, solution_.findBestValue(arr, target));
}

TEST_P(SumOfMutatedArrayClosestToTargetTest, Example2) {
  std::vector<int> arr = {2, 3, 5};
  int target = 10;
  EXPECT_EQ(5, solution_.findBestValue(arr, target));
}

TEST_P(SumOfMutatedArrayClosestToTargetTest, Example3) {
  std::vector<int> arr = {60864, 25176, 27249, 21296, 20204};
  int target = 56803;
  EXPECT_EQ(11361, solution_.findBestValue(arr, target));
}

TEST_P(SumOfMutatedArrayClosestToTargetTest, SingleElement) {
  std::vector<int> arr = {5};
  int target = 3;
  // value=3 -> sum=3, diff=0
  EXPECT_EQ(3, solution_.findBestValue(arr, target));
}

TEST_P(SumOfMutatedArrayClosestToTargetTest, TiePickMinimum) {
  std::vector<int> arr = {3, 5, 6};
  int target = 12;
  // value=4 -> [3,4,4] sum=11 (diff 1)
  // value=5 -> [3,5,5] sum=13 (diff 1)
  // tie => choose minimum value 4
  EXPECT_EQ(4, solution_.findBestValue(arr, target));
}

INSTANTIATE_TEST_SUITE_P(
    SumOfMutatedArrayClosestToTargetTestSuite,
    SumOfMutatedArrayClosestToTargetTest,
    ::testing::ValuesIn(
        SumOfMutatedArrayClosestToTargetSolution().getStrategyNames()));

}  // namespace problem_1300
}  // namespace leetcode
