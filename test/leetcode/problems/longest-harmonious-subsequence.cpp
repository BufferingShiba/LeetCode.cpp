#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/longest-harmonious-subsequence.h"

namespace leetcode {
namespace problem_594 {

class LongestHarmoniousSubsequenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  LongestHarmoniousSubsequenceSolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(LongestHarmoniousSubsequenceTest, Example1) {
  std::vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
  EXPECT_EQ(solution.findLHS(nums), 5);
}

TEST_P(LongestHarmoniousSubsequenceTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(solution.findLHS(nums), 2);
}

TEST_P(LongestHarmoniousSubsequenceTest, Example3) {
  std::vector<int> nums = {1, 1, 1, 1};
  EXPECT_EQ(solution.findLHS(nums), 0);
}

TEST_P(LongestHarmoniousSubsequenceTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  EXPECT_EQ(solution.findLHS(nums), 0);
}

TEST_P(LongestHarmoniousSubsequenceTest, SelfAuthoredPairOnly) {
  std::vector<int> nums = {10, 11, 10, 11, 10};
  EXPECT_EQ(solution.findLHS(nums), 5);
}

TEST_P(LongestHarmoniousSubsequenceTest, SelfAuthoredNegativeValues) {
  std::vector<int> nums = {-3, -2, -2, 0};
  EXPECT_EQ(solution.findLHS(nums), 3);
}

INSTANTIATE_TEST_SUITE_P(
    LongestHarmoniousSubsequenceTests,
    LongestHarmoniousSubsequenceTest,
    ::testing::ValuesIn(LongestHarmoniousSubsequenceSolution().getStrategyNames()));

}  // namespace problem_594
}  // namespace leetcode
