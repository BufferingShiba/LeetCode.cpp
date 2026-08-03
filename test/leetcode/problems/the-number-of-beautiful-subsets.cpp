#include "leetcode/problems/the-number-of-beautiful-subsets.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_2597 {

class TheNumberOfBeautifulSubsetsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  TheNumberOfBeautifulSubsetsSolution solution_;
};

TEST_P(TheNumberOfBeautifulSubsetsTest, Example1) {
  std::vector<int> nums = {2, 4, 6};
  int k = 2;
  EXPECT_EQ(4, solution_.beautifulSubsets(nums, k));
}

TEST_P(TheNumberOfBeautifulSubsetsTest, Example2) {
  std::vector<int> nums = {1};
  int k = 1;
  EXPECT_EQ(1, solution_.beautifulSubsets(nums, k));
}

TEST_P(TheNumberOfBeautifulSubsetsTest, SelfAuthoredDuplicateValues) {
  std::vector<int> nums = {1, 1, 1};
  int k = 1;
  // Values are identical, no two differ by exactly k -> all 2^3-1=7 subsets.
  EXPECT_EQ(7, solution_.beautifulSubsets(nums, k));
}

TEST_P(TheNumberOfBeautifulSubsetsTest, SelfAuthoredAllConflicting) {
  std::vector<int> nums = {1, 2, 3};
  int k = 1;
  // Pairs (1,2) and (2,3) are excluded. Valid subsets:
  // singletons {1},{2},{3}, and {1,3} -> 4.
  EXPECT_EQ(4, solution_.beautifulSubsets(nums, k));
}

INSTANTIATE_TEST_SUITE_P(
    TheNumberOfBeautifulSubsetsTestSuite, TheNumberOfBeautifulSubsetsTest,
    ::testing::ValuesIn(TheNumberOfBeautifulSubsetsSolution().getStrategyNames()));

}  // namespace problem_2597
}  // namespace leetcode
