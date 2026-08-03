#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/maximum-xor-of-two-numbers-in-an-array.h"

namespace leetcode::problem_421 {

class MaximumXorOfTwoNumbersInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumXorOfTwoNumbersInAnArraySolution solution_;
};

TEST_P(MaximumXorOfTwoNumbersInAnArrayTest, Example1) {
  std::vector<int> nums{3, 10, 5, 25, 2, 8};
  EXPECT_EQ(28, solution_.findMaximumXOR(nums));
}

TEST_P(MaximumXorOfTwoNumbersInAnArrayTest, Example2) {
  std::vector<int> nums{14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
  EXPECT_EQ(127, solution_.findMaximumXOR(nums));
}

TEST_P(MaximumXorOfTwoNumbersInAnArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{5};
  EXPECT_EQ(0, solution_.findMaximumXOR(nums));
}

TEST_P(MaximumXorOfTwoNumbersInAnArrayTest, SelfAuthoredTwoElements) {
  std::vector<int> nums{8, 10};
  EXPECT_EQ(2, solution_.findMaximumXOR(nums));
}

TEST_P(MaximumXorOfTwoNumbersInAnArrayTest, SelfAuthoredIdenticalElements) {
  std::vector<int> nums{42, 42, 42};
  EXPECT_EQ(0, solution_.findMaximumXOR(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumXorOfTwoNumbersInAnArrayTests,
    MaximumXorOfTwoNumbersInAnArrayTest,
    ::testing::ValuesIn(
        MaximumXorOfTwoNumbersInAnArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_421
