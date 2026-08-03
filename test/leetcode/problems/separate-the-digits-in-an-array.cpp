#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/separate-the-digits-in-an-array.h"

namespace leetcode {
namespace problem_2553 {

class SeparateTheDigitsInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  SeparateTheDigitsInAnArraySolution solution;
};

TEST_P(SeparateTheDigitsInAnArrayTest, Example1) {
  std::vector<int> nums = {13, 25, 83, 77};
  std::vector<int> expected = {1, 3, 2, 5, 8, 3, 7, 7};
  EXPECT_EQ(solution.separateDigits(nums), expected);
}

TEST_P(SeparateTheDigitsInAnArrayTest, Example2) {
  std::vector<int> nums = {7, 1, 3, 9};
  std::vector<int> expected = {7, 1, 3, 9};
  EXPECT_EQ(solution.separateDigits(nums), expected);
}

TEST_P(SeparateTheDigitsInAnArrayTest, SelfAuthoredMultipleDigits) {
  std::vector<int> nums = {10921, 5};
  std::vector<int> expected = {1, 0, 9, 2, 1, 5};
  EXPECT_EQ(solution.separateDigits(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    SeparateTheDigitsInAnArrayTestSuite, SeparateTheDigitsInAnArrayTest,
    ::testing::ValuesIn(SeparateTheDigitsInAnArraySolution().getStrategyNames()));

}  // namespace problem_2553
}  // namespace leetcode
