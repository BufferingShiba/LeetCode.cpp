#include "leetcode/problems/find-the-largest-almost-missing-integer.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3471 {
namespace {

class FindTheLargestAlmostMissingIntegerTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheLargestAlmostMissingIntegerSolution solution;
};

TEST_P(FindTheLargestAlmostMissingIntegerTest, Example1) {
  std::vector<int> nums = {3, 9, 2, 1, 7};
  std::vector<int> expected = {7};
  EXPECT_EQ(solution.largestInteger(nums, 3), 7);
}

TEST_P(FindTheLargestAlmostMissingIntegerTest, Example2) {
  std::vector<int> nums = {3, 9, 7, 2, 1, 7};
  EXPECT_EQ(solution.largestInteger(nums, 4), 3);
}

TEST_P(FindTheLargestAlmostMissingIntegerTest, Example3) {
  std::vector<int> nums = {0, 0};
  EXPECT_EQ(solution.largestInteger(nums, 1), -1);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheLargestAlmostMissingIntegerTestParams,
    FindTheLargestAlmostMissingIntegerTest,
    ::testing::ValuesIn(
        FindTheLargestAlmostMissingIntegerSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3471
}  // namespace leetcode
