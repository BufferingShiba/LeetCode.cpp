#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-product-difference-between-two-pairs.h"

namespace leetcode {
namespace problem_1913 {

using MaximumProductDifferenceBetweenTwoPairsTest =
    ::testing::TestWithParam<std::string>;

class MaximumProductDifferenceBetweenTwoPairsFixture
    : public MaximumProductDifferenceBetweenTwoPairsTest {
 protected:
  MaximumProductDifferenceBetweenTwoPairsSolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(MaximumProductDifferenceBetweenTwoPairsFixture, Example1) {
  std::vector<int> nums = {5, 6, 2, 7, 4};
  EXPECT_EQ(34, solution.maxProductDifference(nums));
}

TEST_P(MaximumProductDifferenceBetweenTwoPairsFixture, Example2) {
  std::vector<int> nums = {4, 2, 5, 9, 7, 4, 8};
  EXPECT_EQ(64, solution.maxProductDifference(nums));
}

TEST_P(MaximumProductDifferenceBetweenTwoPairsFixture, SelfAuthoredMinSize) {
  std::vector<int> nums = {4, 3, 2, 1};
  EXPECT_EQ(4 * 3 - 2 * 1, solution.maxProductDifference(nums));
}

TEST_P(MaximumProductDifferenceBetweenTwoPairsFixture, SelfAuthoredAllSame) {
  std::vector<int> nums = {7, 7, 7, 7};
  EXPECT_EQ(49 - 49, solution.maxProductDifference(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumProductDifferenceBetweenTwoPairsTests,
    MaximumProductDifferenceBetweenTwoPairsFixture,
    ::testing::ValuesIn(
        MaximumProductDifferenceBetweenTwoPairsSolution().getStrategyNames()));

}  // namespace problem_1913
}  // namespace leetcode
