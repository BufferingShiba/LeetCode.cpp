#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/maximum-subarray-with-equal-products.h"

namespace leetcode {
namespace problem_3411 {

class MaximumSubarrayWithEqualProductsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  MaximumSubarrayWithEqualProductsSolution solution;
};

TEST_P(MaximumSubarrayWithEqualProductsTest, Example1) {
  std::vector<int> nums{1, 2, 1, 2, 1, 1, 1};
  EXPECT_EQ(5, solution.maxLength(nums));
}

TEST_P(MaximumSubarrayWithEqualProductsTest, Example2) {
  std::vector<int> nums{2, 3, 4, 5, 6};
  EXPECT_EQ(3, solution.maxLength(nums));
}

TEST_P(MaximumSubarrayWithEqualProductsTest, Example3) {
  std::vector<int> nums{1, 2, 3, 1, 4, 5, 1};
  EXPECT_EQ(5, solution.maxLength(nums));
}

TEST_P(MaximumSubarrayWithEqualProductsTest, AllOnes) {
  std::vector<int> nums{1, 1, 1, 1};
  EXPECT_EQ(4, solution.maxLength(nums));
}

TEST_P(MaximumSubarrayWithEqualProductsTest, TwoTwos) {
  std::vector<int> nums{2, 2};
  // [2,2]: prod=4, lcm=2, gcd=2 => 4==4 valid, length 2
  EXPECT_EQ(2, solution.maxLength(nums));
}

TEST_P(MaximumSubarrayWithEqualProductsTest, LargeProductDoesNotOverflow) {
  std::vector<int> nums(100, 10);
  EXPECT_EQ(2, solution.maxLength(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumSubarrayWithEqualProductsTestSuite,
    MaximumSubarrayWithEqualProductsTest,
    ::testing::ValuesIn(
        MaximumSubarrayWithEqualProductsSolution().getStrategyNames()));

}  // namespace problem_3411
}  // namespace leetcode
