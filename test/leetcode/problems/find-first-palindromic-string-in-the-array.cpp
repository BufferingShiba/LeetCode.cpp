#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-first-palindromic-string-in-the-array.h"

namespace leetcode {
namespace problem_2108 {

class FindFirstPalindromicStringInTheArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  FindFirstPalindromicStringInTheArraySolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(FindFirstPalindromicStringInTheArrayTest, Example1) {
  std::vector<std::string> words = {"abc", "car", "ada", "racecar", "cool"};
  EXPECT_EQ("ada", solution.firstPalindrome(words));
}

TEST_P(FindFirstPalindromicStringInTheArrayTest, Example2) {
  std::vector<std::string> words = {"notapalindrome", "racecar"};
  EXPECT_EQ("racecar", solution.firstPalindrome(words));
}

TEST_P(FindFirstPalindromicStringInTheArrayTest, Example3) {
  std::vector<std::string> words = {"def", "ghi"};
  EXPECT_EQ("", solution.firstPalindrome(words));
}

TEST_P(FindFirstPalindromicStringInTheArrayTest, SelfAuthoredSingleCharacter) {
  std::vector<std::string> words = {"a", "bc", "cd"};
  EXPECT_EQ("a", solution.firstPalindrome(words));
}

TEST_P(FindFirstPalindromicStringInTheArrayTest, SelfAuthoredSingleWordPalindrome) {
  std::vector<std::string> words = {"abba"};
  EXPECT_EQ("abba", solution.firstPalindrome(words));
}

INSTANTIATE_TEST_SUITE_P(
    FindFirstPalindromicStringInTheArrayTests,
    FindFirstPalindromicStringInTheArrayTest,
    ::testing::ValuesIn(FindFirstPalindromicStringInTheArraySolution().getStrategyNames()));

}  // namespace problem_2108
}  // namespace leetcode
