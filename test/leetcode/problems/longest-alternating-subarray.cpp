#include <gtest/gtest.h>
#include "leetcode/problems/longest-alternating-subarray.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2765 {

class LongestAlternatingSubarrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  LongestAlternatingSubarraySolution solution;
};

TEST_P(LongestAlternatingSubarrayTest, Example1) {
  std::vector<int> nums{2, 3, 4, 3, 4};
  EXPECT_EQ(4, solution.alternatingSubarray(nums));
}

TEST_P(LongestAlternatingSubarrayTest, Example2) {
  std::vector<int> nums{4, 5, 6};
  EXPECT_EQ(2, solution.alternatingSubarray(nums));
}

TEST_P(LongestAlternatingSubarrayTest, SelfAuthoredNoAlternating) {
  std::vector<int> nums{2, 2, 2};
  EXPECT_EQ(-1, solution.alternatingSubarray(nums));
}

TEST_P(LongestAlternatingSubarrayTest, SelfAuthoredSingleAlternatingPair) {
  std::vector<int> nums{1, 2, 1, 2, 1, 2, 3};
  EXPECT_EQ(6, solution.alternatingSubarray(nums));
}

INSTANTIATE_TEST_SUITE_P(
    LongestAlternatingSubarrayTestSuite, LongestAlternatingSubarrayTest,
    ::testing::ValuesIn(LongestAlternatingSubarraySolution().getStrategyNames()));

}  // namespace problem_2765
}  // namespace leetcode
