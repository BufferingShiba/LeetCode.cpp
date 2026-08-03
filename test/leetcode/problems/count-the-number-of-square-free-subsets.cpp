#include <gtest/gtest.h>
#include "leetcode/problems/count-the-number-of-square-free-subsets.h"
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2572 {

class CountTheNumberOfSquareFreeSubsetsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountTheNumberOfSquareFreeSubsetsSolution solution;
};

TEST_P(CountTheNumberOfSquareFreeSubsetsTest, Example1) {
  std::vector<int> nums = {3, 4, 4, 5};
  EXPECT_EQ(3, solution.squareFreeSubsets(nums));
}

TEST_P(CountTheNumberOfSquareFreeSubsetsTest, Example2) {
  std::vector<int> nums = {1};
  EXPECT_EQ(1, solution.squareFreeSubsets(nums));
}

TEST_P(CountTheNumberOfSquareFreeSubsetsTest, SelfAuthoredMultipleOnes) {
  std::vector<int> nums = {1, 1};
  EXPECT_EQ(3, solution.squareFreeSubsets(nums));
}

TEST_P(CountTheNumberOfSquareFreeSubsetsTest, SelfAuthoredTwoPrimesProductSquareFree) {
  std::vector<int> nums = {2, 3};
  EXPECT_EQ(3, solution.squareFreeSubsets(nums));
}

TEST_P(CountTheNumberOfSquareFreeSubsetsTest, SelfAuthoredRepeatedSamePrime) {
  // nums = {2, 2}: product 4 is not square-free, so only singletons count.
  std::vector<int> nums = {2, 2};
  EXPECT_EQ(2, solution.squareFreeSubsets(nums));
}

INSTANTIATE_TEST_SUITE_P(
    CountTheNumberOfSquareFreeSubsetsTestSuite,
    CountTheNumberOfSquareFreeSubsetsTest,
    ::testing::ValuesIn(
        CountTheNumberOfSquareFreeSubsetsSolution().getStrategyNames()));

}  // namespace problem_2572
}  // namespace leetcode
