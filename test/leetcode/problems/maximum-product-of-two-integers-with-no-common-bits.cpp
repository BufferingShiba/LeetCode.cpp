#include "leetcode/problems/maximum-product-of-two-integers-with-no-common-bits.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3670 {

class MaximumProductOfTwoIntegersWithNoCommonBitsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumProductOfTwoIntegersWithNoCommonBitsSolution solution;
};

TEST_P(MaximumProductOfTwoIntegersWithNoCommonBitsTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  EXPECT_EQ(12, solution.maxProduct(nums));
}

TEST_P(MaximumProductOfTwoIntegersWithNoCommonBitsTest, Example2) {
  std::vector<int> nums = {5, 6, 4};
  EXPECT_EQ(0, solution.maxProduct(nums));
}

TEST_P(MaximumProductOfTwoIntegersWithNoCommonBitsTest, Example3) {
  std::vector<int> nums = {64, 8, 32};
  EXPECT_EQ(2048, solution.maxProduct(nums));
}

TEST_P(MaximumProductOfTwoIntegersWithNoCommonBitsTest, OneCompatiblePair) {
  std::vector<int> nums = {8, 3, 12, 5};
  EXPECT_EQ(40, solution.maxProduct(nums));
}

TEST_P(MaximumProductOfTwoIntegersWithNoCommonBitsTest, DuplicateValuesRemainDistinct) {
  std::vector<int> nums = {7, 7, 8};
  EXPECT_EQ(56, solution.maxProduct(nums));
}

TEST_P(MaximumProductOfTwoIntegersWithNoCommonBitsTest, BacktracksFromIncompatiblePreferredBranch) {
  std::vector<int> nums = {9, 2, 19};
  EXPECT_EQ(18, solution.maxProduct(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumProductOfTwoIntegersWithNoCommonBitsTestSuite,
    MaximumProductOfTwoIntegersWithNoCommonBitsTest,
    ::testing::ValuesIn(MaximumProductOfTwoIntegersWithNoCommonBitsSolution()
                            .getStrategyNames()));

}  // namespace problem_3670
}  // namespace leetcode
