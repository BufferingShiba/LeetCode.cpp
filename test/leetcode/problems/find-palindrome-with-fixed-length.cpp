#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-palindrome-with-fixed-length.h"

namespace leetcode {
namespace problem_2217 {

class FindPalindromeWithFixedLengthTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindPalindromeWithFixedLengthSolution solution;
};

TEST_P(FindPalindromeWithFixedLengthTest, Example1) {
  std::vector<int> queries = {1, 2, 3, 4, 5, 90};
  std::vector<long long> expected = {101, 111, 121, 131, 141, 999};
  EXPECT_EQ(solution.kthPalindrome(queries, 3), expected);
}

TEST_P(FindPalindromeWithFixedLengthTest, Example2) {
  std::vector<int> queries = {2, 4, 6};
  std::vector<long long> expected = {1111, 1331, 1551};
  EXPECT_EQ(solution.kthPalindrome(queries, 4), expected);
}

TEST_P(FindPalindromeWithFixedLengthTest, FirstQuery) {
  std::vector<int> queries = {1};
  std::vector<long long> expected = {101};
  EXPECT_EQ(solution.kthPalindrome(queries, 3), expected);
}

TEST_P(FindPalindromeWithFixedLengthTest, OutOfRange) {
  std::vector<int> queries = {10000, 91, 90};
  std::vector<long long> expected = {-1, -1, 9999};
  EXPECT_EQ(solution.kthPalindrome(queries, 4), expected);
}

TEST_P(FindPalindromeWithFixedLengthTest, SingleDigitLength) {
  std::vector<int> queries = {1, 2, 9};
  std::vector<long long> expected = {1, 2, 9};
  EXPECT_EQ(solution.kthPalindrome(queries, 1), expected);
}

TEST_P(FindPalindromeWithFixedLengthTest, EvenLengthSmall) {
  std::vector<int> queries = {1};
  std::vector<long long> expected = {1001};
  EXPECT_EQ(solution.kthPalindrome(queries, 4), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FindPalindromeWithFixedLengthTestSuite, FindPalindromeWithFixedLengthTest,
    ::testing::ValuesIn(FindPalindromeWithFixedLengthSolution().getStrategyNames()));

}  // namespace problem_2217
}  // namespace leetcode
