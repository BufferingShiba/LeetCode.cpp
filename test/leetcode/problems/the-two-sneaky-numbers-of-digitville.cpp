#include "leetcode/problems/the-two-sneaky-numbers-of-digitville.h"

#include <gtest/gtest.h>

#include <algorithm>

namespace leetcode {
namespace problem_3289 {

class TheTwoSneakyNumbersOfDigitvilleTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  TheTwoSneakyNumbersOfDigitvilleSolution solution;
};

TEST_P(TheTwoSneakyNumbersOfDigitvilleTest, Example1) {
  std::vector<int> nums = {0, 1, 1, 0};
  auto actual = solution.getSneakyNumbers(nums);
  std::sort(actual.begin(), actual.end());
  EXPECT_EQ((std::vector<int>{0, 1}), actual);
}

TEST_P(TheTwoSneakyNumbersOfDigitvilleTest, Example2) {
  std::vector<int> nums = {0, 3, 2, 1, 3, 2};
  auto actual = solution.getSneakyNumbers(nums);
  std::sort(actual.begin(), actual.end());
  EXPECT_EQ((std::vector<int>{2, 3}), actual);
}

TEST_P(TheTwoSneakyNumbersOfDigitvilleTest, Example3) {
  std::vector<int> nums = {7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2};
  auto actual = solution.getSneakyNumbers(nums);
  std::sort(actual.begin(), actual.end());
  EXPECT_EQ((std::vector<int>{4, 5}), actual);
}

INSTANTIATE_TEST_SUITE_P(
    TheTwoSneakyNumbersOfDigitvilleTestSuite,
    TheTwoSneakyNumbersOfDigitvilleTest,
    ::testing::ValuesIn(TheTwoSneakyNumbersOfDigitvilleSolution()
                             .getStrategyNames()));

}  // namespace problem_3289
}  // namespace leetcode
