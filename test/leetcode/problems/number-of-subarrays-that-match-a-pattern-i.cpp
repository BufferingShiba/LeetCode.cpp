#include "leetcode/problems/number-of-subarrays-that-match-a-pattern-i.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3034 {
namespace {

using NumberOfSubarraysThatMatchAPatternI = NumberOfSubarraysThatMatchAPatternISolution;

}  // namespace

class NumberOfSubarraysThatMatchAPatternITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfSubarraysThatMatchAPatternISolution solution;
};

TEST_P(NumberOfSubarraysThatMatchAPatternITest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4, 5, 6};
  std::vector<int> pattern = {1, 1};
  EXPECT_EQ(4, solution.countMatchingSubarrays(nums, pattern));
}

TEST_P(NumberOfSubarraysThatMatchAPatternITest, Example2) {
  std::vector<int> nums = {1, 4, 4, 1, 3, 5, 5, 3};
  std::vector<int> pattern = {1, 0, -1};
  EXPECT_EQ(2, solution.countMatchingSubarrays(nums, pattern));
}

TEST_P(NumberOfSubarraysThatMatchAPatternITest, SelfAuthoredAllEqual) {
  std::vector<int> nums = {5, 5, 5, 5};
  std::vector<int> pattern = {0};
  EXPECT_EQ(3, solution.countMatchingSubarrays(nums, pattern));
}

TEST_P(NumberOfSubarraysThatMatchAPatternITest, SelfAuthoredNoMatch) {
  std::vector<int> nums = {1, 2, 3};
  std::vector<int> pattern = {-1};
  EXPECT_EQ(0, solution.countMatchingSubarrays(nums, pattern));
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfSubarraysThatMatchAPatternITests,
    NumberOfSubarraysThatMatchAPatternITest,
    ::testing::ValuesIn(
        NumberOfSubarraysThatMatchAPatternISolution().getStrategyNames()));

}  // namespace problem_3034
}  // namespace leetcode
