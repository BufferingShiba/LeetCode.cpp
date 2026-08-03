#include <gtest/gtest.h>

#include "leetcode/problems/maximum-product-of-three-elements-after-one-replacement.h"

namespace leetcode {
namespace problem_3732 {

class MaximumProductOfThreeElementsAfterOneReplacementTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  MaximumProductOfThreeElementsAfterOneReplacementSolution solution_;
};

TEST_P(MaximumProductOfThreeElementsAfterOneReplacementTest, Example1) {
  std::vector<int> nums = {-5, 7, 0};
  EXPECT_EQ(3500000LL, solution_.maxProduct(nums));
}

TEST_P(MaximumProductOfThreeElementsAfterOneReplacementTest, Example2) {
  std::vector<int> nums = {-4, -2, -1, -3};
  EXPECT_EQ(1200000LL, solution_.maxProduct(nums));
}

TEST_P(MaximumProductOfThreeElementsAfterOneReplacementTest, Example3) {
  std::vector<int> nums = {0, 10, 0};
  EXPECT_EQ(0LL, solution_.maxProduct(nums));
}

TEST_P(MaximumProductOfThreeElementsAfterOneReplacementTest, SelfAuthoredAllPositive) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  // Replace the smallest (1) with 1e5 inside triple: 1e5*4*5=2e6;
  // or outside triple: 3*4*5=60. Max = 2000000.
  EXPECT_EQ(2000000LL, solution_.maxProduct(nums));
}

TEST_P(MaximumProductOfThreeElementsAfterOneReplacementTest, SelfAuthoredMixedSigns) {
  std::vector<int> nums = {-3, 2, 10, 9};
  // top-two abs = 10,9 -> 1e5*10*9=9000000. Or triple outside repl:
  // 10*9*2=180, or (-3)*10*9=-270. Max = 9000000.
  EXPECT_EQ(9000000LL, solution_.maxProduct(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumProductOfThreeElementsAfterOneReplacementTestSuite,
    MaximumProductOfThreeElementsAfterOneReplacementTest,
    ::testing::ValuesIn(
        MaximumProductOfThreeElementsAfterOneReplacementSolution().getStrategyNames()));

}  // namespace problem_3732
}  // namespace leetcode
