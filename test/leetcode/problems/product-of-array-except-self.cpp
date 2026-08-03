#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/product-of-array-except-self.h"

namespace leetcode::problem_238 {

class ProductOfArrayExceptSelfTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ProductOfArrayExceptSelfSolution solution;
};

TEST_P(ProductOfArrayExceptSelfTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4};
  std::vector<int> expected = {24, 12, 8, 6};
  EXPECT_EQ(solution.productExceptSelf(nums), expected);
}

TEST_P(ProductOfArrayExceptSelfTest, Example2) {
  std::vector<int> nums = {-1, 1, 0, -3, 3};
  std::vector<int> expected = {0, 0, 9, 0, 0};
  EXPECT_EQ(solution.productExceptSelf(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ProductOfArrayExceptSelfTest,
    testing::ValuesIn(ProductOfArrayExceptSelfSolution().getStrategyNames()));

}  // namespace leetcode::problem_238
