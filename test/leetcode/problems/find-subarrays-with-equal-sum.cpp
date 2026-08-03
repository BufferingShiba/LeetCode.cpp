#include <gtest/gtest.h>

#include "leetcode/problems/find-subarrays-with-equal-sum.h"

#include <string>
#include <vector>

namespace leetcode::problem_2395 {

class FindSubarraysWithEqualSumTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindSubarraysWithEqualSumSolution solution;
};

TEST_P(FindSubarraysWithEqualSumTest, Example1) {
  std::vector<int> nums{4, 2, 4};
  EXPECT_TRUE(solution.findSubarrays(nums));
}

TEST_P(FindSubarraysWithEqualSumTest, Example2) {
  std::vector<int> nums{1, 2, 3, 4, 5};
  EXPECT_FALSE(solution.findSubarrays(nums));
}

TEST_P(FindSubarraysWithEqualSumTest, Example3) {
  std::vector<int> nums{0, 0, 0};
  EXPECT_TRUE(solution.findSubarrays(nums));
}

TEST_P(FindSubarraysWithEqualSumTest, SelfAuthored_MinLengthDistinctSums) {
  std::vector<int> nums{1, 4, 2};
  // subarray sums: (1+4)=5, (4+2)=6 -> distinct
  EXPECT_FALSE(solution.findSubarrays(nums));
}

TEST_P(FindSubarraysWithEqualSumTest, SelfAuthored_NegativeValuesDuplicate) {
  std::vector<int> nums{-1, 2, 3};
  // subarray sums: 1, 5 -> distinct
  EXPECT_FALSE(solution.findSubarrays(nums));
}

INSTANTIATE_TEST_SUITE_P(
    FindSubarraysWithEqualSumStrategies, FindSubarraysWithEqualSumTest,
    ::testing::ValuesIn(FindSubarraysWithEqualSumSolution().getStrategyNames()));

}  // namespace leetcode::problem_2395
