#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/letter-case-permutation.h"

namespace leetcode::problem_784 {

class LetterCasePermutationTest
    : public testing::TestWithParam<std::string> {
 public:
  void SetUp() override { solution.setStrategy(GetParam()); }

 protected:
  LetterCasePermutationSolution solution;
};

TEST_P(LetterCasePermutationTest, Example1) {
  auto result = solution.letterCasePermutation("a1b2");
  std::vector<std::string> expected = {"a1b2", "a1B2", "A1b2", "A1B2"};
  EXPECT_EQ(result.size(), expected.size());

  std::vector<std::string> sortedResult(result);
  std::vector<std::string> sortedExpected(expected);
  std::sort(sortedResult.begin(), sortedResult.end());
  std::sort(sortedExpected.begin(), sortedExpected.end());
  EXPECT_EQ(sortedResult, sortedExpected);
}

TEST_P(LetterCasePermutationTest, Example2) {
  auto result = solution.letterCasePermutation("3z4");
  std::vector<std::string> expected = {"3z4", "3Z4"};
  EXPECT_EQ(result.size(), expected.size());

  std::vector<std::string> sortedResult(result);
  std::vector<std::string> sortedExpected(expected);
  std::sort(sortedResult.begin(), sortedResult.end());
  std::sort(sortedExpected.begin(), sortedExpected.end());
  EXPECT_EQ(sortedResult, sortedExpected);
}

TEST_P(LetterCasePermutationTest, SelfAuthoredOnlyDigits) {
  auto result = solution.letterCasePermutation("12345");
  std::vector<std::string> expected = {"12345"};
  EXPECT_EQ(result, expected);
}

TEST_P(LetterCasePermutationTest, SelfAuthoredSingleLetter) {
  auto result = solution.letterCasePermutation("a");
  std::vector<std::string> expected = {"a", "A"};

  std::vector<std::string> sortedResult(result);
  std::vector<std::string> sortedExpected(expected);
  std::sort(sortedResult.begin(), sortedResult.end());
  std::sort(sortedExpected.begin(), sortedExpected.end());
  EXPECT_EQ(sortedResult, sortedExpected);
}

INSTANTIATE_TEST_SUITE_P(
    LetterCasePermutationTests, LetterCasePermutationTest,
    testing::ValuesIn(
        LetterCasePermutationSolution().getStrategyNames()));

}  // namespace leetcode::problem_784
