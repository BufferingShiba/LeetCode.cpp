#include <gtest/gtest.h>

#include "leetcode/problems/replace-non-coprime-numbers-in-array.h"

namespace leetcode::problem_2197 {

class ReplaceNonCoprimeNumbersInArrayTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ReplaceNonCoprimeNumbersInArraySolution solution;
};

TEST_P(ReplaceNonCoprimeNumbersInArrayTest, Example1) {
  std::vector<int> nums = {6, 4, 3, 2, 7, 6, 2};
  std::vector<int> expected = {12, 7, 6};
  EXPECT_EQ(solution.replaceNonCoprimes(nums), expected);
}

TEST_P(ReplaceNonCoprimeNumbersInArrayTest, Example2) {
  std::vector<int> nums = {2, 2, 1, 1, 3, 3, 3};
  std::vector<int> expected = {2, 1, 1, 3};
  EXPECT_EQ(solution.replaceNonCoprimes(nums), expected);
}

TEST_P(ReplaceNonCoprimeNumbersInArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  std::vector<int> expected = {5};
  EXPECT_EQ(solution.replaceNonCoprimes(nums), expected);
}

TEST_P(ReplaceNonCoprimeNumbersInArrayTest, SelfAuthoredAllCoprime) {
  std::vector<int> nums = {2, 3, 5, 7, 11};
  std::vector<int> expected = {2, 3, 5, 7, 11};
  EXPECT_EQ(solution.replaceNonCoprimes(nums), expected);
}

TEST_P(ReplaceNonCoprimeNumbersInArrayTest, SelfAuthoredAllSame) {
  std::vector<int> nums = {4, 4, 4, 4};
  std::vector<int> expected = {4};
  EXPECT_EQ(solution.replaceNonCoprimes(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ReplaceNonCoprimeNumbersInArrayTest,
    testing::ValuesIn(
        ReplaceNonCoprimeNumbersInArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_2197
