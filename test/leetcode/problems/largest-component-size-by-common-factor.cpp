#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/largest-component-size-by-common-factor.h"

namespace leetcode {
namespace problem_952 {
namespace {

class LargestComponentSizeByCommonFactorTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LargestComponentSizeByCommonFactorSolution solution;
};

TEST_P(LargestComponentSizeByCommonFactorTest, Example1) {
  std::vector<int> nums = {4, 6, 15, 35};
  EXPECT_EQ(4, solution.largestComponentSize(nums));
}

TEST_P(LargestComponentSizeByCommonFactorTest, Example2) {
  std::vector<int> nums = {20, 50, 9, 63};
  EXPECT_EQ(2, solution.largestComponentSize(nums));
}

TEST_P(LargestComponentSizeByCommonFactorTest, Example3) {
  std::vector<int> nums = {2, 3, 6, 7, 4, 12, 21, 39};
  EXPECT_EQ(8, solution.largestComponentSize(nums));
}

TEST_P(LargestComponentSizeByCommonFactorTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {1};
  EXPECT_EQ(1, solution.largestComponentSize(nums));
}

TEST_P(LargestComponentSizeByCommonFactorTest, SelfAuthoredAllPrimes) {
  std::vector<int> nums = {2, 3, 5, 7, 11};
  EXPECT_EQ(1, solution.largestComponentSize(nums));
}

TEST_P(LargestComponentSizeByCommonFactorTest, SelfAuthoredTwoChainPrimes) {
  // 2 - 10 - 15 - 21 ... but here: 6 and 10 share 2; 15 shares 5 with 10.
  std::vector<int> nums = {6, 10, 15, 21};
  // 6(2,3) 10(2,5) -> connected; 10 & 15 share 5 -> connected; 15 & 21 share 3
  // -> connected. All 4 connected.
  EXPECT_EQ(4, solution.largestComponentSize(nums));
}

INSTANTIATE_TEST_SUITE_P(
    LargestComponentSizeByCommonFactorTestParams,
    LargestComponentSizeByCommonFactorTest,
    ::testing::ValuesIn(
        LargestComponentSizeByCommonFactorSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_952
}  // namespace leetcode
