#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/sum-of-good-numbers.h"

namespace leetcode::problem_3452 {

class SumOfGoodNumbersTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  SumOfGoodNumbersSolution solution;
};

TEST_P(SumOfGoodNumbersTest, Example1) {
  std::vector<int> nums = {1, 3, 2, 1, 5, 4};
  int k = 2;
  EXPECT_EQ(12, solution.sumOfGoodNumbers(nums, k));
}

TEST_P(SumOfGoodNumbersTest, Example2) {
  std::vector<int> nums = {2, 1};
  int k = 1;
  EXPECT_EQ(2, solution.sumOfGoodNumbers(nums, k));
}

TEST_P(SumOfGoodNumbersTest, SelfAuthoredEqualValues) {
  std::vector<int> nums = {5, 5, 5};
  int k = 1;
  // No element is strictly greater than both neighbors, so none is good.
  EXPECT_EQ(0, solution.sumOfGoodNumbers(nums, k));
}

TEST_P(SumOfGoodNumbersTest, SelfAuthoredFrontElement) {
  std::vector<int> nums = {10, 1, 2};
  int k = 1;
  // nums[0]=10 > nums[1], good. nums[1]=1 not >10. nums[2]=2 > nums[1]=1, good.
  EXPECT_EQ(12, solution.sumOfGoodNumbers(nums, k));
}

INSTANTIATE_TEST_SUITE_P(
    SumOfGoodNumbersParameterized,
    SumOfGoodNumbersTest,
    ::testing::ValuesIn(SumOfGoodNumbersSolution().getStrategyNames()));

}  // namespace leetcode::problem_3452
