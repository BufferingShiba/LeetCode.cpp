#include "leetcode/problems/maximum-product-of-three-numbers.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_628 {

class MaximumProductOfThreeNumbersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumProductOfThreeNumbersSolution solution_;
};

TEST_P(MaximumProductOfThreeNumbersTest, Example1) {
  std::vector<int> nums{1, 2, 3};
  EXPECT_EQ(6, solution_.maximumProduct(nums));
}

TEST_P(MaximumProductOfThreeNumbersTest, Example2) {
  std::vector<int> nums{1, 2, 3, 4};
  EXPECT_EQ(24, solution_.maximumProduct(nums));
}

TEST_P(MaximumProductOfThreeNumbersTest, Example3) {
  std::vector<int> nums{-1, -2, -3};
  EXPECT_EQ(-6, solution_.maximumProduct(nums));
}

TEST_P(MaximumProductOfThreeNumbersTest, SelfAuthoredMixedNegatives) {
  std::vector<int> nums{-100, -98, -1, 2, 3, 4};
  EXPECT_EQ(39200, solution_.maximumProduct(nums));
}

TEST_P(MaximumProductOfThreeNumbersTest, SelfAuthoredTwoNegativesMaxProduct) {
  std::vector<int> nums{-100, -1, 1, 2, 3};
  EXPECT_EQ(300, solution_.maximumProduct(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumProductOfThreeNumbersTestSuite,
    MaximumProductOfThreeNumbersTest,
    ::testing::ValuesIn(
        MaximumProductOfThreeNumbersSolution().getStrategyNames()));

}  // namespace problem_628
}  // namespace leetcode
