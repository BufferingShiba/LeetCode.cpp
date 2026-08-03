#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/minimum-operations-to-make-binary-palindrome.h"

using namespace leetcode::problem_3766;

class MinimumOperationsToMakeBinaryPalindromeTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumOperationsToMakeBinaryPalindromeSolution solution;
};

TEST_P(MinimumOperationsToMakeBinaryPalindromeTest, Example1) {
  std::vector<int> nums = {1, 2, 4};
  std::vector<int> expected = {0, 1, 1};
  EXPECT_EQ(solution.minOperations(nums), expected);
}

TEST_P(MinimumOperationsToMakeBinaryPalindromeTest, Example2) {
  std::vector<int> nums = {6, 7, 12};
  std::vector<int> expected = {1, 0, 3};
  EXPECT_EQ(solution.minOperations(nums), expected);
}

TEST_P(MinimumOperationsToMakeBinaryPalindromeTest, SelfAuthoredSingleElementPalindrome) {
  std::vector<int> nums = {1};
  std::vector<int> expected = {0};
  EXPECT_EQ(solution.minOperations(nums), expected);
}

TEST_P(MinimumOperationsToMakeBinaryPalindromeTest, SelfAuthoredSingleElementNonPalindrome) {
  std::vector<int> nums = {2};
  std::vector<int> expected = {1};
  EXPECT_EQ(solution.minOperations(nums), expected);
}

TEST_P(MinimumOperationsToMakeBinaryPalindromeTest, SelfAuthoredAllPalindromes) {
  std::vector<int> nums = {1, 3, 5, 7, 9, 15, 17, 21, 27, 31};
  std::vector<int> expected(10, 0);
  EXPECT_EQ(solution.minOperations(nums), expected);
}

TEST_P(MinimumOperationsToMakeBinaryPalindromeTest, SelfAuthoredLargerValue) {
  std::vector<int> nums = {5000};
  std::vector<int> result = solution.minOperations(nums);
  // 5000 binary 1001110001000, nearest palindrome 4953 (1001101011001), dist 47
  EXPECT_EQ(result[0], 47);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumOperationsToMakeBinaryPalindromeTest,
    testing::ValuesIn(MinimumOperationsToMakeBinaryPalindromeSolution().getStrategyNames()));
