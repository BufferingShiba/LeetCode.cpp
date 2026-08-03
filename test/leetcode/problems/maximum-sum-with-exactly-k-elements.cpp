#include <gtest/gtest.h>

#include "leetcode/problems/maximum-sum-with-exactly-k-elements.h"

namespace leetcode {
namespace problem_2656 {

class MaximumSumWithExactlyKElementsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MaximumSumWithExactlyKElementsSolution solution_;
};

TEST_P(MaximumSumWithExactlyKElementsTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  int k = 3;
  EXPECT_EQ(18, solution_.maximizeSum(nums, k));
}

TEST_P(MaximumSumWithExactlyKElementsTest, Example2) {
  std::vector<int> nums = {5, 5, 5};
  int k = 2;
  EXPECT_EQ(11, solution_.maximizeSum(nums, k));
}

TEST_P(MaximumSumWithExactlyKElementsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {1};
  int k = 1;
  EXPECT_EQ(1, solution_.maximizeSum(nums, k));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumSumWithExactlyKElementsTestCases,
    MaximumSumWithExactlyKElementsTest,
    ::testing::ValuesIn(MaximumSumWithExactlyKElementsSolution().getStrategyNames()));

}  // namespace problem_2656
}  // namespace leetcode
